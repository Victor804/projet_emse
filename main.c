#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "main.h"
#include "client.h"
#include "file.h"


int main(){
  srand(time(NULL)); /* Initialisation de l'aleatoire */
  Horaire horaireDebut = {HEURE_DEBUT, MINUTE_DEBUT, SECONDE_DEBUT};/* Initialisation des horaires de l'entreprise debut et fin */
  Horaire horaireFin = {HEURE_FIN, MINUTE_FIN, SECONDE_FIN};

  File *file; /* Creation de la file d'attente */
  file = initFile();

  /* Remplissage de la file d'attente pour une journee */
  Horaire horaireActuelle = horaireDebut;

  Client client; /* Initialisation des clients */
  client.horaireDepart = (Horaire) {-1, -1, -1};

  while(estInferieurHoraire(horaireActuelle, horaireFin)){
    client.horaireArrivee = horaireActuelle;
    client.dureeService = tempsServiceClient();
    ajouterFile(file, client);
    horaireActuelle = ajouterHoraire(horaireActuelle, convertisseurMinHoraire(tempsProchainClient()));
  }
  afficherFile(file);

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
