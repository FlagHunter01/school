#include <stdio.h>

void exercice6(int *a, int *b)
{
    int buffer = *a;
    *a = *b;
    *b = buffer;
}