#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
typedef char TipoInfoSCL; struct ElemSCL {
TipoInfoSCL info;
struct ElemSCL *next; };
typedef struct ElemSCL TipoNodoSCL; typedef TipoNodoSCL * TipoSCL;


void sclstring_print(TipoSCL s);

TipoSCL sclstring_create(const char *s);

bool sclstring_equals(const TipoSCL scl, const char *s);

void sclstring_remove(TipoSCL *scl_p, char val);





