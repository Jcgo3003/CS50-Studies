#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int main (int argc, string argv[])
{
    
    int tam = ( d * d );
    int i = 0, j = 0;
    int board [d] [d];
    
    for ( i = 0; i < d; i++)   
    {
        for ( j = 0; j < d; j++)
        {
            tam--;
            board [i] [j] = tam;
        }
    }
    
    if ( d %2 == 0)//Checking is d is even
    {
        board [d-1] [d-2] = 2;
        board [d-1] [d-3] = 1;
    }
}