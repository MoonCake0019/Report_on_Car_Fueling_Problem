#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include "utility.h"
#include "sorting_algorithms.h"

#define FUEL 700  // maximul de km pe care se poate deplasa masina fara sa opreasca

#define MAX 1000000   //distanta maxima la care se poate deplase masina


void random_generator(int no_test)
{
    FILE* out = fopen("data.in", "a");

    srand(time(NULL));
    int n; //numarul de benzinarii
    int m;  //numarul de km pe care se poate deplasa masina fara oprire
    int n_must_fill;
    int iterator;
    int destination;
    int case_numeber;

    for(case_numeber=0; case_numeber<no_test; case_numeber++)
    {
        /* masina se poate deplasa pe o distanta de cel putin 400 km
        si cel mult FUEL km*/
        m = 400 + rand_range(FUEL- 400 + 1);

        /* destinatia se alfa la cel putin 1000 km departare
            si la maxim MAX km departare*/
        destination  = 600 + m + rand_range(MAX - (600 + m) + 1);

        /* sunt cel putin n_must_fill benzinarii la care trebuie sa opreasca
           si cel mult destination/10 + n_must_fill benzinarii optionale*/
        n_must_fill = ceil((double)destination/m);

        n = n_must_fill + rand_range(destination/10);

        int* arr = (int*)calloc(n+2,sizeof(int));

        arr[0] = 0;
        arr[n+1] = destination;

        int* is_used= (int*)calloc(destination, sizeof(int)); //memoram variabilele ce au fost deja folosite
        is_used[arr[0]]=1;

        int r_value;

        for( iterator =1 ;   iterator <= n; iterator++)
        {

            r_value = arr[iterator-1] + m - rand()%100; // cream benzinariile sigure la care trebuie sa opreasca soferul

            if(r_value < destination && is_used[r_value] == 0)
            {
                arr[iterator] = r_value;
                is_used[r_value] = 1;

            }
            else
            {
                while(1)
                {
                    r_value = 1 +  rand_range(destination-1);   // daca am generat toate benzinariile sigure atunci generam benzinarii optionale
                    if(!is_used[r_value])      // daca valoarea nu a mai fost memorata atunci o folosim
                    {
                        break;
                    }
                }

                arr[iterator] = r_value;
                is_used[r_value] = 1;
            }
        }

        mergeSort(arr, 0, n+1);

        n = n - 1;

        test(n, m, arr); // Testam daca datele sunt relevante

        fprintf(out,"%d\n", n);

        fprintf(out,"%d\n", m);

        for(iterator=0; iterator<n+2; iterator++)
        {
            fprintf(out,"%d\n", arr[iterator]);
        }

        free(is_used);
        free(arr);

    }

    fclose(out);

}
