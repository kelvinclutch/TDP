#include<stdio.h>
#include<stdlib.h>
#include "scl.h"
#include<stdbool.h>


int scl_len(TipoSCL scl) {
    if (scl==NULL)
        return 0;
    else
        return 1+scl_len(scl->next);
}

int scl_sum(TipoSCL scl) {
    if (scl==NULL)
        return 0;
    else
        return (scl)->info+scl_sum(scl->next);
    
}

float scl_dot(TipoSCL scl1, TipoSCL scl2) {
    if (scl1==NULL|| scl2==NULL)
        return 0;
    else
        return (scl1->info * scl2->info)+scl_dot(scl1->next,scl2->next);
}


void stampa_scl(TipoSCL scl) {
    if (scl==NULL)
        return;
    else {
        printf("%0.0f\n",scl->info);
        return stampa_scl(scl->next);
    }
}
 


TipoSCL crea_scl(int *v,int n) {
    int x=6;
    int pos=x-n;
    
    if (n!=0)
       
    
    {
        TipoSCL scl=(TipoSCL)malloc(sizeof(TipoInfoSCL));
        scl->info=v[pos];
        scl->next=crea_scl(v,n-1);
        return scl;
    }
    return NULL;
}
void rightsum(TipoSCL scl) {
    if (scl==NULL)
        return;
    else
        scl->info=scl_sum(scl);
    rightsum((scl->next));
    
}
/*
void scl_duplicate_pos(TipoSCL scl, int pos) {
   if (scl==NULL)
       return;
   else if (pos==0){
       int *ne=scl->next;
       TipoSCL temp=(TipoSCL)malloc(sizeof(TipoSCL));
       temp->info=scl->info;
       scl->next=temp;
       temp->next=ne;
   }
    scl_duplicate_pos(scl->next,pos-1);
    
}
*/
TipoSCL scl_positives(TipoSCL scl){
    TipoSCL scl2=(TipoSCL)malloc(sizeof(TipoInfoSCL));
    if (scl==NULL)
        return scl2;
    else if (scl->info>0) {
        scl2->info=scl->info;
        scl2->next=scl_positives(scl->next);
        return scl2;
    }
        
    else
        return scl_positives(scl->next);
    
}
void comprimiSCL(TipoSCL* scl){
    if ((*scl)->next==NULL)
        return;
    if ((*scl)->info<(*scl)->next->info){
        (*scl)->info+=(*scl)->next->info;
        TipoNodoSCL *temp=(*scl)->next;
        (*scl)->next=(*scl)->next->next;
        free(temp);
    }
    comprimiSCL(&(*scl)->next);
    return;

}



/*
int rotateList(int** v, TipoSCL src, int num){
    *v=(int*)malloc(sizeof(int*)*scl_len(src));
    int i=0;
    while (src!=NULL){
        if (scl_len(src)==num){
            *v[i]=src->info;
            src=src->next;
            i++;
        }
        src=src->next;
    }
    printf("%d%d\n",*v[0],*v[1]);
}
*/
int cerca_max(TipoSCL *l,int x){
    if (*l==NULL)
        return x;
    if ((*l)->info > x){
        x=cerca_max(&(*l)->next,(*l)->info);
    }
    x=cerca_max(&(*l)->next,x);
    return x;
    
}
int sommaCoda_aux(TipoSCL l);
int sommaCoda_aux(TipoSCL l){
    if (l==NULL)
        return 0;
    else
        return l->info+sommaCoda_aux(l->next);
}
int sommaCoda(TipoSCL l){
    if (l==NULL)
        return 0;
    else
        return sommaCoda_aux(l->next);
    
}
void eliminaTuttiSommaValori(TipoSCL* l){
    if (*l==NULL)
        return;
    else {
        if ((*l)->info < sommaCoda(*l)){
            TipoSCL *aux=l;
            *l=(*l)->next;
            free(aux);
            eliminaTuttiSommaValori(&(*l));
            
        }
        else
            eliminaTuttiSommaValori(&(*l)->next);
            
    }
    
}
TipoSCL merge_elements(TipoSCL l1, TipoSCL l2){
    TipoSCL ris=(TipoSCL)malloc(sizeof(TipoSCL));
    if (l1==NULL && l2==NULL)
        return NULL;
    if (l1==NULL)
        return l2;
                                
    if (l2==NULL)
        return l1;
    else {
        printf("%f %f\n",l1->info,l2->info);
        if (l1->info < l2->info){
            ris->info=l1->info;
            ris->next=merge_elements(l1->next,l2);
            
        }
        if (l1->info > l2->info)
            ris->info=l2->info;
            ris->next=merge_elements(l1,l2->next);
        
    }
    return ris;
}
