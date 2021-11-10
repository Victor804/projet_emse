#include <stdio.h>
#include <stdlib.h>
#include "client.h"
#include "file.h"

File *initFile(){
    File *file = malloc(sizeof(*file));
    file->premier = NULL;

    return file;
}


void ajouterFile(File *file, Client client){
    Element *nouveau = malloc(sizeof(*nouveau));
    if (file == NULL || nouveau == NULL){
        exit(EXIT_FAILURE);
    }

    nouveau->client = client;
    nouveau->suivant = NULL;

    if (file->premier != NULL){
        Element *elementActuel = file->premier;
        while (elementActuel->suivant != NULL){
            elementActuel = elementActuel->suivant;
        }
        elementActuel->suivant = nouveau;
    }
    else
    {
        file->premier = nouveau;
    }
}


Client extraireFile(File *file){
    if (file == NULL){
        exit(EXIT_FAILURE);
    }

    Client clientExtrait;

    if (file->premier != NULL){
        Element *client = file->premier;

        clientExtrait = client->client;
        file->premier = client->suivant;
        free(client);
    }

    return clientExtrait;
}


void afficherFile(File *file){
    if (file == NULL){
        exit(EXIT_FAILURE);
    }

    Element *element = file->premier;
    while (element != NULL){
        afficherClient(element->client);
        printf("\n");
        element = element->suivant;
    }
  }


int estVideFile(File *file){
  /* Retourne 1 si la file est vide sinon 0 */
  if(file == NULL){
    exit(EXIT_FAILURE);
  }
  
  Element *element = file->premier;
  if(element == NULL){
    return 1;
  }
  else{
    return 0;
  }
}
