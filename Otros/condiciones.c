#include <stdio.h>
#include <cs50.h>

int main (void)
{
    printf("Dame un numero ");
    int n = get_int();
    if (n > 25)
    { 
        printf("Es mayor de 25\n");
        n = n-1;
    }
    else if (n > 10 && n < 24)
    { 
        printf("Es mayor que 10 pero menor que 24\n");
        n = n-15;
    }
    else if (n > 5 && n < 9)
    { 
        printf("Es mayor que 5 pero menor que 10\n");
        n = 5;
    }
    else if (n > 4 )
    { 
        printf("Es mayor que 4 te queda %i\n", n);
        
    }
   
    
}