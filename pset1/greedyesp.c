#include <cs50.h>
#include <stdio.h>
#include <math.h>

float num();

int main(void)
{
    
    float n = num();
    int cents = round( n * 100);  ///En centavos 
    int coins = 0;   ///Declaro la variable coins que sera utlz como cambio
    
    while(cents  > 24 )
    {
    coins = cents / 25; ///coins lleva la suma
    cents = cents % 25; //cents lleva el cambio
    }

    while (cents > 9 )///mientras cents sea menos que 24 y mas que 9//Listo!!!! no mover
    {
    coins = coins + (cents / 10);// coins lleva la suma de las monedas que voy utilizado
    cents = cents % 10;// cents - centavos mod con eso tengo el cambio    
    }

    while (cents > 4 )///mientras cents sea menos que 24 y mas que 9//Listo!!!! no mover
    {
    coins = coins + (cents / 5);// coins lleva la suma de las monedas que voy utilizado
    cents = cents % 5;// cents - centavos mod con eso tengo el cambio    
    }

    while (cents > 0 )///mientras cents sea menos que 24 y mas que 9//Listo!!!! no mover
    {
    coins = coins + (cents / 1);// coins lleva la suma de las monedas que voy utilizado
    cents = cents % 1;// cents - centavos mod con eso tengo el cambio    
    }
    printf("%i\n", coins);
    
    
}

float num()
{
    float dol;
    do
    {
        printf("O hai! How much change is owed? ");
        dol = get_float();
    }
    while (dol < 0.000001 );
    return dol;
}