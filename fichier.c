#include <stdio.h>
#include "client.h"

void enregisterClient(FILE *file, Client client){
  fprintf(file, "Client(%d:%d:%d-->%d:%d:%d  %d)\n", client.horaireArrivee.heure,
                                                     client.horaireArrivee.min,
                                                     client.horaireArrivee.sec,
                                                     client.horaireDepart.heure,
                                                     client.horaireDepart.min,
                                                     client.horaireDepart.sec,
                                                     client.dureeService);
}
