#include <stdio.h>
#include <stdlib.h>

void algorithm_2(int n, int m, int gas_station[], int case_number)
{
    FILE* out = fopen("data.out", "a");

    int iterator, destination, refill, station_number, last_station;

    int skip_case = 0;

    int* count = (int*)malloc(n*sizeof(int));

    destination = gas_station[n+1]; //destinatia

    station_number = 0; //indicele statiei

    refill = 0; // numarul de opriri pe care le-a realizat soferul



    for(iterator =1; iterator<=n+1; iterator++)
    {
        if((gas_station[iterator] - gas_station[iterator-1])>m)  // CAZUL IN CARE BENZINARIILE SUNT LA DISTANTE PREA MARI
        {
            fprintf(out,"TESTUL: %d metoda 2\n", case_number);
            fprintf(out,"\nSoferul nu poate sa isi completeze traseul\n");
            skip_case = 1; // DACA SE INTAMPLA CA STATIILE SA FIE POZITIONATE LA DISTANTE PREA MARI ATUNCI SE VA SARI CAZUL DE FATA
        }
    }

    if(skip_case == 0)
    {
        while(station_number <= n)
        {
            last_station  = station_number; // indicele ultimei statii unde am oprit pornind de la origine ( i.e 0 )

            while((station_number <= n) && (gas_station[station_number + 1] - gas_station[last_station])<=m) // crestem numarul statiei atat timp cat distanta dintre statia precedenta si urmatoarea e mai mica ca m si nu ajungem la destinatie
            {
                station_number++;
            }

            if(station_number <= n)
            {
                count[refill++] = station_number; // memoram indicele statiei unde am alimentat
            }

        }


        fprintf(out,"TESTUL: %d metoda 2\n", case_number);
        fprintf(out,"Soferul masinii vrea sa parcurga o distanta de :%d km\n", destination);
        fprintf(out,"Cu un plin masina poate sa se deplaseze pe o distanta de %d km\n", m);
        fprintf(out,"Pentru a avea un consum optim soferul trebuie sa opreasca de: %d ori\n", refill);
        fprintf(out,"Pentru a alimenta acesta va oprii la benzinariile cu numarul : ");

        for(iterator =0; iterator<refill; iterator++)
        {
            fprintf(out,"%d  ", count[iterator]);
        }

        fprintf(out,"\n\n");

    }

    fclose(out);
    free(count);
}
