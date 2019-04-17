/**
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>


int main(int argc, char *argv[])
{
    // ensure proper usage   /////////
    if (argc != 3)           /// Getting "n" from the comand line
    {
        fprintf(stderr, "Usage: ./resize n infile outfile\n");
        return 1;
    }

    // remember filenames

    char *infile = argv[1];             //Name infile 
    char *outfile = argv[2];            //Name outfile
    
    /////////////////////printf("n =  %i  2x %i\n", n, 2*n);

    // open input file 
    FILE *inptr = fopen(infile, "r");//Pointer inptr   and opens the file with the name of the comand line
    if (inptr == NULL)              //Keeping the program safe
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");//Pointer for out file, with the name of the comand line
    if (outptr == NULL)                 //Keeping the program safe
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }
    
    printf("Dame un numero ");
    int d = get_int();
    printf("Cuantas veces ");
    int n = get_int();
    
    fseek(inptr, 30 , SEEK_SET);
    int p = ftell(inptr );
    printf("p = %i\n", p);


    

    //El for funciona da tal manrea que cada que va cambiando de estado hace la tarea que esta dentro, no?
    
    // iterate over infile's scanlines
    for (int i = 0; i < d; i++)//makes a nested for biHeight times of the original data
    {
        //iterate over pixels in scanline so i must make here the iteration n times
        int rem_v = n;//remenbering n 
        while( rem_v != 0)
        {
            /////aqui regresa una vez que termino el prime rengos si o si por eso lo ajusta
            
            
            int j;
            printf("%i",i);////   para seguile la huella a como se va imprimiendo cada copia de fila
            ////////ahor mi puntero esta en lugar 30 necesito que cada vez que cambie de linea
            ////agreque el tamano de la lineas mas el padding
            ////30 + 0 + 0 en en el primer linea despues 
            ///cambio de linea                   30
            ////30 + 5 + 2 la linea sera 37      37
            ///cambio de linea                   44        
            ////37 + 5 + 2
            ////este seek es el de lectura
            fseek(inptr, ((d * i ) + (i* 2) ) , SEEK_CUR);
            
            for ( j = 0; j < d; j++)   //using the original data esto pas por cada linea d es el numero de largo
            {
                
                char temp[1];           //temp es mi buffer, cada ve que j cambie char lo hara tambien
                ////aqui mi puntero esta en 0 
                
                fread(&temp, sizeof(char), 1, inptr);///Read every single pixel
        
                int rem_h = n;          //remenbering n 
                while (rem_h != 0)///writing the data horizontaly 'n' times each pixel
                    {
                    printf("%2i", j);
                    fwrite(&temp, sizeof(char), (1), outptr);
                    rem_h--;
                    }
                    rem_h = n;
                
            }
            //adding padding
            printf(" XXXX\n");
            fputs( " XXXX\n", outptr);
            
            rem_v--;
            
        }
        rem_v = n;
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
