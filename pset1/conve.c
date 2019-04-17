#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    printf("Dame un numero ");
    float n = get_float();
    int cent = round( n * 100);
    printf("Esto es en centavos %i\n", cent);
}