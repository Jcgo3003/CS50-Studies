#include <cs50.h>
#include <stdio.h>

int num();

int main (void)
{ 
    int alt = num();
    for( int i = 0; i < alt; i++)
    {
        for( int a = 0; a <  (alt - (i + 1)); a++)
        {
            printf(" ");
        }
        for (int b = 0; b < (i + 2); b++)
        {
            printf("#");
        }
        printf("\n");
    }
    
}

int num(void)
{
    
    int n;
    do 
    {
        printf("Height ");
        n = get_int();
    }
    while (n < 0 || n > 23);
    return n;
}