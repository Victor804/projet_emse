#include "horaire.h"

typedef struct {
  Horaire horaireArrivee;
  Horaire horaireDepart;
  int dureeService; /* Temps exprime en minute */
}Client;


void afficherClient(Client client);
