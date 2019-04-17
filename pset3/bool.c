/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n);
 
int main (void)
{
    printf("Buscas a ");
    int a = get_int();
    int values[] = {0,2 ,3 , 4,5,6 , 7 , 8,9,10 , 12 , 14,16,28};
    int b = 14;
    if ( search(a , values , b) )
    {
        printf("Si\n");
    }
    else
    {
        printf("No\n");
    }
    
}
 
bool search(int value, int values[], int n)
{
    bool m = false;
    int pi = 0, pf = (n - 1), pm = 0;
    pm = round ((pi + pf) / 2);
    
    if ( value == values[pm])
    {
        m = true;
    }
    else
    {
        while ( value != values[ pm ] )
        {
            if ( pi > pf || pf < 0)
            {
                return m;
            }
            else if ( value == values[pm] )
            {
                m = true;
            }
            else if ( value > values[pm] )
            {
                pi = pm + 1;
                pm = round ((pi + pf) / 2);
            }
            else if ( value < values[pm])
            {
                pf = pm - 1;
                pm = round ((pi + pf) / 2);
            }
        }
        if ( value == values[pm] )
            {
                m = true;
            }
    }
    return m;
}


