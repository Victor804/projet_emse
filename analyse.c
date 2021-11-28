#include <stdio.h>
#include <math.h>
#include "analyse.h"



void afficherAnalyse(Analyse analyse){
  printf("Nombre simulation:%d\nMoyenne taille file:%d\nDebit moyen:%g Personne/h\ntemps de reponse:%f\nClient non servis:%d\n",
          analyse.nombreSimulation,
          analyse.moyenneTailleFile,
          round(analyse.debitMoyen),
          analyse.tempsReponse,
          analyse.nombreClientNonServis);
}


void updateAnalyse(Analyse *analyse, int nombreClient, float tempsSimulation, int tempsReponse, int nombreClientNonServis){
  analyse->nombreSimulation++;
  analyse->moyenneTailleFile = (analyse->moyenneTailleFile*(analyse->nombreSimulation-1)+nombreClient)/(analyse->nombreSimulation);
  analyse->debitMoyen = (analyse->debitMoyen*(analyse->nombreSimulation-1)+nombreClient/tempsSimulation)/(analyse->nombreSimulation);
  analyse->tempsReponse = (analyse->tempsReponse*(analyse->nombreSimulation-1)+tempsReponse)/(analyse->nombreSimulation);
  analyse->nombreClientNonServis = (analyse->nombreClientNonServis*(analyse->nombreSimulation-1)+nombreClientNonServis)/(analyse->nombreSimulation);
}
