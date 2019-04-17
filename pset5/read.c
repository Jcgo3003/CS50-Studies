#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <cs50.h>
#include <ctype.h>
#define alpha 26


////struct node
typedef struct node
{
    bool fin;
    struct node *next[alpha];///crea una apuntador llamando next con un numero
}
node;
///setting a new root
node *root = NULL;

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./read infile outfile\n");
        return 1;
    }

    // remember file names
    char *infile = argv[1];             //Name infile
    //char *outfile = argv[2];            //Name outfile

    // open input file
    FILE *inptr = fopen(infile, "r");//Pointer inptr   and opens the file with the name of the comand line
    if ( inptr == NULL )              //Keeping the program safe
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // // open output file
    // FILE *outptr = fopen(outfile, "w");//Pointer for out file, with the name of the comand line
    // if (outptr == NULL)                 //Keeping the program safe
    // {
    //     fclose(inptr);
    //     fprintf(stderr, "Could not create %s.\n", outfile);
    //     return 3;
    // }

    // Buffer
    char buffer = 'p';
    int  count = 0;
    // int's
    //int num_b = 50;
    int num = 0;

    // leeyendo las palabras
    while( buffer != EOF )//isalpha(buffer) HASTA QUE TEMINE EL DICCIONARIO COMPLETO
    {
        buffer = fgetc(inptr);///leyendo el archivo

        //transformo las letras a numeros
        num = buffer - 97;///necesito que se acuerde cada vez del numero anterior

        if (buffer == '\'')// Si " ' " SERA 26
        {
        num = 26;
        }
        ///para que solo obtega letras y no signos extranos, AQUI seguira recibiendo letras hasta que
        if ( (num >= 0 && num <= 26) ) // || (num_b >= 0 && num_b <= 26) )//protejo el programa de signos raros
        {

            // // aqui comienzo a crear el nodo
            //     node *nuevo = malloc(sizeof(node));//creo el nuevo nodo
            //     if( nuevo == NULL)///por si no se crea
            //     {
            //         fprintf(stderr,"Could not create a new node\n");
            //         return 1;
            //     }

            //     nuevo->next[num] = NULL;///el nuevo nodo 'num' apunta hacia la nada NULL
            //     nuevo->fin = false;
            // /////aqui ya esta creada ahora la tengo que POSICIONAR

            // ///si el la PRIMERA vez que se crea algo DEL TODO
            //     if( root == NULL)
            //     {
            //         root = nuevo;
            //     }////PRIMER NODO

            //     else
            //     {
            //     ///// AQUI YA EXITE ALGUIEN HASTA ARRIVA // NECESITO QUE PLACER 1 VAYA UNIENDO LOS LUGARES
            //     node *placer1 = root;/// APUNTA ROOT
            //     }
            //     while (true)
            //     {
            //         /// avoid duplicates // - NO DUPLICADOS -
            //         if (placer1->next[num] == nuevo->next[num])
            //         {
            //             free(nuevo);////borralo
            //             break;////termina este while
            //         }

            //         // check for insertion at tail //Insertandolo al final
            //         else if (placer1->next[num] == NULL)///placer1 == root
            //         {
            //         placer1->next[num_b] = nuevo;////uniendo el nuevo con Anterior/ROOT////
            //         break;
            //         }
            //     }
            count++;///creo que este contador me va ayudar a la hora de hacer las uniones
            printf("%i", count);
            printf("%i ", num);///EN vez de este creara el nodo
        }

        ///aqui es cambio de palabra aqui PUEDO LLAMAR A SIZE porque cada '\n' significa una nueva palabra
        if (buffer == '\n'|| buffer == EOF)//aqui quiero que reconosca que es otra palabra
        {//que aqui comienze otro  nodo asi hasta el final de los tiempos o EOF
            //  nuevo->fin = TRUE;
             printf(" C%i", count);
             count = 0;
             //num_b = num;///de esta manera num_b recordara el numero anterior
             printf("\n");
        }

    }

    fclose(inptr);





}