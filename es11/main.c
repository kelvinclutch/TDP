
#include <stdio.h>
#include <stdlib.h>
#include"es11.h"
int main () {
   
    TipoAlbero e=creaAlbBin(2,albBinVuoto(),albBinVuoto());
    TipoAlbero f=creaAlbBin(8,albBinVuoto(),albBinVuoto());
    TipoAlbero g=creaAlbBin(12,albBinVuoto(),albBinVuoto());
    TipoAlbero h=creaAlbBin(11,albBinVuoto(),albBinVuoto());
    TipoAlbero i=creaAlbBin(14,albBinVuoto(),albBinVuoto());
    
    
   
    TipoAlbero d=creaAlbBin(1,h,albBinVuoto());
    TipoAlbero b=creaAlbBin(5,d,e);
    TipoAlbero c=creaAlbBin(7,f,g);
    TipoAlbero a=creaAlbBin(2,b,c);
    //TipoLista l=sinistroMinoreDestro(a);
    TipoLista l=foglieFratelli(a);
    printlist(l);
    //Insieme *ins=insiemeVuoto();
    //nodiMinori(a,ins);
    //stampaInsieme(ins,"a");
    //int x=somma_albero(a);
    //TipoAlbero ris=normalizza_funz(a);
    //int ris=ricercaLivello(a,2);
    //printf("%d\n",ris);
    
    //TipoAlbero k=taglia_livello(a,2,a);
    //printf("%d\n",singleChildSum(a));
    //stampa_albero(k);
    //int xbu=livelli_completi(a);
    //printf("%d\n",xbu);
    //printlist(listaNodiFoglia(a));
    
}
