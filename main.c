#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    srand(time(NULL));
    int nbgen=rand()%24+1;    //entre 1-24
    printf("%d\n",nbgen);
    return 0;
}
