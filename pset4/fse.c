#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main(void) 
{
    /////// Crea apuntador out, crea archivo salida
    FILE* out = fopen("salida.txt", "w+");/// abre un apuntador out, 
    // FILE* out = fopen("out.txt", "w+"); me permite tanto escribir como leer
    ///// En salida.txt agrega eso
    //fputs("0123456789", out);// pon esto en apuntador out
    
    
    
    /////////////////////// lo posiona en lugar
    printf("que escribo? ");
    string s = get_string();
    fputs( s , out);
    
    /////////////////////
    printf("Donde me posiciono? ");
    int busco = get_int();

    fseek(out, busco , SEEK_SET);//busca en aputador out, # busco , en posicion seek_set
    
    /////////////////
    // FILE* opf = fopen("salida.txt", "r");
    printf("Desde donde imprimo ");
    int imp = get_int();

    // fseek(out, imp , SEEK_SET);//busca en aputador out, # busco , en posicion seek_set
    fseek(out, imp, SEEK_CUR);/// te posiciona desde donde se quedo el apuntador, poniedo ese lugar como el lugar 0 
    /////////////////
    char buffer[50];//crea buffer con 50 espacios 
    fgets(buffer, 50, out);//utiliza  a buffer, guarda 10 espacios, de out2
    
    ////////imprime buffer
    printf("%s\n", buffer); //imprime buffer

    fclose(out);
    // fclose(opf);
    
}