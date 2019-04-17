#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main (void)
{
    ///// Cuidando el programa
    // if ( argc != 2 )
    // {
    //     printf("Can't load\n");
    // }

    //////aqui estoy leyendo el archivo de entrada
    // char *in = argv[1];
    // FILE *inptr = fopen(in , "r");
    // if (inprt == NULL)
    // {
    //     printf("Can't load file\n")
    //     return 2;
    // }

    ///Necesito que lea el contenido y vaya creando cadenas el solo

    // char ptr[5];

    // fread(ptr, 5, 1, in);


    ////Creando la estructa nodo y su contenido
    typedef struct node
    {
        bool is_word;//boleano para saber si ya alcanse el final de aquel camino
        struct node *children[27];///valor para hacer el camino
    }
    node;

    node *root = malloc(sizeof(node));////aqui este puntero esta apuntando a ese espacio donde hice malloc
    ///aqui ya tengo la raiz ahora debo hacer el trav para mantener seguro la raiz
    if ( root == NULL)
    {
        // unload();
        return false;
    }

    node *trav = malloc(sizeof(node));///creando a mi navegador
    trav = root;
    ///ahora necesito rellenar eso pero como?, cada vez que creo un nodo debo hacer malloc pero como hago que
    ///apunte a mi direcion

    if ( trav == NULL)
    {
        // unload();
        return false;
    }

    node *cero = malloc(sizeof(node));///ya cree ahora necesito que este enlazado a root
    trav -> children[0] = cero;///aqui asigno a children [0] en root  el nodo 0
    ///hasta aqui tengo el arbol de a
    if ( cero == NULL)
    {
        // unload();
        return false;
    }


    node *cerouno = malloc(sizeof(node));/// b
    cero -> children[1] = cerouno;

    if ( cerouno == NULL)
    {
        // unload();
        return false;
    }

    node *cerounodos = malloc(sizeof(node));/// c
    cerouno -> children[2] = cerounodos;

    if ( cerounodos == NULL)
    {
        // unload();
        return false;
    }

    cerounodos -> is_word = true;
    ///hasta ahora el mapa esta asi root > a > b > c true

    ///como lo reviso


    // if (cerounodos==NULL)
    // {
    //     printf("Nullo\n");
    // }
    // else
    //     printf("Verdadero\n");

    if (root->children[0]->children[1]->children[2]==true)
    {
        printf("verdarero por path\n");
    }
    else
        printf("Verdadero\n");


    //a b c
    ///como navegor mi trie no lo se

    // printf(" %c ", root->children[0]);
    // printf(" %i ", cero.children[1]);
    // printf(" %i ", cerouno.children[2]);






}
