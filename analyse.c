#include <stdio.h>
#include <math.h>
#include "analyse.h"



void afficherAnalyse(Analyse analyse){
  printf("Nombre simulation:%d\nMoyenne taille file:%g\nTaille max file:%g\nDebit moyen:%g Personne/h\ntemps de reponse:%f min\nClient non servis:%g\n",
          analyse.nombreSimulation,
          round(analyse.moyenneTailleFile),
          round(analyse.moyenneTailleMaxFile),
          round(analyse.debitMoyen),
          analyse.tempsReponse,
          round(analyse.nombreClientNonServis));
}


void updateAnalyse(Analyse *analyse, int nombreClient, float tempsSimulation, int tempsReponse, int nombreClientNonServis, int tailleFileMax, float moyenneTailleFile){
  analyse->nombreSimulation++;
  analyse->moyenneTailleFile = (analyse->moyenneTailleFile*(analyse->nombreSimulation-1)+moyenneTailleFile)/(analyse->nombreSimulation);
  analyse->moyenneTailleMaxFile = (analyse->moyenneTailleMaxFile*(analyse->nombreSimulation-1)+tailleFileMax)/(analyse->nombreSimulation);
  analyse->debitMoyen = (analyse->debitMoyen*(analyse->nombreSimulation-1)+(nombreClient-nombreClientNonServis)/tempsSimulation)/(analyse->nombreSimulation);
  analyse->tempsReponse = (analyse->tempsReponse*(analyse->nombreSimulation-1)+tempsReponse)/(analyse->nombreSimulation);
  analyse->nombreClientNonServis = (analyse->nombreClientNonServis*(analyse->nombreSimulation-1)+nombreClientNonServis)/(analyse->nombreSimulation);
}
