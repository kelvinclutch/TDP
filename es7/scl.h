
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef float TipoInfoSCL; struct ElemSCL {
TipoInfoSCL info;
struct ElemSCL *next; };
typedef struct ElemSCL TipoNodoSCL; typedef TipoNodoSCL * TipoSCL;

int scl_len(TipoSCL scl);
int scl_sum(TipoSCL scl);
float scl_media(TipoSCL scl);
float scl_dot(TipoSCL scl1, TipoSCL scl2);
TipoSCL crea_scl(int *v,int n);
void scl_duplicate_pos(TipoSCL scl, int pos);
void stampa_scl(TipoSCL scl);
TipoSCL scl_positives(TipoSCL scl);
void rightsum(TipoSCL scl);
float scl_media_aux(TipoSCL scl,int n,int somma);
void comprimiSCL(TipoSCL* scl);
TipoSCL merge_elements(TipoSCL l1, TipoSCL l2);
int sommaCoda(TipoSCL l);
void eliminaTuttiSommaValori(TipoSCL* l);
int rotateList(int** v, TipoSCL src, int num);
int cerca_max(TipoSCL *l,int x);
void inserisciMassimo(TipoSCL* l);
void anteponiMassimo(TipoSCL* l);
TipoSCL *erase(TipoSCL *scl, int index);
