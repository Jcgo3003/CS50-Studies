#include <cs50.h>
#include <stdio.h>

///This funtion will get me a valid Hight
int number();

int main(void)
{
    int height = number(); /// ing heign is equal to the number i get from the user
    /// I start a for with height as conditional
    
    
    FILE* mar = fopen( "mario.txt" , "w");
    
    
    
    
    
    for (int i = 0; i < height ; i++)
    {
        ///I make a new for to iterate the spaces following the formula height - (i + 1)
        for (int a = 0; a < (height - (i + 1)); a++)
        {
            fprintf( mar, " ");
        }
        ///I make a another for to iterate the # following the formula (i + 1)
        for (int a = 0; a < (i + 1); a++)
        {
            fprintf( mar,"#");
        }
        /// I just print one space between each side of the piramid
        fprintf( mar,"  ");
        ///I make a another for to iterate the # following the formula (i + 1)
       for (int a = 0; a < (i + 1); a++)
        {
            fputc( '#', mar );
        }
        /// I print one \n for goint to print the next floor
        fputc('\n', mar);
        
    
    }
    
    fclose( mar );
    
    FILE* mar = fopen( "mario.txt" , "r");
    
    if ( mar == NULL)
    {
    printf("File does not exist.\n");
    return 1;
        
    }
    
    // for( int i = 0; i < n; i++ )
    // {
        string m = fgets(mar);
        printf("%s", m);
        
        
    // }
    
    
    
}
///The funtion number 
int number(void)
{
    ///I start a do while promting the user for an interger
    int n;
    do
    {
        printf("Height: ");
        n = get_int();
    }
    ///Will keep promting until the user introduce a number between 0 and 23
    while ( n < 0 || n > 23);
    return n;
    
}
    