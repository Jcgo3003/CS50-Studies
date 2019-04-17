#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (void)
{
    long long n = get_long_long();
    if ( n < pow(10,2) )
    {
        printf("INVALID\n");
    }
    else if ( n > (pow(10,2)-1) && n < pow(10,3)  )
    {
        printf("1 Entre 100 y 999\n");
    }
    else if ( n > pow(10,3)-1 && n < pow(10,4)) 
    {
        printf("INVALID  Entre 1000 y 9999\n");
    }
    
    
    
    else if ( n > (pow(10,4)-1) && n < pow(10,5) )
    {
        printf("2 Entre 10000 y 99999\n");
    }
    
    
    else if ( n > (pow(10,5)-1) && n < pow(10,6) )
    {
        printf("3 Entre 100000 y 999999\n");
    }
    
    
    
    else if (  n > pow(10,6)-1)//// cuando sea mayor que 10 a la 5 100000
    {
        printf("INVALID mayor que 1000000\n");
    }
    
}
