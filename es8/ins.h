#include<stdlib.h>
#include<stdio.h>
#include"insf_scl.h"
#include<stdbool.h>

Insieme init(int *arr, int n);
void stampains(Insieme T);
Insieme copy(Insieme s);
int size(Insieme s);
bool subset(Insieme a, Insieme b);
bool equal(Insieme a, Insieme b);
Insieme intersection(Insieme a, Insieme b);
Insieme unionn(Insieme a, Insieme b);
void stampains_aux(IteratoreInsieme it);
Insieme intersection_aux(IteratoreInsieme it,Insieme b,Insieme c);
