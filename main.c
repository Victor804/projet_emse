#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "main.h"
#include "client.h"
#include "file.h"
#include "fichier.h"
#include "analyse.h"


int main(){
  srand(time(NULL)); /* Initialisation de l'aleatoire */

  Analyse analyse = {0, 0, 0, 0, 0, 0};

  for(int i = 0; i < 1; i++){
    simulation(&analyse);
  }
  afficherAnalyse(analyse);


  return 0;
}


void simulation(Analyse *analyse){
  Horaire horaireDebut = {HEURE_DEBUT, MINUTE_DEBUT, SECONDE_DEBUT};/* Initialisation des horaires de l'entreprise debut et fin */
  Horaire horaireFin = {HEURE_FIN, MINUTE_FIN, SECONDE_FIN};
  Horaire horaireServiceFin = {HEURE_SERVICE_FIN, MINUTE_SERVICE_FIN, SECONDE_SERVICE_FIN};

  //FILE* fichier;
  //fichier = fopen(FILENAME, "w");

  File *file; /* Creation de la file d'attente */
  file = initFile();


  /* Remplissage de la file d'attente pour une journee */
  Horaire horaireActuel = horaireDebut;

  Client client; /* Initialisation des clients */
  client.horaireDepart = (Horaire) {-1, -1, -1};

  horaireActuel = ajouterHoraire(horaireActuel, convertisseurMinHoraire(tempsProchainClient()));

  int nombreClient = 0;
  while(estInferieurHoraire(horaireActuel, horaireFin)){
    client.horaireArrivee = horaireActuel;
    client.dureeService = tempsServiceClient();
    ajouterFile(file, client);
    horaireActuel = ajouterHoraire(horaireActuel, convertisseurMinHoraire(tempsProchainClient()));
    nombreClient++;
  }

  /* Calcule de l'horaire de sortie */
  client = extraireFile(file);/* Initialisation avec le premier client */
  client.horaireDepart = ajouterHoraire(client.horaireArrivee, convertisseurMinHoraire(client.dureeService));

  Horaire horairePassage = client.horaireDepart;
  Horaire horaireDepart;

  afficherClient(client);printf("\n");
  //enregisterClient(fichier, client);
  int tempsReponseCum = 0;//Temps de reponse cumulee
  int nombreClientNonServis = 0;//Nombre de client non servis
  int tailleFileMax = 0;
  int tailleFile = 0;
  int nombreClientEnFileDattente = 0;
  int nombreFile = 0;
  while(!estVideFile(file)){
    client = extraireFile(file);
    if(estInferieurHoraire(horairePassage, client.horaireArrivee)){
      horaireDepart = ajouterHoraire(client.horaireArrivee, convertisseurMinHoraire(client.dureeService));
      if(tailleFile != 0){
        nombreFile++;
        tailleFile = 0;
      }
    }
    else{
      horaireDepart = ajouterHoraire(horairePassage, convertisseurMinHoraire(client.dureeService));
      tailleFile++;
      nombreClientEnFileDattente++;
    }
    if(estInferieurHoraire(horaireDepart, horaireServiceFin)){
      client.horaireDepart = horaireDepart;
      //enregisterClient(fichier, client);
      tempsReponseCum += convertisseurHoraireMin(client.horaireDepart)-client.dureeService-convertisseurHoraireMin(client.horaireArrivee);
      horairePassage = client.horaireDepart;
    }
    else{
      client.horaireDepart = (Horaire) {-1, -1, -1};
      nombreClientNonServis++;
      horairePassage = horaireServiceFin;
    }
    if(tailleFile > tailleFileMax){
      tailleFileMax = tailleFile;
    }
    afficherClient(client);printf("\n");
  }
  float moyenneTailleFile;
  if(nombreFile == 0){
    moyenneTailleFile = nombreClientEnFileDattente;
  }
  else{
    moyenneTailleFile = nombreClientEnFileDattente/nombreFile;
  }
  updateAnalyse(analyse,
                nombreClient,
                (convertisseurHoraireMin(horaireFin)-convertisseurHoraireMin(horaireDebut))/60,
                tempsReponseCum/(nombreClient-nombreClientNonServis),
                nombreClientNonServis,
                tailleFileMax,
                moyenneTailleFile);
}


double aleatoire(){
  /* Retourne une valeur entre 0 et 1 */
  return (double)rand()/(double)RAND_MAX ;
}


int tempsProchainClient(){
  /* Retourne un temps ( int ) en minute selon la loi de poisson*/
  return -log(1-aleatoire())/LAMBDA;
}


int tempsServiceClient(){
  /* Retoure un temps ( int ) en minute selon la loi uniforme*/
  return aleatoire()*(SERVICEMAX-SERVICEMIN)+SERVICEMIN;
}
