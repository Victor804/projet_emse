/* Structure d'analyse */
typedef struct{
  int nombreSimulation;
  float moyenneTailleFile;
  float moyenneTailleMaxFile;
  float debitMoyen;
  float tempsReponse;
  float nombreClientNonServis;
}Analyse;



/* Prototypes */
void afficherAnalyse(Analyse analyse);
void updateAnalyse(Analyse *analyse, int nombreClient, float tempsSimulation, int tempsReponse, int nombreClientNonServis, int tailleMaxFile, float moyenneTailleFile);
