#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int main (int argc, string argv[])
{
    argc = 0;
    int d = atoi ( argv[1] );
    
    
    int tam = ( d * d );
    int i = 0, j = 0;
    int board [d] [d];
    
    for ( i = 0; i < d; i++)   
    {
        for ( j = 0; j < d; j++)
        {
            tam--;
            board [i] [j] = tam;
        }
    }
    
    if ( d %2 == 0)//Checking is d is even
    {
        board [d-1] [d-2] = 2;
        board [d-1] [d-3] = 1;
    }
    
    
    
    
    
    bool check = true;
    ///////Making the board to compare to
    int tam_w = 0;//Counting the numbers in the array
    
    // int i = 0, j = 0;
    //int made = 0;//To avoid do the array to compare everytime i run this program since the winnin board will be the same
    
    int board_w [d] [d];//Making the doble array 
    
    //if ( make == 0 )
    //{

        for ( i = 0; i < d; i++)/// Making a board that is won already to comparate with the user's board   
        {
            for ( j = 0; j < d; j++)
            {
                tam_w++;
                board_w [i] [j] = tam_w;
            
                if ( board_w [i] [j] == (d *d) )//Getting the 0 to the last tile// 0 is my underscore
                {
                    board_w [i] [j] = 0;
                }
            }
        }
        
    ////////Comparing both boards
    for ( i = 0; i < d; i++)
    {
        for ( j = 0; j < d; j++)
        {
            if ( board [i] [j] != board_w [i] [j])
            {
                check = false;
            }
        }
    }
    
}