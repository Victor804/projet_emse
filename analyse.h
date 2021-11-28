/* Structure d'analyse */
typedef struct{
  int nombreSimulation;
  int moyenneTailleFile;
  int moyenneTailleMaxFile;
  float debitMoyen;
  float tempsReponse;
  int nombreClientNonServis;
}Analyse;



/* Prototypes */
void afficherAnalyse(Analyse analyse);
void updateAnalyse(Analyse *analyse, int nombreClient, float tempsSimulation, int tempsReponse, int nombreClientNonServis);
