//
//  es6.c
//  
//
//  Created by Paolo Cupini on 09/04/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include<string.h>
#include "es6.h"
int product(int vec[], int n,int i) {
    
    int fin;
    fin = vec[i];
    
    if (vec[i]==vec[n])
        return 1;
    else
        return vec[i]*product(vec,n,i+1);

}
void vec_integral(int* v, int n){
    
    if (n==0)
        return ;
    else
        v[n]=v[n]+sommaelementi(v,n);
        
    
    
        
    vec_integral(v,n-1);
    
    
}
int sommaelementi(int*v,int n){
    
    int somma=0;
    if (n==0)
        return 0;
    else {
        while (n!=0) {
            somma+=v[n];
            n--;
        }
    }
    
    
    
    return somma;
    
    
    
}
int length(char * s,int i) {
    if (s[i]=='\0')
        return 1;
    else
        return 1+length(s,i+1);
    
}
int char_position(char* s, char ch,int i) {
    if (s[i]=='\0')
        return -1;
    else if (s[i]==ch)
        return i;
    else
        return char_position(s,ch,i+1);
}
bool is_lowercase(char *s,int i) {
    if (s[i]=='\0')
        return true;
    else if (isupper(s[i]))
        return false;
    else
        return is_lowercase(s,i+1);
}
void to_uppercase(char *s,int i) {
    char c=s[i];
    
    if (c=='\0')
        return ;
    else c=toupper(c);
    
    to_uppercase(s,i+1);
    
}
void copy(char * dest, char * src,int i) {
    char c=src[i];
    if (c=='\0')
        return;
    else
        dest[i]=c;
    
    printf("%c\n",dest[i]);
    copy(dest,src,i+1);
}

void concat(char*dest,char*src,int i) {
    
    if (src[i]=='\0')
        return;
    else
        dest[i+strlen(dest)]=src[i];
    printf("%c\n",src[i]);
    concat(dest,src,i+1);
    
}
void filter_write(char * message, FILE * file,int i) {
    
    if (message[i]=='\0')
        return;
    else {
        if (islower(message[i]) && isalpha(message[i]))
            fputc(message[i],file);
        
        }
    filter_write(message,file,i+1);
        
    
}
bool same_content(FILE *f1, FILE *f2) {
    char c[256];
    while(fscanf(f1,"%s",c)!=EOF) {
        printf("%s\n",c);
    }
        
}

