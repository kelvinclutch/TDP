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

int **allocamat(int r, int c) {
  int **a = (int **) malloc(r * sizeof(int *));
  for (int i=0; i<r; i++) {
    a[i] = (int *)malloc(c * sizeof(int));
  }
  return a;
}

void deallocamat(int **a, int r) {
  for (int i=0; i<r; i++) {
    free(a[i]);
  }
  free(a);
}

void stampamat(int **m, int r, int c) {
  for (int i=0; i<r; i++) {
    for (int j=0; j<c; j++) {
       printf(" %2d ", m[i][j]);
    }
    printf("\n");
  }
}

int kernel (int **mat, int r, int c, int i, int j, 
            int dr, int dc) {

   int u0 = i*dr;
   int v0 = j*dc;

   int s = 0;
   for (int u=u0; u< min(r,u0+dr) ; u++) {
       for (int v=v0; v< min(c,v0+dc); v++) {
            s += mat[u][v];
       }
   }
   return s;
}

int ** filter (int **mat, int r, int c, int dr, int dc,
               int *r_out, int *c_out) {

  *r_out = r/dr + (r%dr>0?1:0);
  *c_out = c/dc + (c%dc>0?1:0);

  int **a = allocamat(*r_out,*c_out);

  for (int i=0; i<*r_out; i++) {
    for (int j=0; j<*c_out; j++) {
      a[i][j] =  kernel (mat, r, c, i, j, dr, dc);
    }
  }

  return a;
}


int main() {

  int N=7, M=5;
  int **x = allocamat(N,M);

  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
       x[i][j] = (i+j)%10;
    }
  }

  printf("Matrice input\n");
  stampamat(x,N,M);

  int dr=3, dc=2;
  int r_out, c_out;

  int **r = filter(x,N,M,dr,dc,&r_out,&c_out);

  printf("Risultato\n");
  stampamat(r,r_out,c_out);

  deallocamat(x,N);
  deallocamat(r,r_out);
}

