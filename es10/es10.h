#include "alberoBinario.h"
#include "listacopia.h"
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
void modAlbBin(TipoAlbero *a, TipoInfoAlbero info, TipoAlbero *sx, TipoAlbero *dx);
bool est_foglia(TipoAlbero a);
int profondita(TipoAlbero a);
int max(int c,int x);
TipoInfoAlbero trova_massimo_aux(TipoAlbero a,TipoInfoAlbero b);
TipoInfoAlbero trova_massimo(TipoAlbero a);
void stampa_albero(TipoAlbero a);
TipoInfoAlbero somma_foglie(TipoAlbero a);
int cerca_livello(TipoAlbero a, TipoInfoAlbero v);
int conta_dispari(TipoAlbero a);
int somma_singoli(TipoAlbero a);
TipoLista albero_lista_aux(TipoAlbero a,TipoLista l);
TipoLista albero_lista(TipoAlbero a);
TipoLista  percorso_lungo(TipoAlbero a,TipoLista l);
int somma_albero(TipoAlbero a);
void somma_sottoalbero(TipoAlbero a);
void scambia_foglie(TipoAlbero a);
int conta_nodi_livello(TipoAlbero a,int l);
int trova_livello(TipoAlbero a,TipoInfoAlbero x);
TipoLista foglieFratelli(TipoAlbero a);
