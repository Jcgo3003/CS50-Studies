#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int a = 0, b = 0, c = 0, n = 7, i = 0, j = 0;
    int ar[]={0,4,2,5,6,87,23};
    
    
    while ( j <= n - 2)
    {
    //printf("j es %i\n", j);
        a = ar[j];
        i = j;
        b = j;
        while ( i <= (n - 1))
        {
            
            while( a > ar[i] )
            {
                b = i;/// el es el problema if ( a > ar[i] ) si no encuentra ningun numero entonces b seria j para evitar lo que pasa
                a = ar[i];// como hacer que i se quede en la casilla  y no cambie cuando el numero de la misma casilla es menor y
            }               // este programa no se ejecuta
            i++;
        }
        c = ar[j];// c guarda el # de la casilla j 
        ar[j] = a;// ar[j] cambia por # menor
        ar[b] = c;// sera el # que estaba en casilla j
    
        j++;
    //     for( int z = 0; z < n; z++)
    //     {
    //         printf("%i\n", ar[z]);
    //     }
    // printf("i es %i\n", b);
    // printf("El numero menor es %i\n", a);
    // //printf("i es %i\n", b);
    // printf("\n");
    }
    
    for( int z = 0; z < n; z++)
    {
        printf("%i\n", ar[z]);
    }
}