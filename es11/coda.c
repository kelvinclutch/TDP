
#include "coda.h"
#include <stdlib.h>
#include <stdio.h>

void inCoda(Coda* c, T e){
    if (*c == NULL){
        *c = (Coda) malloc(sizeof(TipoNodo));
        (*c) -> info = e; (*c) -> next = NULL;
    
}
else
    inCoda(&((*c) -> next), e);
    
}

Coda* codaVuota() {
return (Coda*) malloc(sizeof(Coda));
}

void outCoda(Coda* c){
    if (c == NULL || *c == NULL){
    printf("ERRORE: input NULL o coda vuota");
        
    }
    Coda tmp = *c;
    *c = (*c) -> next;
    free(tmp);
}
T primo(Coda* c){
    if (*c == NULL){
        printf("ERRORE: coda vuota");
        exit(1); }
    return (*c)->info;
    
}
bool estVuota(Coda*c){
    return *c==NULL;
}
