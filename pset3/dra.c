#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int main (void)
{
    printf("Dame un numero ");
    int n = get_int();
    
    for ( int i = 0; i < n; i++)    
    {
        if (i == 5)
        {
            printf(" _ ");
        }
        else
        {
            printf(" %i ", i);
        }
    }
    printf("\n");
}