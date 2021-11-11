#include <stdio.h>
#include "horaire.h"

/* Fonctions de gestion des horaires */
void afficherHoraire(Horaire horaire){
  if(horaire.heure == -1 && horaire.min == -1 && horaire.sec == -1){
    printf("NULL");
  }
  else{
    if(horaire.heure < 10){
      printf("0%d", horaire.heure);
    }
    else {
      printf("%d", horaire.heure);
    }
    printf(":");
    if(horaire.min < 10){
      printf("0%d", horaire.min);
    }
    else{
      printf("%d", horaire.min);
    }
    printf(":");
    if(horaire.sec < 10){
      printf("0%d", horaire.sec);
    }
    else{
      printf("%d", horaire.sec);
    }
  }
}


int estInferieurHoraire(Horaire h1, Horaire h2){
  /* Renvoie 1 si h1 < h2 sinon 0 */
  if(h1.heure < h2.heure){
    return 1;
  }
  else if(h1.heure > h2.heure) {
    return 0;
  }
  else{
    if(h1.min < h2.min){
      return 1;
    }
    else if(h1.min > h2.min){
      return 0;
    }
    else{
      if(h1.sec < h2.sec){
        return 1;
      }
      else if(h1.sec > h2.sec){
        return 0;
      }
      else{
        return 0;
      }
    }
  }
}


Horaire ajouterHoraire(Horaire h1, Horaire h2){
  /* Addictionne deux horaires */
  Horaire horaire = {0, 0, 0};

  horaire.heure = h1.heure + h2.heure;
  horaire.min = h1.min + h2.min;
  horaire.sec = h1.sec + h2.sec;

  if(horaire.sec >= 60){
    horaire.min += (int)horaire.sec/60;
    horaire.sec -=((int)horaire.sec/60)*60;
  }
  if(horaire.min >= 60){
    horaire.heure += (int)horaire.min/60;
    horaire.min -= ((int)horaire.min/60)*60;
  }

  return horaire;
}


Horaire convertisseurMinHoraire(int minute){
  Horaire horaire = {0, 0, 0};

  horaire.heure+=(int)minute/60;
  horaire.min = minute-horaire.heure*60;

  return horaire;
}


int convertisseurHoraireMin(Horaire horaire){
  return horaire.heure*60 + horaire.min;
}
