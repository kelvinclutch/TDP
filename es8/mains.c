#include<stdlib.h>
#include<stdio.h>
#include"insf_scl.h"
#include<stdbool.h>
#include "ins.h"
int main () {
    const int n=4;
    const int n1=7;
    int arr1[n1]={2,4,5,7,6,9,10};
    int arr[n]={1,4,5,6};
    Insieme k=init(arr,n);
    
    Insieme k2=init(arr1,n1);
    Insieme c=intersection(k2,k);
    
    stampains(c);
    //Insieme scopy=copy(k);
    //printf("%d\n",size(k));
    //printf("%d\n",equal(k2,k));
}
