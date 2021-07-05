#include "alberoBinario.h"
#include <stdio.h>
#include <stdlib.h>

#include "lista.h"
void rimuoviAlberi(TipoAlbero *a, TipoInfoAlbero info);
TipoLista append(TipoLista l, T e);
void stampa_albero(TipoAlbero a);
int somma_albero(TipoAlbero a);
TipoAlbero normalizza_funz(TipoAlbero a);
TipoAlbero normalizza(TipoAlbero a,int x);
TipoAlbero normalizza_funz_aux(TipoAlbero a,TipoAlbero ris, int x);
TipoAlbero da_array_ordinato(int *a, const int n);
TipoAlbero taglia_livello(TipoAlbero a, int livello,TipoAlbero b);
void visita_in_ampiezza(TipoAlbero a);
int livelli_completi(TipoAlbero a);
//es12
int ricercaLivello(TipoAlbero a, TipoInfoAlbero v);
//int ricercaLivello_aux(TipoAlbero a, TipoInfoAlbero v,TipoLista l,int x);
//int max(TipoLista l);
int singleChildSum(TipoAlbero a);
//TipoLista listaNodiFoglia(TipoAlbero a);
//TipoLista listaNodiFoglia_aux(TipoAlbero a,TipoLista l);
//void nodiMinori(TipoAlbero a, Insieme* ins);
TipoLista sinistroMinoreDestro_aux(TipoAlbero a,TipoLista l);
TipoLista sinistroMinoreDestro(TipoAlbero alb);
int est_foglia(TipoAlbero a);
TipoLista foglieFratelli_aux(TipoAlbero a,TipoLista l);
TipoLista foglieFratelli(TipoAlbero alb);
