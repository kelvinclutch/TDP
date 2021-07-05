//
//  filtr.c
//  
//
//  Created by Paolo Cupini on 06/04/21.
//

#include "filtr.h"
#include<stdlib.h>
#include <stdio.h>
Mat* crea_mat(int r, int c) {
    Mat *m=(Mat*)malloc(sizeof(Mat));
    m->rows=r;
    m->cols=c;
    m->rows_pt=(int**)calloc(r,sizeof(int*));
    for (int i=0;i<r;i++) {
        m->rows_pt[i]=(int*)calloc(c,sizeof(int));
}
    return m;
}
void riempi_mat(Mat*m){
    int val;
    for (int i=0;i<m->rows;i++) {
        for (int j=0;j<m->cols;j++) {
            printf("inseirsci numero in posizione %d%d\n",i,j);
            scanf("%d",&val);
            m->rows_pt[i][j]=val;
        
        }
    }
    
    
}
void stampa_mat(Mat *ris){
    for (int i=0;i<ris->rows;i++) {
        for (int j=0;j<ris->cols;j++)
        printf("%d",ris->rows_pt[i][j]);
    printf("\n");
    }
}






/*
Mat*filtramat(Mat*m,Mat*ris) {
    for (int i=0;i<m->rows;i++){
        for (int j=0;j<m->cols;j++)
        {
            if (i!=0 && j!=0 && i!=m->rows-1 && j!=m->cols-1)
            {
                ris->rows_pt[i][j]=m->rows_pt[i][j]-m->rows_pt[i-1][j-1]-m->rows_pt[i-1][j]-m->rows_pt[i-1][j+1]-m->rows_pt[i][j-1]-m->rows_pt[i][j+1]-m->rows_pt[i+1][j-1]-m->rows_pt[i+1][j]-m->rows_pt[i+1][j+1];
            }
           
        }
        
    }
    stampa_mat(ris);
}

Mat* repeatmatrix(Mat*m,int righe, int colonne) {
    Mat* ris=crea_mat(m->rows*righe,m->cols*colonne);
    
    for (int i=0;i<ris->rows;i++) {
        for (int j=0;j<ris->cols;j++) {
           
            
        }
        
        
    }
    
}
Mat* inverti_diag(Mat*m) {
    int*v=(int*)malloc(m->rows*sizeof(int));
    int *v1=(int*)malloc(m->rows*sizeof(int));
    int conta=0;
    int conta1=0;
    for (int i=0;i<m->rows;i++) {
        for (int j=0;j<m->cols;j++) {
            if (i==j)
            {
                v[conta]=m->rows_pt[i][j];
                conta++;
            }
            if (i+j==m->rows-1)
            {
                v1[conta1]=m->rows_pt[i][j];
                conta1++;
            }
        }
        
        
    }
    conta=0;
    conta1=0;
    for (int i=0;i<m->rows;i++) {
        for (int j=0;j<m->cols;j++) {
            if (i==j) {
                m->rows_pt[i][j]=v1[conta1];
                conta1++;
            }
            if (i+j==m->rows -1)
            {
                m->rows_pt[i][j]=v[conta];
                conta++;
            }
            
        }
    }
    stampa_mat(m);
}


*/

int *somma_colonna(Mat*src){
    int *c=(int*)malloc(sizeof(int)*src->cols);
    int k=0;
    int somma=0;
    while(k!=src->cols){
    for (int i=0;i<src->rows;i++){
        for (int j=0;j<src->cols;j++){
            if (j==k)
                somma+=src->rows_pt[i][j];
        }
    }
    c[k]=somma;
    somma=0;
    k++;
    }
    return c;
}

int matrix_block_sum(Mat* dest, Mat* src, int start_row, int start_col){
    if (start_row>=src->rows || start_row>=src->cols)
        return 0;
    else{
        for (int i=start_row;i<src->rows;i++){
            for (int j=start_col;j<src->cols;j++){
                dest->rows_pt[i][j]=dest->rows_pt[i][j]+src->rows_pt[i-start_row][j-start_col];
            }
        }
    }
    return src->rows * src->cols;
}
TipoLista append(TipoLista l,int x){
    if (estVuota(l))
        return cons(x,l);
    else
        return cons(car(l),append(cdr(l),x));
}
/*
TipoLista* lowerValues(Mat* m, int value){
    TipoLista l=listaVuota();
    for (int i=0;i<m->rows;i++){
        for (int j=0;j<m->cols;j++){
            if (m->rows_pt[i][j]<value)
                l=append(l,m->rows_pt[i][j]);
        }
    }
    return &l;
    
}

void mat_rotate_90_clockwise(Mat* dest, Mat* src){
    for (int i=0;i<dest->rows;i++){
        for (int j=0;j<dest->cols;j++){
            dest->rows_pt[i][j]=src->rows_pt[j][i]);
        }
    }
}
*/
/*
Mat* sommaSudEst(Mat* mat){
    Mat*ris=crea_mat(mat->rows,mat->cols);
    int somma=0;
    for (int i=0;i<mat->rows;i++){
        for (int j=0;j<mat->cols;j++){
            somma=mat->rows_pt[i][j];
            if (i+1!=mat->rows && j+1!=mat->cols){
                somma+=mat->rows_pt[i+1][j+1]+mat->rows_pt[i+1][j]+mat->rows_pt[i][j+1];
            }
            else{
                if (i+1==mat->rows && j+1!=mat->cols)
                    somma+=mat->rows_pt[0][j+1] +mat->rows_pt[0][j];
                if (i+1!=mat->rows && j+1==mat->cols)
                    somma+=mat->rows_pt[i+1][0] +mat->rows_pt[i][0];
                if (i+1==mat->rows && j+1==mat->cols)
                    somma+=mat->rows_pt[0][0]+mat->rows_pt[i][0]+mat->rows_pt[0][j];
                
            }
            
            
            ris->rows_pt[i][j]=somma;
        }
    }
    return ris;
}

*/
Mat* mirror(Mat* m){
    Mat*ris=crea_mat(m->rows,m->cols*2);
    for (int i=0;i<m->rows;i++){
        for(int j=0;j<m->cols;j++){
            ris->rows_pt[i][j]=m->rows_pt[i][j];
        }
        
    }
    for (int i1=0;i1<m->rows;i1++){
        int k=m->cols;
        for (int j1=m->cols;j1<ris->cols;j1++){
            
            ris->rows_pt[i1][j1]=m->rows_pt[i1][k-1];
            k--;
        }
    }
    return ris;
}
int calcola_diag(Mat* src,int k){
    int somma=0;
    for (int i=0;i<src->rows;i++){
        for (int j=0;j<src->cols;j++){
            if (i-j==k)
                somma+=src->rows_pt[i][j];
        }
    }
    return somma;
}
void trasforma( Mat* src, int* vect ){
    int i=0;
    while (i<src->rows){
        vect[i]=calcola_diag(src,i);
        i++;
    }
    

}
int massimo(Mat* src){
    int valm=0;
    int indmax=0;
    for (int j=0;j<src->cols;j++){
        int somma=0;
        for (int i=0;i<src->rows;i++){
            somma+=src->rows_pt[i][j];
        }
        if (somma>valm){
            valm=somma;
            indmax=j;
        }
    }
    int max=0;
    int k=indmax;
    for (int i1=0;i1<src->rows;i1++){
        if (src->rows_pt[i1][k]>max){
            max=src->rows_pt[i1][k];
            
            
        }
        }
    
    return max;
    
}
void matrix_compute_neighboor_sub(Mat* dest, Mat* src){
    for (int i=0;i<src->rows;i++){
        for (int j=0;j<src->cols;j++){
            printf("%d%d\n",i,j);
            if (i+1!=src->rows && i!=0 && j+1!=src->cols && j!=0)
                src->rows_pt[i][j]=dest->rows_pt[i][j]-dest->rows_pt[i-1][j-1]-dest->rows_pt[i][j-1]-dest->rows_pt[i-1][j]-dest->rows_pt[i-1][j+1]-dest->rows_pt[i+1][j-1]-dest->rows_pt[i+1][j+1]-dest->rows_pt[i+1][j]-dest->rows_pt[i][j+1];
            else {
                if (i==0 && j==0)
                    src->rows_pt[i][j]=dest->rows_pt[i][j]-dest->rows_pt[i+1][j+1]-dest->rows_pt[i+1][j]-dest->rows_pt[i][j+1];
                if (i==0 && j+1==src->cols)
                    src->rows_pt[i][j]=dest->rows_pt[i][j]-dest->rows_pt[i][j-1]-dest->rows_pt[i+1][j]-dest->rows_pt[i+1][j-1];
                if (j==0 && i+1==src->rows)
                    src->rows_pt[i][j]=dest->rows_pt[i][j]-dest->rows_pt[i-1][j]-dest->rows_pt[i][j+1]-dest->rows_pt[i-1][j+1];
                if (j+1==src->cols && i+1==src->rows)
                    src->rows_pt[i][j]=dest->rows_pt[i][j]-dest->rows_pt[i][j-1]-dest->rows_pt[i-1][j]-dest->rows_pt[i-1][j-1];
            }
            else{
                    if (i==0)
                        src->rows_pt[i][j]=dest->rows_pt[i][j]-dest->rows_pt[i+1][j]-dest->rows_pt[i+1][j+1]-dest->rows_pt[i][j+1]-dest->rows_pt[i][j-1]-dest->rows_pt[i+1][j-1];
                    if (i+1==src->rows)
                        src->rows_pt[i][j]=dest->rows_pt[i][j]-dest->rows_pt[i-1][j]-dest->rows_pt[i-1][j+1]-dest->rows_pt[i][j+1]-dest->rows_pt[i][j-1]-dest->rows_pt[i-1][j-1];
                    if (j==0)
                        src->rows_pt[i][j]=dest->rows_pt[i][j]-dest->rows_pt[i+1][j]-dest->rows_pt[i][j+1]-dest->rows_pt[i-1][j]-dest->rows_pt[i+1][j+1]-dest->rows_pt[i-1][j+1];
                    if (j+1==src->cols)
                        src->rows_pt[i][j]=dest->rows_pt[i][j]-dest->rows_pt[i-1][j-1]-dest->rows_pt[i][j-1]-dest->rows_pt[i-1][j]-dest->rows_pt[i+1][j-1]-dest->rows_pt[i+1][j];
                }
            }
        }
    }

