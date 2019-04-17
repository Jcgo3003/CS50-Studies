#include <cs50.h>
#include <stdio.h>

int main (void)
{
    printf("Damme un numero ");
    int n = get_int();
    printf("El mod10 de n = %i\n",n % 10);
}
    