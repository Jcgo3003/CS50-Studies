#include <cs50.h>
#include <stdio.h>
#include <math.h>

//bool search(int value, int values[], int n)
int main (void)
{
    printf("Cual es el # que buscas ");
    int value = get_int();
    int ar[] = { 0, 2 ,3 , 4,5,6 , 7 , 8,9,10 , 12 , 14,16,28};
    ////////////0 1  2   3 4 5   6   7 8 9    10   11 12 13
    int n = 14;// tamano del arreglo
    int pi = 0, pf = (n - 1), pm = 0;
    
    pm = round ((pi + pf) / 2);
    // printf("PM %i\n", pm);
    // printf("ar pm %i\n", ar [pm]);
    
    if ( value == ar[pm])
    {
        printf("Si esta\n");
        return true;
    }
    else //if ( value != ar[pm])
    {
       
        while ( value != ar [ pm ] )
        {
            
            if (  pf < 0)
            {
                printf("No esta por pf < 0\n");
                return false;
            }
            
            if ( pi > pf )
            {
                printf("No esta por pi > pf\n");
                return false;
            }
            
            if ( value == ar[pm] )
            {
                printf("Si esta\n");
                return true;
            }
            
            if ( value > ar[pm] )
            {
                printf("derecha\n");
                pi = pm + 1;
                pm = round ((pi + pf) / 2);
            }
            
            if ( value < ar [pm])
            {
                printf("izquierda\n");
                pf = pm - 1;
                pm = round ((pi + pf) / 2);
            }
            
        }
        
        if ( value == ar[pm] )
            {
                printf("Si esta\n");
                return true;
            }
        
    }
    
}