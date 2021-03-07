#include <stdio.h>
#include <stdlib.h>
#include "test_generator.h"


int main()
{
    FILE* out = fopen("data.in", "w");
    int no_test;

    printf("introduceti numarul de teste pe care vreti sa le creati:");
    scanf("%d", &no_test);

    fprintf(out, "%d\n", no_test);
    fclose(out);

    random_generator(no_test);

    return 0;
}
