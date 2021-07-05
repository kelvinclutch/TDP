#include<stdio.h>
#include<stdlib.h>

// Struttura SCL

typedef int TipoInfoSCL;

struct ElemSCL{
        TipoInfoSCL info;
        struct ElemSCL* next;
};

typedef struct ElemSCL TipoNodoSCL;

typedef TipoNodoSCL* TipoSCL;

// inserimento in prima posizione
void add(TipoSCL *pscl, TipoInfoSCL e) {
  TipoSCL temp = *pscl;
  *pscl = (TipoSCL) malloc(sizeof(TipoNodoSCL));
  (*pscl)->info = e;
  (*pscl)->next = temp;
}

// eliminazione in prima posizione
void del(TipoSCL *pscl) {
  TipoSCL temp = *pscl;
  *pscl = (*pscl)->next;
  free(temp);
}

// stampa SCL
void stampa(TipoSCL scl) {
  if (scl==NULL)
    printf("\n");
  else {
    printf("%d ", scl->info);
    stampa(scl->next);
  }
}

// copia
void copia(TipoSCL scl, TipoSCL *pris) {
  if (scl==NULL)
    *pris = NULL;
  else {
    add(pris,scl->info);
    copia(scl->next, &((*pris)->next));
  }
}

// copia inversa (ausiliaria)
void copiaInversa_r(TipoSCL scl, TipoSCL *pris, TipoSCL *q) {
  if (scl==NULL) {
    *pris = NULL; *q = NULL;
  }
  else {

    copiaInversa_r(scl->next, pris, q);

    if (*pris==NULL) {
      *q = (TipoSCL) malloc(sizeof(TipoNodoSCL));
      *pris = *q;
    }
    else {
      (*q)->next = (TipoSCL) malloc(sizeof(TipoNodoSCL));
      *q = (*q)->next;
    }

    (*q)->info = scl->info;
    (*q)->next = NULL;
  }
}

// copia inversa
void copiaInversa(TipoSCL scl, TipoSCL *pris) {
    TipoSCL q;
    copiaInversa_r(scl, pris, &q);
}

// elimina (dealloca) SCL
void delSCL(TipoSCL *pscl) {
  if (*pscl!=NULL) {
    delSCL(&((*pscl)->next));
    free((*pscl)->next);
  }
}

// inserimento prima di un nodo che contiene e
void ins(TipoSCL *pscl, TipoInfoSCL e, TipoInfoSCL n) {
  if (*pscl==NULL) {

  }
  else if ((*pscl)->info==e) {
    add(pscl,n);
  }
  else {
    ins(&((*pscl)->next),e,n);
  }
}

// eliminazione del primo nodo che contiene e
void del(TipoSCL *pscl, TipoInfoSCL e) {
  if (*pscl==NULL) {

  }
  else if ((*pscl)->info==e) {
    del(pscl);
  }
  else {
    del(&((*pscl)->next),e);
  }
}

// inserimento in posizione i
void insp(TipoSCL *pscl, int i, TipoInfoSCL n) {
  if (i==0) {
    add(pscl,n);  
  }
  else if (*pscl==NULL) {
     // nessuna operazione: i>lunghezza SCL
  }
  else {
    insp(&((*pscl)->next),i-1,n);
  }
}

// eliminazione in posizione i
void delp(TipoSCL *pscl, int i) {
  if (*pscl==NULL) {
    // nessuna operazione: i>=lunghezza SCL
  }
  else if (i==0) {
    del(pscl);
  }
  else {
    delp(&((*pscl)->next),i-1);
  }
}

// inverti i valori in posizione dispari (ausiliaria)
void invertiDispari_r(TipoSCL scl, int i) {
  if (scl==NULL) {
  }
  else {
     if (i%2==1)
       scl->info *= -1;
     invertiDispari_r(scl->next,i+1);
  }
}

// inverti i valori in posizione dispari
void invertiDispari(TipoSCL scl) {
   invertiDispari_r(scl,0);
}

// trova un elemento
bool trova(TipoSCL scl, TipoInfoSCL n) {
  if (scl==NULL)
    return false;
  else 
    return scl->info==n || trova(scl->next,n);
}

// verifica presenza di duplicati
bool duplicati(TipoSCL scl) {
  if (scl==NULL)
    return false;
  else
    return trova(scl->next, scl->info) || duplicati(scl->next);
}

// elimina duplicati (elimina i nodi nelle prime posizioni)
void eliminaDuplicati(TipoSCL *pscl) {
  if (*pscl!=NULL) {
    if (trova((*pscl)->next,(*pscl)->info)) {
      TipoSCL t = *pscl; 
      *pscl = (*pscl)->next;
      free(t);
      eliminaDuplicati(pscl); // continuare dal nodo corrente
    }
    else {
      eliminaDuplicati(&((*pscl)->next)); // andare al successivo
    }    
  }
}

// elimina duplicati (elimina i nodi nelle ultime posizioni)
void eliminaDuplicatiq(TipoSCL *pscl) {
  if (*pscl!=NULL) {
    if (trova((*pscl)->next,(*pscl)->info)) {
      del(&(*pscl)->next,(*pscl)->info);
      eliminaDuplicatiq(pscl); // continuare dal nodo corrente
    }
    else {
      eliminaDuplicatiq(&((*pscl)->next)); // andare al successivo
    }    
  }
}


int main() {
  TipoSCL l1 = NULL, l2, l3;
  add(&l1,4);
  add(&l1,3);
  add(&l1,1);

  printf("l1: ");
  stampa(l1);

  ins(&l1,3,2);
  ins(&l1,5,2);
  ins(&l1,3,3);
  insp(&l1,5,5);
  insp(&l1,1,6);

  printf("l1: ");
  stampa(l1);

  del(&l1,3);
  del(&l1,6);

  printf("l1: ");
  stampa(l1);

  copia(l1,&l2);
  copiaInversa(l1,&l3);

  printf("l2 = copia(l1): ");
  stampa(l2);
  printf("l3 = copiaInversa(l1): ");
  stampa(l3);

  invertiDispari(l2);
  printf("invertiDispari(l2): ");
  stampa(l2);

  insp(&l2,5,-2);
  insp(&l2,1,-4);
  insp(&l2,7,-2);
  insp(&l2,0,1);

  delSCL(&l3);
  copia(l2,&l3);

  printf("l2: ");
  stampa(l2);
  printf("duplicati: %d \n", duplicati(l2));
  eliminaDuplicati(&l2);
  printf("eliminaDuplicati(l2): ");
  stampa(l2);
  printf("duplicati: %d \n", duplicati(l2));

  printf("l3: ");
  stampa(l3);
  printf("duplicati: %d \n", duplicati(l3));
  eliminaDuplicatiq(&l3);
  printf("eliminaDuplicatiq(l3): ");
  stampa(l3);
  printf("duplicati: %d \n", duplicati(l3));

  delSCL(&l1);
  delSCL(&l2);
  delSCL(&l3);
}

