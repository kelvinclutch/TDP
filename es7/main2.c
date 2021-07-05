#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include "scl2.h"
int main () {
    const char *s2="defoltz";
    TipoSCL ss2=sclstring_create(s2);
    
    const char *s1 ="defoltz";
    printf("%d\n",sclstring_equals(ss2,s1));
    sclstring_remove(&ss2,'e');
    sclstring_print(ss2);
}
