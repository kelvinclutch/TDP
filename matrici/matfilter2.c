/*

  Esercizio:

  Scrivere una funzione che restituisce una matrice ottenuta
  da una operazione di filtraggio di una matrice in input
  applicando un kernel sommatore.

  Data una matrice r x c e un kernel di dimensione dr x dc,
  la matrice filtrata ha dimensioni ceil(r/dr) x ceil(c/dc)
  e ogni componente i, j contiene la somma di tutti gli elementi 
  della sotto-matrice della matrice di input di dimensione dr x dc 
  a partire dall'indice (i*dr, j*dc).

  Scrivere tutte le funzioni accessorie e la funzione main per
  eseguire dei test.

  Note:
  - ceil = approssimazione in eccesso
  - se r non è multiplo di dr oppure c non è multiplo di dc
    la dimensione effettiva della sotto-matrice potrebbe essere
    minore di dr x dc in prossimità dell'ultima riga o dell'ultima colonna.

*/


#include<stdio.h>
#include<stdlib.h>

#define min(a,b) ((a)<(b)?(a):(b))

typedef struct {
  int rows, cols;
  int ** row_ptrs; // array di puntatori alle righe
} Mat;

Mat *allocamat(int r, int c) {
  Mat *a = (Mat *)malloc(sizeof(Mat));
  a->rows=r; a->cols=c;
  a->row_ptrs = (int **) malloc(r * sizeof(int *));
  for (int i=0; i<r; i++) {
    a->row_ptrs[i] = (int *)malloc(c * sizeof(int));
  }
  return a;
}

void deallocamat(Mat *a) {
  for (int i=0; i<a->rows; i++) {
    free(a->row_ptrs[i]);
  }
  free(a->row_ptrs);
  free(a);
}

void stampamat(Mat *m) {
  for (int i=0; i<m->rows; i++) {
    for (int j=0; j<m->cols; j++) {
       printf(" %2d ", m->row_ptrs[i][j]);
    }
    printf("\n");
  }
}

int kernel (Mat *mat, int i, int j, 
            int dr, int dc) {

   int u0 = i*dr;
   int v0 = j*dc;

   int s = 0;
   for (int u=u0; u< min(mat->rows,u0+dr) ; u++) {
       for (int v=v0; v< min(mat->cols,v0+dc); v++) {
            s += mat->row_ptrs[u][v];
       }
   }
   return s;
}

Mat * filter (Mat *mat, int dr, int dc) {

  Mat *a = allocamat(mat->rows/dr + (mat->rows%dr>0?1:0),mat->cols/dc + (mat->cols%dc>0?1:0));

  for (int i=0; i<a->rows; i++) {
    for (int j=0; j<a->cols; j++) {
      a->row_ptrs[i][j] = f (...) ;

    }
  }

  return a;
}


int main() {

  int N=7, M=5;
  Mat *x = allocamat(N,M);

  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
       x->row_ptrs[i][j] = (i+j)%10;
    }
  }

  printf("Matrice input\n");
  stampamat(x);

  int dr=3, dc=2;

  Mat *r = filter(x,dr,dc);

  printf("Risultato\n");
  stampamat(r);

  deallocamat(x);
  deallocamat(r);
}

