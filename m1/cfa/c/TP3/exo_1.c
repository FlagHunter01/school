#include <stdio.h>

void exercice1()
{
    int a, b, c;
    for (a = 0; a <= 9; a++)
    {
        for (b = 0; b <= 9; b++)
        {
            for (c = 0; c <= 9; c++)
            {
                if (a < b && b < c)
                {
                    printf("%03d%03d%03d, ", a, b, c);
                }
            }
        }
    }
    printf("\n");
}
