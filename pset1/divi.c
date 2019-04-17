#include <cs50.h>
#include <stdio.h>

int main (void)
{
    printf("Dame un numero ");
    int n = get_int();
    int m = n / 10;
    printf("Este es el numero dividido entre 10 es %i\n", m);
}
    