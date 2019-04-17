#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (void)// here's the arrays where the game must be saved
{
    printf("Dame un numero ");
    int d = get_int();
    
    int siz = ( d * d );    // Will count the tile's numbers
    int board [d] [d];
    
    for ( int i = 0; i < d; i++)  // Making the array 
    {
        for ( int j = 0; j < d; j++)
        {
            siz--;
            board [i] [j] = siz;
        }
    }
    
    if ( d %2 == 0)//Checking is d is even
    {
        board [d-1] [d-2] = 2;
        board [d-1] [d-3] = 1;
    
    }
    
    printf("\n");
    for ( int i = 0; i < d; i++)    
    {
        for ( int j = 0; j < d; j++)
        {
            if ( board [i] [j] == 0)
            {
                printf("|  _  ");
            }
            else
            {
                printf("| %2i  ", board [i] [j]);
            }
        }
        printf("|");
        printf("\n");
        printf("\n");
    }
    
    
    
    
    printf("Seleciona un numero ");
    int sel = get_int();
    
    if (sel > (d *d) -1)//making sure that the number exist in the array
    {
        printf("Numero no existe\n");
    }
    
    else
    {
    int sel_i = 0, sel_j = 0;
    int zero = 0;
    int zero_i = 0, zero_j = 0;
    
    for ( int i = 0; i < d; i++)    
    {
        for ( int j = 0; j < d; j++)
        {
            if ( sel == board [i] [j])
            {
                sel_i = i;
                sel_j = j;
                printf("Tu numero esta en i %i j %i\n", sel_i , sel_j );
            }
            else if (  zero == board [i] [j])
            {
                zero_i = i;
                zero_j = j;
                printf("Cero esta en i %i j %i\n", zero_i , zero_j);
            }
            // else
            // {
            //     printf("Numero no exite\n");
            // }
            
        }
       
    }
    ///I know where the number selecte is and zero is 
    // now i need to know make the machine know if is a legal move
    
    if ( sel_i == zero_i && ( sel_j == (zero_j + 1) || sel_j == (zero_j - 1) ) )//movement in colomns 
    {
        printf("Movimiento legal\n");
        board [zero_i] [zero_j] = board [sel_i] [sel_j];//swichting the seletion for 0
        board [sel_i] [sel_j] = 0;//Seting 0 to the place where it used to be the selection 
    }
    else if ( ( sel_i == (zero_i + 1) || sel_i == (zero_i - 1) ) && sel_j == zero_j )//movement in rows
    {
        board [zero_i] [zero_j] = board [sel_i] [sel_j];
        board [sel_i] [sel_j] = 0;
        printf("Movimiento legal\n");
    }
    else 
    {
        printf("Movimiento no legal\n");
    }
    
    }
    
    printf("\n");
    for ( int i = 0; i < d; i++)    
    {
        for ( int j = 0; j < d; j++)
        {
            if ( board [i] [j] == 0)
            {
                printf("|  _  ");
            }
            else
            {
                printf("| %2i  ", board [i] [j]);
            }
        }
        printf("|");
        printf("\n");
        printf("\n");
    }
}