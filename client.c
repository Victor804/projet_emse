#include <stdio.h>
#include "client.h"


void afficherClient(Client client){
  printf("Client(");
  afficherHoraire(client.horaireArrivee);
  if(client.horaireDepart.heure != -1){
    printf("-->");
    printf("%d",convertisseurHoraireMin(client.horaireDepart)-client.dureeService-convertisseurHoraireMin(client.horaireArrivee));
    printf("-->");
    afficherHoraire(convertisseurMinHoraire(convertisseurHoraireMin(client.horaireDepart)-client.dureeService));
    printf("-->");
    afficherHoraire(client.horaireDepart);
  }
  printf(")");

}
