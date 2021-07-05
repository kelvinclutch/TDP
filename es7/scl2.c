#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include "scl2.h"
void sclstring_print(TipoSCL s) {
    if (s==NULL)
        return;
    else
        printf("%c\n",s->info);
    sclstring_print(s->next);
}
 

TipoSCL sclstring_create(const char *s) {
    if(*s!='\0') {
        TipoSCL scls=(TipoSCL)malloc(sizeof(TipoInfoSCL));
        scls->info=(char)(*s);
        scls->next=sclstring_create(s+1);
        return scls;
    }
    return NULL;
}
bool sclstring_equals(const TipoSCL scl, const char *s) {
    if (scl==NULL && *s=='\0')
        return true;
    else if (scl->info != *s)
        return false;
    else
        return sclstring_equals(scl->next,s+1);
}
void sclstring_remove(TipoSCL *scl_p, char val) {
   
    if (scl_p==NULL)
        return;
    else if ((*scl_p)->info==val) {
        TipoSCL temp=*scl_p;
        (*scl_p)=(*scl_p)->next;
        
        free(temp);
    }
    else
        sclstring_remove(&((*scl_p)->next),val);
        
    
}


