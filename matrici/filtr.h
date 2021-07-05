//
//  filtr.h
//  
//
//  Created by Paolo Cupini on 06/04/21.
//

#ifndef filtr_h
#define filtr_h
#include "lista_2.h"
typedef struct {
    int rows;
    int cols;
    int**rows_pt;
}Mat;

Mat* crea_mat(int r,int c);
void riempi_mat(Mat *m);
void stampa_mat(Mat *ris);
Mat* filtramat(Mat*m,Mat*ris);
Mat* repeatmatrix(Mat*m,int righe, int colonne);
Mat* inverti_diag(Mat*m);
Mat* sommaSudEst(Mat* mat);
void mat_rotate_90_clockwise(Mat* dest, Mat* src);
Mat* sommaSudEst(Mat* mat);
void trasforma( Mat* src, int* vect );
int calcola_diag(Mat* src,int k);
int massimo(Mat* src);
int *somma_colonna(Mat*src);
Mat* mirror(Mat* m);
Mat *mirror_aux(Mat*m);
int matrix_block_sum(Mat* dest, Mat* src, int start_row, int start_col);
TipoLista append(TipoLista l,int x);
TipoLista* lowerValues(Mat* m, int value);
void mat_rotate_90_clockwise(Mat* dest, Mat* src);
int compute_diagonal_integral(float** v , Mat* src);
Mat* matrixRepeat(Mat* src, int num_row_blocks, int num_col_blocks);
int matrixBlockCopy(Mat* dest, Mat* src,int start_row, int start_col);
void matrix_compute_neighboor_sub(Mat* dest, Mat* src);

#endif /* filtr_h */
