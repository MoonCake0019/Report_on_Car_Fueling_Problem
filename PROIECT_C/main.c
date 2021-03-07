#include <stdio.h>
#include <stdlib.h>
#include "algorithms.h"

int main()
{

    int no_test;
    int case_number;
    FILE* out = fopen("data.out", "w");
    fclose(out);
    FILE* in = fopen("C:\\Users\\ASUS\\Desktop\\P1\\GENERATOR_TESTE\\data.in", "r");

    fscanf(in, "%d", &no_test);

    for(case_number = 1; case_number <= no_test; case_number ++)
    {

        int n,m, iterator;

        fscanf(in, "%d", &n);
        fscanf(in, "%d", &m);

        int* gas_station = (int*)malloc((n+2)*sizeof(int));

        for(iterator =0; iterator< n+2; iterator++)
        {
            fscanf(in, "%d", &gas_station[iterator]);
        }

        //rulam prima metoda de rezolvare a problemei
        algorithm_1(n, m, gas_station, case_number);
        //rulam a doua metoda de rezolvare a problemei
        algorithm_2(n, m, gas_station, case_number);

        free(gas_station);
    }

    fclose(in);

    return 0;
}
