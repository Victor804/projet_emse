#include <stdio.h>
#include "client.h"
#include "fichier.h"

void enregisterClient(FILE *file, Client client){
  Horaire horairePassage = convertisseurMinHoraire(convertisseurHoraireMin(client.horaireDepart)-client.dureeService);
  if(client.horaireDepart.heure != -1){
    fprintf(file, "Client(%d:%d:%d-->%d-->%d:%d:%d-->%d:%d:%d)\n", client.horaireArrivee.heure,
                                                       client.horaireArrivee.min,
                                                       client.horaireArrivee.sec,
                                                       convertisseurHoraireMin(client.horaireDepart)-client.dureeService-convertisseurHoraireMin(client.horaireArrivee),
                                                       horairePassage.heure,
                                                       horairePassage.min,
                                                       horairePassage.sec,
                                                       client.horaireDepart.heure,
                                                       client.horaireDepart.min,
                                                       client.horaireDepart.sec);

  }
  else{
    fprintf(file, "Client(%d:%d:%d)\n", client.horaireArrivee.heure,
                                                                   client.horaireArrivee.min,
                                                                   client.horaireArrivee.sec);
  }
}
