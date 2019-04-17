#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (void)
{
    long long n = get_long_long();
    if (  n > (pow(10,12)-1) && n < pow(10,13)  )
    {
        printf("13\n");
    }
    
    else if ( n > (pow(10,14)-1) && n < pow(10,16) )
    {
        printf("15 o 16\n");
    }
    else if ( n < pow(10,12) )
    {
        printf("INVALID\n");
    }
    else if (  n > pow(10,16)-1)
    {
        printf("INVALID\n");
    }
    else if ( n > pow(10,13)-1 && n < pow(10,14) )
    {
        printf("INVALID\n");
    }
}
