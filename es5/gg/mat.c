#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int rows;
    int cols;
    float **rows_pt;
}Mat;

Mat* crea_mat(int r,int c);

void stampa(Mat*m);
int main() {
    
    FILE*file=fopen("mat.txt","r");
    if (file==NULL) {
        puts("errore");
        exit(1);
    }
    int n;
    int k;
    fscanf(file," %d %d",&n,&k);
    Mat *m=crea_mat(n,k);
    float ku;
    
        for (int i=0;i<m->rows;i++) {
            for (int j=0;j<m->cols;j++) {
                (fscanf(file,"%f",&ku));
                m->rows_pt[i][j]=ku;
            
            
        }
            
        
    }
    stampa(m);
    
    
    
}
Mat* crea_mat(int r, int c) {
    Mat*m=(Mat*)malloc(sizeof(Mat));
    m->rows=r;
    m->cols=c;
    m->rows_pt=(float**)calloc(r,sizeof(float**));
    for (int i=0;i<r;i++) {
        m->rows_pt[i]=(float*)calloc(c,sizeof(float));
    }
    return m;
}

    

void stampa (Mat*m) {
    for (int i=0;i<m->rows;i++) {
        for (int j=0;j<m->cols;j++)
            printf("%.0f",m->rows_pt[i][j]);
    printf("\n");
        
        
    }
}
