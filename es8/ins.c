#include<stdlib.h>
#include<stdio.h>
#include"insf_scl.h"
#include<stdbool.h>
#include "ins.h"
/*
Insieme init(int *arr, int n) {
    Insieme k=insiemeVuoto();
    for (int i=0;i<n;i++) {
        if (!membro(k,arr[i]))
            k=inserisci(k,arr[i]);
    }
    return k;
}
 */
Insieme init(int *arr,int n) {
    
    if (n==0)
        return insiemeVuoto();
    
    
    Insieme k=init(arr+1,n-1);
    return inserisci(k,*arr);
    
    
}
void stampains_aux(IteratoreInsieme it) {
    if (!hasNext(it)) return;
    printf("%d\n",next(it));
    stampains_aux(it);
}
void stampains(Insieme T) {
    
    stampains_aux(creaIteratoreInsieme(T));
}

/*
Insieme copy(Insieme s) {
    Insieme scopy=insiemeVuoto();
    IteratoreInsieme it=creaIteratoreInsieme(s);
    while (hasNext(it)) {
        scopy=inserisci(scopy,next(it));
    }
    return scopy;
}
 */
int size(Insieme s) {
    int cont=0;
    IteratoreInsieme it=creaIteratoreInsieme(s);
    while (hasNext(it)) {
        cont++;
        next(it);
    }
    return cont;
}
/*
bool subset(Insieme a, Insieme b) {
    IteratoreInsieme it=creaIteratoreInsieme(a);
    if (size(a)<=size(b)) {
        while (hasNext(it)) {
            if (!membro(b,next(it)))
                return false;
        
    }
        return true;
    }
        return false;
}
bool equal(Insieme a, Insieme b) {
    if (size(a)==size(b)) {
        IteratoreInsieme it =creaIteratoreInsieme(a);
        IteratoreInsieme it1=creaIteratoreInsieme(b);
        while (hasNext(it) && hasNext(it1)) {
            if (next(it)!=next(it1))
                return false;
        }
                return true;
            
    }
    return false;
}
Insieme intersection(Insieme a, Insieme b) {
    
    Insieme c=insiemeVuoto();
    
    IteratoreInsieme it = creaIteratoreInsieme(b);
    while (hasNext(it)) {
        if (membro(b,next(it)))
            c=inserisci(c,next(it));
    }
    return c;
}
*/
Insieme intersection(Insieme a, Insieme b) {
    
    IteratoreInsieme it=creaIteratoreInsieme(a);
    Insieme c=intersection_aux(it,b,c);
    return c;
    
    
}
Insieme intersection_aux(IteratoreInsieme it,Insieme b,Insieme c) {
    if (!hasNext(it))
        return insiemeVuoto();
    int val=next(it);
    if (membro(b,val))
        c=inserisci(c,val);
    intersection_aux(it,b,c);
    
    
    return c;
        
    
             
}
