#include <cs50.h>
#include <stdio.h>

void letras(string name);  ///declara el programa que se llama  letras 

int main (void)
{
    string s = get_string(); //Crea un string "s" y obtiende datos del usuario
    letras(s);              ///Llama a su programa letras, y en en el string saca manda a s
                            ///Lo que guardo en s lo manda a su string y lo pone en lugaar de name 
}

void letras(string name)    
{
    printf("hello, %s\n", name);  ///imprime en la pantalla hello y lo que se haya guardado en name
}