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
    
    
    
    
    BYTE buffer [512];
    int a = 0;
    int b = 0;
    while (   fread(buffer, 512, 1 , inptr)  ) 
    {
        //ya se el numero de bloques ahora
        a++;
        
        //Reading a block of 512
        if ( buffer[0]==0xff && buffer[1]==0xd8 && buffer[2]==0xff && (buffer[3]&0xf0) == 0xe0  ) 
        {
            b++;
        }
        
    }
    int c  = ftell(inptr);
    printf("Read %i\n",c);
    
    int cont = 0;
    
    fseek(inptr, 0, SEEK_SET);
    
    for ( int i = 0; i < a; i++)
    {
        fread(buffer, 512, 1 , inptr);
        
        if ( buffer[0]==0xff && buffer[1]==0xd8 && buffer[2]==0xff )
        {
            cont ++ ;
        }
        
        
        // printf("Buffer 0 %i\n", buffer[0]);
        // printf("Buffer 1 %i\n", buffer[1]);
        // printf("Buffer 2 %i\n", buffer[2]); 
        
        // int c  = ftell(inptr);
        // printf("tell %i\n",c);
    }
    
    
    printf("a %i\n", a);
    printf("Cont %i\n", b);
    
    // printf("\n");
    c  = ftell(inptr);
    printf("Read final %i\n",c);
    // printf("Buffer 1 %i\n", buffer[0]);
    // for ( int i = 0; i < 30, i++)
    // {
        
    // }
    
    
}