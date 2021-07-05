
// crea una matrice ceil(r/dr) x ceil (c/dc), contenente in posizione i e j la somma degli elementi della sotto_mat di dimensione dr x dc a partire dall'indice (i*dr,j*dc)



#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "filtr.h"




int main () {
    int r=3;
    int c=4;
    int r1=2;
    int c1=2;
    //Mat *m1=crea_mat(r1,c1);
    //riempi_mat(m1);
    Mat*m=crea_mat(r,c);
    riempi_mat(m);
    //printf("%d\n",massimo(m));
    //Mat *ris=sommaSudEst(m);
    //stampa_mat(ris);
    //Mat*m1=crea_mat(r1,c1);
    //riempi_mat(m1);
    matrix_compute_neighboor_sub(m,crea_mat(r,c));
    

}

