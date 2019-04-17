#include <cs50.h>
#include <stdio.h>

int main (void)
{
    printf("Dame un numero ");
    int n = get_int();
    
    while (n > 25)
    { 
        printf("N es mayor que 25 esto es ahora %i\n",n);
        n = n - 1;
    }
    printf("n queda al final de etapa 1 %i\n", n);
    
    while (n > 20)
    { 
        printf("N es mayor que 20 esto es ahora %i\n",n);
        n = n - 1;
    }
    
    printf("n queda al final de etapa 2 %i\n", n);
    
    while (n > 15)
    { 
        printf("N es mayor que 15 esto es ahora %i\n",n);
        n = n - 1;
    }
    
    printf("n queda al final de etapa 3 %i\n", n);
}
