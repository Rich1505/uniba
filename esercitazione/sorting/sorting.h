#ifndef SORTING_H
#define SORTING_H
#include<stdlib.h>
#include<stdbool.h>

void bubbleSort(int *arr,size_t size, bool (*op)(int,int));

void selectionSort(int *arr, size_t size, bool (*op)(int,int));

void insertionSort(int *arr, size_t size, bool (*op)(int,int));

bool ascending(int a,int b);
bool descending(int a,int b);

#endif