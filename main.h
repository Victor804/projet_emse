/* Constantes */
/* Horaire de debut d'une journee */
#define HEURE_DEBUT 8
#define MINUTE_DEBUT 30
#define SECONDE_DEBUT 0

/* Horaire  de fin d'une journee */
#define HEURE_FIN 17
#define MINUTE_FIN 0
#define SECONDE_FIN 0

/* Horaire  de fin d'une journee service*/
#define HEURE_SERVICE_FIN 17
#define MINUTE_SERVICE_FIN 30
#define SECONDE_SERVICE_FIN 0


/* Parametre loi de probabilite: loi de poisson */
#define LAMBDA 0.05

/* Nombre de simulation */
#define NBSIMULATION 2

/* Parametre intervalle duree en minute du service */
#define SERVICEMIN 5
#define SERVICEMAX 25

/* Parametre fichier */
#define FILENAME "sauvegarde.txt"

/* Prototypes */
double aleatoire();
int tempsProchainClient();
int tempsServiceClient();
void simulation();
void menu();
