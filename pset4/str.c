#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include "bmp.h"

int main(void) 
{
    
    typedef struct 
    { 
    string name; 
    int age; 
    char sex; 

    }  per; 
    
    per hola;
    
    printf("Name: ");
    hola.name = get_string();
    printf("Age: ");
    hola.age = get_int();
    printf("Sex: ");
    hola.sex = get_char();
    
    printf("%s %i %c \n", hola.name, hola.age, hola.sex );
    
    // /////// Crea apuntador out, crea archivo salida
    // FILE* out = fopen("copy.bmp", "r");/// abre un apuntador out, 
    // // FILE* out = fopen("out.txt", "w+"); me permite tanto escribir como leer
    // ///// En salida.txt agrega eso
    // //fputs("0123456789", out);// pon esto en apuntador out
    
    // if (out == NULL)//If that file is doesn't exist does this
    // {
    //     fprintf(stderr, "Could not open");
    //     return 2;
    // }
    // ////////////////////////////////////////////
    
    // // read infile's BITMAPFILEHEADER
    // BITMAPFILEHEADER bf;//creates "bf" a type of struck called "BIT MAP FILE HEADER" that comes in bmp.h
    // fread(&bf, sizeof(BITMAPFILEHEADER), 1, out);//the buffer will be "bf", size, 1, from the input(file in)
                                    
    // // read infile's BITMAPINFOHEADER
    // BITMAPINFOHEADER bi;// creates a second struc call "bi" that constaint the BIT MAP INFO HEADER  
    // fread(&bi, sizeof(BITMAPINFOHEADER), 1, out);
    
    // printf("%i %i %i %i\n", bf.bfType, bf.bfSize, bf.bfReserved1, bf.bfReserved2 );
    // printf("%i\n", bi.biCompression);
    
    // // if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
    // //     bi.biBitCount != 24 || bi.biCompression != 0)//if anything of this is diferent of this data then
    // // /////////////////////// lo posiona en lugar
    // // printf("que escribo? ");
    // // string s = get_string();
    // // fputs( s , out);
    
    // // /////////////////////
    // // printf("Donde me posiciono? ");
    // // int busco = get_int();

    // // fseek(out, busco , SEEK_SET);//busca en aputador out, # busco , en posicion seek_set
    
    // // /////////////////
    // // // FILE* opf = fopen("salida.txt", "r");
    // // printf("Desde donde imprimo ");
    // // int imp = get_int();

    // // // fseek(out, imp , SEEK_SET);//busca en aputador out, # busco , en posicion seek_set
    // // fseek(out, imp, SEEK_CUR);/// te posiciona desde donde se quedo el apuntador, poniedo ese lugar como el lugar 0 
    // // /////////////////
    // // char buffer[50];//crea buffer con 50 espacios 
    // // fgets(buffer, 50, out);//utiliza  a buffer, guarda 10 espacios, de out2
    
    // // ////////imprime buffer
    // // printf("%s\n", buffer); //imprime buffer

    
    
    
    // fclose(out);
    // // fclose(opf);
    
}