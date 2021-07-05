#include<stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "es10.h"
void modAlbBin(TipoAlbero *a, TipoInfoAlbero info, TipoAlbero *sx, TipoAlbero *dx) {
  TipoAlbero s=*sx, d=*dx;  // serve nel caso in cui a == sx o dx
  (*a)->info = info;
  (*a)->sinistro = s;
  (*a)->destro = d;
}
bool est_foglia(TipoAlbero a){
    if (estVuoto(a))
        return 0;
    if  (estVuoto(sinistro(a))&&estVuoto(destro(a)))
        return 1;
    else
        return 0;
}

int profondita(TipoAlbero a){
    if (estVuoto(a))
        return 0;
    else
        return 1+profondita(sinistro(a))+profondita(destro(a));
}
int conta_nodi_livello(TipoAlbero a,int l) {
    if (estVuoto(a))
        return 0;
    if (l==0)
        return 1;
    else
        return conta_nodi_livello(sinistro(a),l-1)+conta_nodi_livello(destro(a),l-1);
}
int trova_livello(TipoAlbero a,TipoInfoAlbero x) {
    if (estVuoto(a))
        return -1;
    if (radice(a)==x)
        return 0;
    else{
        int sx=trova_livello(sinistro(a),x);
        int dx=trova_livello(destro(a),x);
        if (sx<0 && dx<0)
            return -1;
        else
            return 1+max(sx,dx);
    }
}



int max(int c,int x) {
    if (c>x)
        return c;
    else
        return x;
}
void stampa_albero(TipoAlbero a) {
    if (estVuoto(a))
        return;
    else {
        printf("%d\n",radice(a));
        stampa_albero(sinistro(a));
        stampa_albero(destro(a));
}
}
TipoInfoAlbero trova_massimo_aux(TipoAlbero a,TipoInfoAlbero b){
    if (estVuoto(a))
        return b;
    else {
        return max(trova_massimo_aux(sinistro(a),max(b,radice(a))),trova_massimo_aux(destro(a),max(b,radice(a))));
    
        
    }
}

TipoInfoAlbero trova_massimo(TipoAlbero a) {
    if (estVuoto(a))
        return -1;
    else return trova_massimo_aux(a,radice(a));
    
}
TipoInfoAlbero somma_foglie(TipoAlbero a) {
    if (estVuoto(a))
        return 1;
    else if (estVuoto(destro(a)) && estVuoto(sinistro(a)))
        return radice(a);
    else
        return somma_foglie(sinistro(a))+somma_foglie(destro(a));
   
}

int cerca_livello(TipoAlbero a, TipoInfoAlbero v) {
    if (estVuoto(a))
        return -1;
    
    else {
        if (radice(a)==v)
            return 0;
        else {
            int sx=cerca_livello(sinistro(a),v);
            if (sx==-1){
                int dx=cerca_livello(destro(a),v);
                return dx==-1 ?-1 :dx+1;
            }
            else
                return sx+1;
        }
        
    }
  
}

int conta_dispari(TipoAlbero a) {
                  
    if (estVuoto(a)){
        return 0;
    }
    int valsx=0,valdx=0;
    if (a->sinistro!=NULL){
        valsx=a->sinistro->info;
    }
    if (a->destro!=NULL) {
        valdx=a->destro->info;
    }
    if ((radice(a)+valdx+valsx)%2==0)
        return conta_dispari(sinistro(a))+conta_dispari(destro(a));
    else
        return conta_dispari(sinistro(a))+conta_dispari(destro(a))+1;
    
}
   

int somma_singoli(TipoAlbero a) {
    if (estVuoto(a))
        return 0;
    else if ((estVuoto(sinistro(a)) && !estVuoto(destro(a))) || (estVuoto(destro(a)) && !estVuoto(sinistro(a))))
        return 1+somma_singoli(destro(a))+somma_singoli(sinistro(a));
    else
        return somma_singoli(destro(a))+somma_singoli(sinistro(a));
    
}

TipoLista albero_lista_aux(TipoAlbero a,TipoLista l){
    if (estVuoto(a)) return l;
    else {
        l=albero_lista_aux(destro(a),l);
        l=cons(radice(a),l);                            //lista sinistra
        
        l=albero_lista_aux(sinistro(a),l);
        return l;
    }
}

TipoLista albero_lista(TipoAlbero a) {
    return albero_lista_aux(a,listaVuota());
}

int somma_albero(TipoAlbero a) {
    if (estVuoto(a))
        return 0;
    else
        return radice(a)+somma_albero(sinistro(a))+somma_albero
        (destro(a));
}

void somma_sottoalbero(TipoAlbero a) {
    if (estVuoto(a))
        return;
    else {
        int dx=somma_albero(destro(a));
        int sx=somma_albero(sinistro(a));
        a->info=sx+dx;
    }
    somma_sottoalbero(sinistro(a));
    somma_sottoalbero(destro(a));
}
/*
void scambia_foglie(TipoAlbero a) {
    if (estVuoto(a))
        return;
    else{
        if (est_foglia(sinistro(a))||est_foglia(destro(a))){
            modAlbBin(&a,radice(a),destro(a),sinistro(a));
        
        }
    }
    scambia_foglie(sinistro(a));
    scambia_foglie(destro(a));

        
}
 */
TipoLista foglieFratelli_aux(TipoAlbero a,TipoLista l){
    if (estVuoto(a))
        return l;
    else if (est_foglia(sinistro(a)) && est_foglia(destro(a))){
        l=cons(radice(sinistro(a)),l);
        l=cons(radice(destro(a)),l);
        
    }
    l=foglieFratelli_aux(sinistro(a),l);
    l=foglieFratelli_aux(destro(a),l);
    return l;
    
    
}
TipoLista foglieFratelli(TipoAlbero a){
    return foglieFratelli_aux(a,listaVuota());
}
