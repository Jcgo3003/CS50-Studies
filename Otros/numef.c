#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main (void)
{
    printf("Credit card ");
    long long n = get_long_long();
    while ( n > (pow(10,12)-1) && n < pow(10,13) ) || ( n > (pow(10,14)-1) && n < pow(10,16) )
    {
        printf("Numero ACEPTADO\n");
        n = n * -1;
    }
}
// Ejemplo de validacion de credito inicial