#include<stdlib.h>
#include<stdio.h>

#include"insieme.h"

// O(1)
Insieme* insiemeVuoto() {
  Insieme* r = (Insieme*) malloc(sizeof(Insieme*));
  *r = NULL;
  return r;
}

// O(1)
bool estVuoto(Insieme* ins) {
    return *ins == NULL;
}

// O(n)
void inserisci(Insieme *ins, T e) {
    if (!membro(ins,e)) {
        NodoSCL* n = (NodoSCL*) malloc(sizeof(NodoSCL));
        n->info = e;
        n->next = *ins;
        *ins = n;
    }
}

// O(n)
void elimina(Insieme *ins, T e) {
    if (*ins == NULL){
      return;
    }
    NodoSCL* p = *ins;
    if (p->info == e){
      *ins = p->next;
      free(p);
      return;
    }
    elimina(&((*ins) -> next),e);
}

// O(n)
bool  membro(Insieme* ins, T e) {
    NodoSCL* p = *ins;
    while (p!=NULL) {
        if (p -> info == e){
          return true;
        }
        p = p->next;
    }
    return false;
}

// O(1)
IteratoreInsieme* creaIteratoreInsieme(Insieme* ins) {
  IteratoreInsieme* r = (IteratoreInsieme*) malloc(sizeof(IteratoreInsieme));
  r->ptr = *ins;
  return r;
}

// O(1)
bool hasNext(IteratoreInsieme* it) {
    return it->ptr!=NULL;
}

// O(1)
T next(IteratoreInsieme *it) {
    T r = TERRORVALUE;
    if (it->ptr!=NULL) {
        r = it->ptr->info;
        it->ptr = it->ptr->next;
    }
    else
        printf("ERRORE Iteratore non valido.\n");
    return r;
}




// Implementazione funzioni ausiliarie
void stampaInsieme(Insieme* i, char* nome){
  printf("%s = {", nome);
  IteratoreInsieme* it = creaIteratoreInsieme(i);
  while(hasNext(it)){
    printf("%d ", next(it));
  }
  free(it);
  printf("}\n");
}
