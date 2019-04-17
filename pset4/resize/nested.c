#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(void)// here's the arrays where the game must be saved
{
    //int board [d] [d];
    printf("Dame un numero ");
    int d = get_int();
    printf("Cuantas verces repitos la lineas ");
    int n = get_int();
    // int siz = ( d * d );    // Will count the tile's numbers
    
    for ( int i = 0; i < d; i++)  //Al llegar a 4 se parara no hara nada mas, llega a 3 y se acabo
    {
        printf("%i",i);
        
        for ( int j = 0; j < d; j++)
        {
            ////cuando j llegue a su limite quiero que regrese a 0 un numero n verces como hacerlo
            while (n > 0 )
            {
            printf(" %i", j);
                
                if (j < d)
                {
                    j = 0;
                    n--;
                }
            }
        
        }
            // siz--;
            // board [i] [j] = siz;
    printf("\n");    
    }
        

    
    
    
}