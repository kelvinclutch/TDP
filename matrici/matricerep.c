#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int rows;
    int cols;
    int **rows_pt;
    
}Mat;

Mat* creamatrice(int r,int c);
void riempimat(Mat*m);
Mat* moltiplica(Mat*m,Mat*ris);
void stampamat(Mat*ris);
int main() {
    int r=3;
    int c=3;
    int k=3;
    Mat*m=creamatrice(r, c);
    riempimat(m);
    Mat*ris=creamatrice(r*k,c*k);
    moltiplica(m,ris);
}

Mat* creamatrice(int r,int c) {
    Mat*m=(Mat*)malloc(sizeof(Mat));
    m->rows=r;
    m->cols=c;
    m->rows_pt=(int**)calloc(r,sizeof(int**));
    for (int i=0;i<r;i++) {
        m->rows_pt[i]=(int*)calloc(c,sizeof(int*));
    }
    return m;
    
}
void riempimat(Mat *m) {
    
    
    int val;
    for (int i=0;i<m->rows;i++) {
        for (int j=0;j<m->cols;j++) {
        printf("inseirsci valore \n");
        scanf("%d",&val);
        m->rows_pt[i][j]=val;
            
        }
    }
}
Mat* moltiplica(Mat*m,Mat*ris) {
    
    for (int i=0;i<ris->rows;i++) {
        
        for (int j=0;j<ris->cols;j++) {
            
            
            
        }
    }
                
    //stampamat(ris);
    //return ris;
            }
        
    
void stampamat(Mat *ris) {
    for (int i=0;i<ris->rows;i++) {
        for (int j=0;j<ris->cols;j++)
        printf("%d ",ris->rows_pt[i][j]);
    printf("\n");
    }
}
