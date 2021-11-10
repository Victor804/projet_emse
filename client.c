#include <stdio.h>
#include "client.h"


void afficherClient(Client client){
  printf("Client(");
  afficherHoraire(client.horaireArrivee);
  printf("-->");
  afficherHoraire(client.horaireDepart);
  printf("  %d", client.dureeService);
  printf(")");
}
