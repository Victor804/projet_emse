/* Structure horaire */
typedef struct{
  int heure;
  int min;
  int sec;
}Horaire;


/* Prototypes */
void afficherHoraire(Horaire horaire);
int estInferieurHoraire(Horaire h1, Horaire h2);
Horaire ajouterHoraire(Horaire h1, Horaire h2);
Horaire convertisseurMinHoraire(int minute);
int convertisseurHoraireMin(Horaire horaire);
