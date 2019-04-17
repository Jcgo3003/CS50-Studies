#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int mod = get_int();
    printf("mod 10\n");
    int sn = get_int();
    
    if ((mod == 34 || mod == 37) && sn==0  )
    {
        printf("amex\n");
    }
    else if (mod>39 && mod<50 && sn==0 )
    {
        printf("visa\n");
    }
    else if(mod>50 && mod<56 && sn==0 )
    { 
        printf("master\n");
    }
    else
    {
        printf("invalid\n");
    }
}