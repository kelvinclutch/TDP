//
//  main.c
//  
//
//  Created by Paolo Cupini on 09/04/21.
//

#include <stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include <string.h>
#include "es6.h"

int main () {
    const int n=5;
    int v[n]= {4,1,2,3,4};
    int i=0;
    //printf("%d\n",product(v,n,i));
    vec_integral(v,n);
    for (int k=0;k<n;k++) printf("%d\n",v[k]);

   char *s="caIo beLlo";
    //printf("%d\n",length(s,i));
   // char ch='a';
   // printf("%d\n",char_position(s,ch,i));
    //printf("%d\n",is_lowercase(s,i));
    to_uppercase(s,i);
    char scopy[256];
    //copy(scopy,s,i);
    
    char dest[256]="dDJ807efolt                       ";
   // concat(dest,s,i);
   // int z=0;
  //  while (z!=strlen(z)) {
    //    printf("%c\n",dest[z]);
    //    z++;
  //  }
    
    FILE *f=fopen("bellazi","w+");
    if (f==NULL){
        printf("errore");
        exit(1);
    }
    filter_write(dest,f,i);
    FILE *g=fopen("gang","w+");
    filter_write(dest,g,i);
    same_content(f,g);
}


   
   
