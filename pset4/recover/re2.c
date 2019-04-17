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
    char nam [10];
    
    
    while ( fread(buffer, sizeof(BYTE), 512, inptr) )///Reading the file
    {
        if ( buffer[0]==0xff && buffer[1]==0xd8 && buffer[2]==0xff && (buffer[3]&0xf0) == 0xe0 ) 
        {
            printf("%i", count);
            sprintf( nam ,"%03i.jpg", count);///getting a name for the file
            FILE *outprt = fopen ( nam , "w" );///opening a new file
            
            fwrite(buffer, sizeof(BYTE), 512, outprt);///Writing the rootblock
            fread(buffer, sizeof(BYTE), 512, inptr);//reading the next block
            
                while ( buffer[0]!=0xff && buffer[1]!=0xd8 && buffer[2]!=0xff && (buffer[3]&0xf0) != 0xe0 ) //kepping writing
                {
                fwrite(buffer, sizeof(BYTE), 512, outprt);///writing the rootblock
                fread(buffer, sizeof(BYTE), 512, inptr);//reading the next block
                }
            fclose(outprt);
            count ++;
        }
    }
    fclose(inptr);
}
    // fread(buffer, 512, 1, inptr);
    // printf("1\n");
    // for ( int i = 0; i < 512 ; i++)
    // {
    //     printf(" %i ", buffer[i]);
    // }
    
    // printf("\n");
    // printf("2\n");
    // fread(buffer, 512, 1, inptr);
    // for ( int i = 0; i < 512 ; i++)
    // {
    //     printf(" %i", buffer[i]);
    // }
    // printf("\n");
    
    // printf("3\n");
    // fread(buffer, 512, sizeof(BYTE) , inptr);
    // for ( int i = 0; i < 512 ; i++)
    // {
    //     printf(" %i ", buffer[i]);
    // }
    // printf("\n");

    /////////
    // while ( fread(buffer, 512, 1 , inptr)  )///cada que va haciendo este while esta metiendo datos en el buffer
    // {
    //     if ( buffer[0]==0xff && buffer[1]==0xd8 && buffer[2]==0xff && (buffer[3]&0xf0) == 0xe0  )
    //     {
            
    //         ///jpg encontrado!!!!
    //         printf(" C %i  ", count);//contar las veces que salta esta funcion
            
    //         sprintf( nam ,"%03i.jpg", count);///dadole un nombre al archivo
            
    //         FILE *outprt = fopen ( nam , "w" );///abriendo el archivo
            
    //         fwrite (buffer, 512, 1, outprt);    
    //         while ( sen == 0) //mientras sen sea 0 sigue haciendo esto 
    //         {

    //             //al momento de leer de nuevo camibo la posicion a la siguiene
    //             fread(buffer, 512, 1 , inptr);///creo que por leer otra vez movio el cursor de lectura
                
    //             fwrite (buffer, 512, 1, outprt);///comenzo a escribir desde el segundo bloque
    //             ///si quito eso de leer talvez siga llenadoel buffer
    //             ///por otra parte me parece que nada se movera hasta que termine esta funcion
    //             //es decir escribe esto
    //             //despues esccribe el buffer
                
    //             ///solo copio el primer 512 y nada mas
                
                
    //           /// printf("%i", count);
    //             //hasta aqui ya hizo eso ahora si
                
    //             if ( buffer[0]==0xff && buffer[1]==0xd8 && buffer[2]==0xff && (buffer[3]&0xf0) == 0xe0  )
    //             {
    //                 sen = 1;
    //             }
    //             // el estado cambia 1 y se acaba la funcion la cosa es que quiero que siga leyendo
    //         }
            
    //         fclose(outprt);
    //         count ++;
    //         sen = 0;

    //     }
        


///////////y si ya llamo una funcion que trabaje de la siguiente manera

    ////tiene que escribir cuando se le invoque y segui escribienfo hasta que 
    ///cambie de estado la coso es que el puntero que esta arriva se sigue moviendo 
        
        
        
        
        
        // if ( buffer[0]==0xff && buffer[1]==0xd8 && buffer[2]==0xff && (buffer[3]&0xf0) == 0xe0  )
        // {
        //     int a = count;
        //     printf("count %i ", count);
        //     count ++;
            
        //     ///lo encontre !!!
            
        //     ///ahora escribe ese en out 
        //     ///ya escrcibi uno en out ahora necesito que sigas escribiendo 
        //     ///hasta que encuentres otro
        //     while( a!=count )
        //     {
        //     printf(" %i ", count);
        //     }
        //     ////se queda en bulce infinito porque jamas termina este while 
        // printf("\n");
        // }
        
        
        
        
        
        
        
        
        // if ( buffer[0]==0xff && buffer[1]==0xd8 && buffer[2]==0xff && (buffer[3]&0xf0) == 0xe0  ) 
        // {
            
        //     //// getting name for the jpg  
        //     sprintf( nam ,"%03i.jpg", count);
        //     /// opening the file to read
        //     FILE *outprt = fopen ( nam , "w" );
            
        //     count ++;///adding +1 to the counter
            
        //     fwrite (buffer, 512, 1, outprt);//writing the file the rootchunck of 512
            
        //     while ( buffer[0]!=0xff && buffer[1]!=0xd8 && buffer[2]!=0xff && (buffer[3]&0xf0) != 0xe0 )
        //     ////esta mal porque asi evita escribir los primeros 512
            
        //     {
        //     fwrite (buffer, 512, 1, outprt);//writing the file the rootchunck of 512
        //     }
        //     ///necesito decirle a la maquina que se dentega un bloque antes de llegar a el el siguiente
            
        //     fclose(outprt);
            
        // }
        

    
    
    
    // for ( int i = 0; i <= count; i++ )
    // {
    //     printf("pos %i %i\n", i, pos[i]);
    // }
    



    // mientras bla bla sea verdad while rellena buffer
    
    // buffer ya se esta rellenando solo
    
    // revisa en buffer si encuentas el praton tal
    
    // abre un archivo 
    
    // ahora  BUFFER encontrado lo que pasa es que guarda ese buffer solo ese buffer 
    // while sigue leyendo ahora necesito una condicion que haga que este 
    
    // while bla lee y lee 
    
    //     if bla   
    //     cambia senal a 0
    //     dale la senal a while 1
        
    //     }
        
    //     while senal = 1 hasta que senal 0 cuando llega a 0 no trabaja mas es decir no sabe cuando cerrar el archivo
    //     {
    //     abre  archivo tal  
    //     guarda ese buffer 
    //     sigue escribiendo 
    //     }
    //     if  senal 0
    //     {
    //     end of file
    //     cierra ese archivo
    //     }
        
        
    