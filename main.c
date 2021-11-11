#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "main.h"
#include "client.h"
#include "file.h"
#include "fichier.h"

int main(){
  srand(time(NULL)); /* Initialisation de l'aleatoire */

  Horaire horaireDebut = {HEURE_DEBUT, MINUTE_DEBUT, SECONDE_DEBUT};/* Initialisation des horaires de l'entreprise debut et fin */
  Horaire horaireFin = {HEURE_FIN, MINUTE_FIN, SECONDE_FIN};

  FILE* fichier;
  fichier = fopen(FILENAME, "w");

  File *file; /* Creation de la file d'attente */
  file = initFile();


  /* Remplissage de la file d'attente pour une journee */
  Horaire horaireActuelle = horaireDebut;

  Client client; /* Initialisation des clients */
  client.horaireDepart = (Horaire) {-1, -1, -1};

  horaireActuelle = ajouterHoraire(horaireActuelle, convertisseurMinHoraire(tempsProchainClient()));
  while(estInferieurHoraire(horaireActuelle, horaireFin)){
    client.horaireArrivee = horaireActuelle;
    client.dureeService = tempsServiceClient();
    ajouterFile(file, client);
    horaireActuelle = ajouterHoraire(horaireActuelle, convertisseurMinHoraire(tempsProchainClient()));
  }
  afficherFile(file);

  printf("Calcule de l'horaire de sortie:\n");

  /* Calcule de l'horaire de sortie */
  client = extraireFile(file);/* Initialisation avec le premier client */
  client.horaireDepart = ajouterHoraire(client.horaireArrivee, convertisseurMinHoraire(client.dureeService));

  Horaire horairePassage = client.horaireDepart;
  afficherClient(client);printf("\n");
  enregisterClient(fichier, client);

  while(!estVideFile(file)){
    client = extraireFile(file);
    if(estInferieurHoraire(horairePassage, client.horaireArrivee)){
      client.horaireDepart = ajouterHoraire(client.horaireArrivee, convertisseurMinHoraire(client.dureeService));
    }
    else{
      client.horaireDepart = ajouterHoraire(horairePassage, convertisseurMinHoraire(client.dureeService));
    }
    afficherClient(client);printf("\n");
    enregisterClient(fichier, client);

    horairePassage = client.horaireDepart;
  }
  return 0;
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
