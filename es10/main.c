#include<stdbool.h>
#include <stdio.h>
#include "listacopia.h"
#include <stdlib.h>
#include "es10.h"
int main () {
    TipoAlbero m=creaAlbBin(2,albBinVuoto(),albBinVuoto());
    TipoAlbero n=creaAlbBin(7,m,albBinVuoto());
    TipoAlbero k=creaAlbBin(4,albBinVuoto(),albBinVuoto());
    TipoAlbero a = creaAlbBin(6,albBinVuoto(),k);
    TipoAlbero b = creaAlbBin(11,albBinVuoto(),n);
    TipoAlbero c = creaAlbBin(3,albBinVuoto(),albBinVuoto());
    TipoAlbero d = creaAlbBin(10,albBinVuoto(),albBinVuoto());
    TipoAlbero e = creaAlbBin(7,a,b);
    TipoAlbero f = creaAlbBin(4,c,d);
    TipoAlbero g = creaAlbBin(8,e,f);
    //stampa_albero(g);
    //printf("%d",trova_massimo(g));
    //printf("%d",somma_foglie(g));
    //printf("%d",cerca_livello(g,5));
    //printf("%d",conta_dispari(g));
    //printf("%d\n",somma_singoli(g));
    //albero_lista(g);
    //somma_sottoalbero(g);
    
    //stampa_albero(g);
    //TipoLista l=percorso_lungo(g,listaVuota());
    //printlist(l);
    //scambia_foglie(g);
    TipoLista l=foglieFratelli(g);
    printlist(l);
}
