#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>

typedef uint8_t  BYTE;

int main ( int argc, char *argv[])
{
    // ensure proper usage
    if ( argc != 2)
    {
        fprintf(stderr,"Usage: ./recover image\n");
        return 1;
    }
    
    //Remembering filename
    char *infile = argv[1];

    // Openig the file
    FILE *inptr = fopen (infile, "r");
    if ( inptr == NULL)
    {
        fprintf(stderr, "Could not open %s",infile);
        return 2;
    }
    
    ////////////////////////////////////////////
    ///FILE *outptr = fopen(outfile, "w")
    
    
    BYTE buffer [512];
    int count = 0;
    //char nam [10];
    
    
    while ( fread(buffer, 512, 1 , inptr)  )///cada que va haciendo este while esta metiendo datos en el buffer
    {
        if ( buffer[0]==0xff && buffer[1]==0xd8 && buffer[2]==0xff && (buffer[3]&0xf0) == 0xe0 )
        {
            
            printf("Count %i", count);
            count++;
            
            
        }
  
    }
    
}
       