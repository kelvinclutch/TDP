
#include <stdio.h>
#include <stdlib.h>
#include"es11.h"


TipoLista append(TipoLista l, T e){
    if(estVuota(l)){
        return cons(e,l);
    }
    return cons(car(l),append(cdr(l),e)); }

int somma_albero(TipoAlbero a){
    if (estVuoto(a))
        return 0;
    else
        return radice(a)+somma_albero(sinistro(a))+somma_albero(destro(a));
}

void stampa_albero(TipoAlbero a){
    if (estVuoto(a))
        return;
    else
        printf("%d\n",radice(a));
    stampa_albero(sinistro(a));
    stampa_albero(destro(a));
}
TipoAlbero normalizza(TipoAlbero a,int x){
    if (estVuoto(a))
        return a;
    else
    {
        int val=radice(a)/2;
        (a)->info=val;
        normalizza(sinistro(a),x);
        normalizza(destro(a),x);
    }
    return a;
    
}
TipoAlbero normalizza_funz_aux(TipoAlbero a,TipoAlbero ris, int x){
    if (estVuoto(a))
        return ris;
    else{
        int val=radice(a)/x;
        ris=creaAlbBin(val,normalizza(sinistro(a),x),normalizza(destro(a),x));
    }
    return ris;
}
TipoAlbero normalizza_funz(TipoAlbero a){
    int x=2;
    TipoAlbero ris=albBinVuoto();
    ris=normalizza_funz_aux(a,ris,x);
    return ris;
}
TipoAlbero taglia_livello(TipoAlbero a, int livello,TipoAlbero b){
    if (estVuoto(a))
        return b;
   
    if (livello==0){
        b->info=radice(a)+somma_albero(destro(a))+somma_albero(sinistro(a));
        
        
    }
    taglia_livello(sinistro(a),livello-1,b);
    taglia_livello(destro(a),livello-1,b);
    return b;
    
    
    
}
int livelli_completi(TipoAlbero a) {
    if (estVuoto(a))
        return 0;
    
    if (!estVuoto(sinistro(a))&&!estVuoto(destro(a)))
        return 1+livelli_completi(sinistro(a))+livelli_completi(destro(a));
        
    else
        return 0;
    
    
    
}
/*   //ES 12
int max(TipoLista l){
    int k=0;
    while(!estVuota(l)){
        if (car(l)>k){
            k=car(l);
            
        }
        l=cdr(l);
    }
       
    return k;
    
}

int ricercaLivello_aux(TipoAlbero a, TipoInfoAlbero v,TipoLista l,int x){
    if (estVuoto(a))
        return max(l);
    if (radice(a)==v)
        l=cons(x,l);
        
    ricercaLivello_aux(sinistro(a),v,l,x+1);
    ricercaLivello_aux(destro(a),v,l,x+1);
    //return -1;
    
}
int ricercaLivello(TipoAlbero a, TipoInfoAlbero v){
    return ricercaLivello_aux(a,v,listaVuota(),0);
        
}
        
int singleChildSum(TipoAlbero a){
    if (estVuoto(a))
        return 0;
    else if ((estVuoto(sinistro(a)) && !estVuoto(destro(a))) || (!estVuoto(sinistro(a))&&estVuoto(destro(a))))
        return radice(a)+singleChildSum(sinistro(a))+singleChildSum(destro(a));

    else
        return singleChildSum(sinistro(a))+singleChildSum(destro(a));
}

TipoLista listaNodiFoglia_aux(TipoAlbero a,TipoLista l){
    if (estVuoto(a))
        return l;
    else if (estVuoto(sinistro(a))&&estVuoto(destro(a)))
        l=append(l,radice(a));
    
    listaNodiFoglia_aux(sinistro(a),l);
    listaNodiFoglia_aux(destro(a),l);
    return l;
        
}


TipoLista listaNodiFoglia(TipoAlbero a){
    TipoLista l=listaVuota();
    
    return listaNodiFoglia_aux(a,l);
}

void nodiMinori(TipoAlbero a, Insieme* ins){
    if (estVuoto(a))
        return;
    else{
        int sx=0;
        int dx=0;
        if (!estVuoto(sinistro(a))){
            sx=radice(sinistro(a));
        }
        if (!estVuoto(destro(a))){
            dx=radice(destro(a));
        }
        int tot=sx+dx;
        if (tot>radice(a)&&!membro(ins,radice(a))){
            inserisci(ins,radice(a));
        }
        
    }
    nodiMinori(sinistro(a),ins);
    nodiMinori(destro(a),ins);
}

*/
TipoLista sinistroMinoreDestro_aux(TipoAlbero a,TipoLista l){
    if (estVuoto(a))
        return l;
    else{
        int dx=0;
        int sx=0;
        if (!estVuoto(sinistro(a)))
            sx=radice(sinistro(a));
        if (!estVuoto(destro(a)))
            dx=radice(destro(a));
        
        if (sx<dx){
            l=append(l,radice(a));
            
        }
        
        
    }
    l=sinistroMinoreDestro_aux(sinistro(a),l);
    l=sinistroMinoreDestro_aux(destro(a),l);
    return l;
}
TipoLista sinistroMinoreDestro(TipoAlbero alb){
    if (estVuoto(alb))
        return NULL;
    else
        return sinistroMinoreDestro_aux(alb,listaVuota());
}
int est_foglia(TipoAlbero a){
    if (estVuoto(a))
        return 0;
    if (estVuoto(sinistro(a))&&estVuoto(destro(a)))
        return 1;
    else
        return 0;
}
TipoLista foglieFratelli_aux(TipoAlbero a,TipoLista l){
    if (estVuoto(a))
        return l;
    else{
        if (est_foglia(sinistro(a))==1 && !estVuoto(destro(a)))
            l=append(l,radice(destro(a)));
        if (est_foglia(destro(a))==1 && !estVuoto(sinistro(a)))
            l=append(l,radice(sinistro(a)));
        
    }
    l=foglieFratelli_aux(sinistro(a),l);
    l=foglieFratelli_aux(destro(a),l);
    return l;
}
TipoLista foglieFratelli(TipoAlbero alb){
    if (estVuoto(alb))
        return NULL;
    else
        return foglieFratelli_aux(alb,listaVuota());
}
