#include <stdio.h>
#include <cs50.h>

int say(int n); 

int main (void)
{
    printf("Dame un numero ");
    int x = get_int();
    printf("numero n es %i\n", say(x));
}

int say(int n)
{ 
    n = n + 1;
    return n;
}
