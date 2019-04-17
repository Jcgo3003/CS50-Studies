#include <cs50.h>
#include <stdio.h>

int main (void)
{
    printf("Dame un numero ");
    long long n = get_long_long();
    while ( n > 2 && n <6 )
    {
        printf("Numero de 13 cifr\n");
        n --;
    }
}