#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int main (int argc, string argv[])
{
    argc = 0;
    
    int d = atoi ( argv[1] );
    int tam = ( d * d );
    
    int i = 0, j = 0;
    int board [d] [d];
    
    for ( i = 0; i < d; i++)    //Line 0 the top one
    {
        // printf(" %i   ", i);
        for ( j = 0; j < d; j++)
        {
            tam--;
            board [i] [j] = tam;
            // printf(" %i", j);
            // printf(" %i ", tam );
        }
        // printf("\n");
    }
    
    if ( d %2 == 0)//Checking is d is even
    {
        // printf("Es par\n");
        board [d-1] [d-2] = 2;
        board [d-1] [d-3] = 1;
    }
    for ( i = 0; i < d; i++)    //Line 0 the top one
    {
        for ( j = 0; j < d; j++)
        {
            printf(" %i ", board [i] [j]);
        }
        printf("\n");
    }
    
}