#include <stdio.h>
#include <stdlib.h>

void algorithm_1(int n, int m, int gas_station[], int case_number)
{
    FILE* out = fopen("data.out", "a");

    int  destination, iterator, station_number, distance, refill, last_station;

    int skip_case = 0;

    int* count = (int*)malloc(n*sizeof(int));

    destination = gas_station[n+1]; //destinatia

    last_station = gas_station[0]; // ultima statie, pornind de la origine( i.e 0 )

    station_number = 0; //indicele statiei

    refill = 0; // numarul de opriri pe care le-a realizat soferul


    for(iterator =1; iterator<=n+1; iterator++)
    {
        if((gas_station[iterator] - gas_station[iterator-1])>m) // CAZUL IN CARE BENZINARIILE SUNT LA DISTANTE PREA MARI
        {
            fprintf(out,"TESTUL: %d metoda 1\n", case_number);
            fprintf(out,"\nSoferul nu poate sa isi completeze traseul\n");
            skip_case = 1;
        }
    }


    if(skip_case == 0)
    {
        while(station_number <= n)
        {

            distance = 0; // distanta pe care o parcurgem de la ultima alimentare

            while( distance < m && station_number <= n) // ne deplasamm ( i.e distanta parcursa creste ) atat timp cat distanta este mai mica ca m si cat timp nu am ajuns la destinatie
            {
                if((distance >= (gas_station[station_number] - last_station)) && ((m - distance)>=(gas_station[station_number+1]-gas_station[station_number])))
                {
                    station_number++; // daca putem ajunge la statia urmatoare atunci crestem numarul statiei
                }
                distance++;
            }

            last_station = gas_station[station_number]; // memoram pozitia ultimei statii unde am alimentat

            if(station_number <= n)
            {
                count[refill++] = station_number ; // memoram indicele statiei unde am alimentat
                station_number++;
            }

        }

        fprintf(out,"TESTUL: %d metoda 1\n", case_number);
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
