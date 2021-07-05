//
//  main.c
//  
//
//  Created by Paolo Cupini on 07/04/21.
//

#include <stdlib.h>
#include <stdio.h>
#include "ricorsione.h"
int main () {
    int x=5;
    printf("%d\n",fattoriale(x));
    int y=3;
    printf("%d\n",potenza(x,y));
    printf("%d\n",binomiale(x,y));
    FILE *f=fopen("bella.txt","r");
    if (f==NULL) {
        printf("errore in apertura");
        exit(1);
    }
    FILE*g=fopen("bellacopia.txt","r");
    if (g==NULL) {
        printf("errore");
        exit(1);
    }
   
    
    printf("%d\n",prodotto(x,y));
    printf("%d\n",contacarattere(f));
    printf("%d\n",trovamassimo(g));
}
