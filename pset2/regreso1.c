#include <cs50.h>
#include <stdio.h>

int mult(int n);

int main (void)
{
    printf("Dame un numero ");
    int x = get_int();
    printf("Esto es lo que sale %i\n",mult(x));
}

int mult(int n)
{ 
     n = n * n;
    return n;
}