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
    
    
    
    
    
    
    
    
    printf("seciona un numero ");
    int tile = get_int();
    
    bool tiles = false;
    
    int tile_i = 0, tile_j = 0;//This will keep track of the 'tile'
    int zero = 0, zero_i = 0, zero_j = 0;//This will keep track of '0'
    
    if (tile > (d *d) -1)//making sure that the selected number exist in the array
    {
        return tiles;
    }
    
    else///looking for the numbers
    {
        for ( int i = 0; i < d; i++)//Looking for the 'selection' and '0'    
        {
            for ( int j = 0; j < d; j++)
            {
                if ( tile == board [i] [j])//Looking for the tile
                {
                    tile_i = i;
                    tile_j = j;
                }
                else if (  zero == board [i] [j])//Looking for 0
                {
                    zero_i = i;
                    zero_j = j;
                }
            }
        }
    }
    
    ///moving the tile
    if ( tile_i == zero_i && ( tile_j == (zero_j + 1) || tile_j == (zero_j - 1) ) )//movement in colomns 
    {
        board [zero_i] [zero_j] = board [tile_i] [tile_j];//swichting the tileetion for 0
        board [tile_i] [tile_j] = 0;//Seting 0 to the place where it used to be the tileection 
        tiles = true;
    }
    else if ( ( tile_i == (zero_i + 1) || tile_i == (zero_i - 1) ) && tile_j == zero_j )//movement in rows
    {
        board [zero_i] [zero_j] = board [tile_i] [tile_j];
        board [tile_i] [tile_j] = 0;
        tiles = true;
    }
    else 
    {
        return tiles;
    }
    
    return tiles;
}