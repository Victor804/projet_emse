/* Declaration des structures */
typedef struct File File;
typedef struct Element Element;

struct File{
  Element *premier;
};

struct Element{
  Client client;
  Element *suivant;
};


/* Prototypes */
File *initFile();
void ajouterFile(File *file, Client client);
Client extraireFile(File *file);
void afficherFile(File *file);
int estVideFile(File *file);
