#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main (void)
{
        
          int n = 4;
        int c = 0, r =0;
        int loc[] = {0,4,5,9};
        
        while (n-1 > 0)
        {
                
                
                // printf(" # veces %i", c);///para saber numero de veces que se ejecuta
                c ++; /// c = 1 
                r ++; ///r = 1
                printf("loc [%i] = %i ", c, loc[c]);
                
                while ( loc[c] != r )/// mientras esto sea verdadero loc [1]  diferente de r = 1
                {
                        
                        printf("%i\n",  loc[c-1] + 1 );/// imprimes (loc [1-1] +1)
                        r = loc [c];     /// r = lo[1]     r = 4
                }///ahora r puede continuar porque  loc [1] = r  4 = 4  
                //printf(" loc %i",loc[c]);
                
                n = n - 1;///a n restale 1
        }
        
        
        // printf("\n");
        // printf("n %i\n",n);
        // printf("c %i\n",c);
        // printf("r %i\n",r);
}
        