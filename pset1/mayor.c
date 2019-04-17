#include <cs50.h>
#include <stdio.h>
#include <math.h>

float num();

int main(void)
{
    
    float n = num();
    int cent = round( n * 100);
    printf("Esto es en centavos %i\n", cent);
}

float num()
{
    float dol;
    do
    {
        printf("Dolares ");
        dol = get_float();
    }
    while (dol < 0.000001 );
    return dol;
}