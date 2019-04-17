/**
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

#include "bmp.h"

int main(int argc, char *argv[])//Gets information over the comand line 
{
    // ensure proper usage
    if (argc != 3)
    {
        fprintf(stderr, "Usage: ./copy infile outfile\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[1];//This is the pointer for the file that i get and its called'infile'
    char *outfile = argv[2];//The pointer out its call "outfile"
    
    printf("Primer %s\n", infile);
    printf("Segundo %s\n", outfile);
    
    int a = 3;
    int *pa;
    pa = &a;
    
    printf("A quien le doy el 1 a a o ap ");
    int b = get_int();
    
    if (b == 1)
    {
        a++;
        printf("Suma por a\n");
        printf("a = %i\n", a);
    }
    if (b == 2)
    {
        *pa = 10;
        printf("Suma por pa\n");
        printf("a = %i\n", a);
        
    }
    if (b == 3)
    {
        pa = &b;
        *pa = 120;
        printf("Suma por pa a b\n");
        printf("b = %i\n", b);
        
    }
    
    
}
