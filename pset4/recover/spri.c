#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main (void)
{

char buffer[50];///crea un arreglo de 50 chars

int course = 50;////int course  es 50

sprintf(buffer,"CS%d rocks!", course);///llama sprinf  (llama a arreglo de chars , imprime  cs " lugar" rocks, lugar de rocks)

/////hasta dodne entendi
///sprinf guardo en burffer ------ todo lo que esta despues de buffer
//ahore en buffer esta guardado todo eso 

printf("%s\n", buffer);///imprime la cadena de chars de 50 lo que hay dentro 


}