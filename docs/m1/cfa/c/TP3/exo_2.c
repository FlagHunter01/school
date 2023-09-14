#include <stdio.h>

void exercice2()
{
    for (int a = 0; a < 100; a++)
    {
        for (int b = a + 1; b < 100; b++)
        printf("%02d %02d, ", a, b);
    }
    printf("\n");
}