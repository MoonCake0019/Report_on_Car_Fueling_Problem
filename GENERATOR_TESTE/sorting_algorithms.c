#include <stdio.h>
#include <stdlib.h>
#include "sorting_algorithms.h"


void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {

        int middle = left+(right-left)/2;

        // sortam primul si al doilea vector
        mergeSort(arr, left, middle);
        mergeSort(arr, middle+1, right);
        //merge
        merge(arr, left, middle, right);
    }
}

void merge(int arr[], int left, int middle, int right)
{
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 =  right - middle;


    int* L = (int*)malloc(n1*sizeof(int));
    int* R = (int*)malloc(n2*sizeof(int));


    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[middle + 1+ j];

    i = 0;      // indexul initial al primului vector
    j = 0;      // indexul initial celui de al doilea vector
    k = left;   // indexul initial vectorului unit

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copiem elementele ramase din L[]*/
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copiem elementele ramase din R[]*/
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


