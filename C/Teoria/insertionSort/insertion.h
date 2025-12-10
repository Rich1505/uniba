#ifndef INSERTION_H
#define INSERTION_H
#include<stdio.h>

void insertionSort(int vettore[], size_t dimensione, int(*op)(int,int));
int ascending(int a,int b);
int descending(int a,int b);

#endif