# SIMULATION DE LISTE D'ATTENTE
Projet de simulation de file d'attente par Victor Vaucel et Théo Thilloux

## Installation
```
$ make
$ ./prog
```

## Utilisation
Les paramètres de la simulation se trouvent dans le fichier main.h .

### Heure de début de service
```
#define HEURE_DEBUT 8
#define MINUTE_DEBUT 30
#define SECONDE_DEBUT 0
```

### Heure de fin d'arrivée des clients
```
#define HEURE_FIN 17
#define MINUTE_FIN 0
#define SECONDE_FIN 0
```

### Heure de fin de service
```
#define HEURE_SERVICE_FIN 17
#define MINUTE_SERVICE_FIN 30
#define SECONDE_SERVICE_FIN 0
```

### Fréquence d'arrivée (lambda)
```
#define LAMBDA 0.05
```

### Nombre de simulation
```
#define NBSIMULATION 1
```

### Intervalle de la durée de service pour un client (en minute)
```
#define SERVICEMIN 5
#define SERVICEMAX 25
```
