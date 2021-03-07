#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void test(int n, int m, int arr[])
{
    int iterator;

    for(iterator =1; iterator<=n+1; iterator++)
    {
        assert(arr[iterator] - arr[iterator-1]<= m);
        assert(arr[iterator]!=arr[iterator-1]);
        assert(arr[iterator] > arr[iterator-1]);
    }
}

int rand_range(int n)  // FUNCTIA CE GENEREAZA VALORI RANDOM MAI MARI DECAT RAND_MAX
{

    unsigned int x;
    x = rand();
    x <<= 15;
    x^= rand();
    x %= n;

    return x;
}
