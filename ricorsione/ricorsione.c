//
//  ricorsione.c
//  
//
//  Created by Paolo Cupini on 07/04/21.
//

#include "ricorsione.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int fattoriale(int x) {
    if (x==0)
        return 1;
    else
        return x*fattoriale(x-1);
}
int potenza(int x,int y) {
    if (y==0)
        return 1;
    else
        return x*potenza(x,y-1);
}
int binomiale(int x,int y) {
    return fattoriale(x)/(fattoriale(x-y)*fattoriale(y));
}
void leggifile(FILE *f,FILE*g) {
    
    char c;
    c=fgetc(f);
    while (c!=EOF) {
        
        leggifile(f,g);
        fputc(c,g);
    }
    exit(1);
    
   
}
int prodotto(int x,int y) {
    if (y==0)
        return 1;
    else
        return x+(prodotto(x,y-1));
        
}
int contacarattere(FILE*f) {
    char c;
    char g='a';
    c=fgetc(f);
    
    if (c==EOF)
        return 0;
    else if (c==g)
        return 1+contacarattere(f);
    else
        return contacarattere(f);
  }
int trovamassimo(FILE*g) {
    int n;
    
    
    int fin;
    fin=fscanf(g,"%d",&n);
    if (fin==EOF)
        return 0;
    else
    {
        int m=trovamassimo(g);
        if (m>n) return m;
        else return n;
    }
    
    
}

