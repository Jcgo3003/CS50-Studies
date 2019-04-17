#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "trie.h"

// linked list
node *root = NULL;


// prototypes
void delete(void);
void insert(void);
void search(void);
void traverse(void);
int main(void)
{
    if( root == NULL) //si NO EXISTE root
    {
        // CREAR ESPACIO en memoria //
        node *newroot = malloc(sizeof(node));
        if ( newroot == NULL )
        {
            fprintf(stderr,"Could not create ROOT node\n");

        }
        // hago que esta sea la nueva raiz
        root = newroot;

    }

    int c;
    do
    {
        // print instructions
        printf("\nMENU TRIES\n\n"
            "1 - insert\n"
            "2 - search\n");

        // get command
        printf("Command: ");
        c = get_int();

        // try to execute command
        switch (c)
        {
            case 1: insert(); break;
            case 2: search(); break;
        }
    }
    while (c != 0);

    // // free list before quitting
    // node *ptr = root;
    // while (ptr != NULL)
    // {
    //     node *predptr = ptr;
    //     ptr = ptr->next;
    //     free(predptr);
    // }
}

/**
 * Tries to insert a number into list.
 */
void insert(void)
{
    printf("Introduce 4 numeros por cadena: \n");
    int num;
    int c = 1;

    node *pla = root;
    node *pla2;
    while ( c < 5)
    {
        printf("%i ", c);
        num = get_int();
        {
            ///creando nuevo nodo

            //
            if( ((c%2) != 0) && pla->next[num] == NULL)// impar y NO EXISTE
            {

                node *newnode = malloc(sizeof(node));
                if (newnode == NULL)
                {
                    printf("Error! no se puede crear nodo\n");
                    break;
                }

                pla->next[num] = newnode;////NUEVO nodo asingado en NUM
                pla2 = pla->next[num];///pla2 NODO
            }

            else if( ((c%2) != 0) && pla->next[num] != NULL)// impar y EXISTE
            {
                pla2 = pla->next[num];///pla2 es el nodo que ya exite
            }


            else if( ((c%2) == 0) && pla2->next[num] == NULL )// par y NO EXISTE
            {
                node *newnode = malloc(sizeof(node));
                if (newnode == NULL)
                {
                    printf("Error! no se puede crear nodo\n");
                    break;
                }

                pla2->next[num]= newnode;///NUEVO nodo asignado a pla2 en NUM
                pla = pla2->next[num];///pla NODO
            }

            else if( ((c%2) == 0) && pla2->next[num] != NULL )// par y EXISTE
            {
                pla = pla2->next[num];///pla NODO
            }


            if (c == 4)
            {
                printf("Escribe algo: ");
                pla->final = get_string();
                printf("Fin de cadena\n");
            }

        c++;
        }

    }
}

/**
 * Searches for a number in list.
 */
void search(void)
{
    node *ptr = root;
    node *ptr2;
    int num;
    int c = 1;
    while ( c < 5)
    {
        printf("%i ",c);
        num = get_int();

        if ( ( c%2 ) != 0)// impar
        {
            if( ptr->next[num] != NULL )// ptr en NUM tiene algo
            {
                printf("Existe\n");
                ptr2 = ptr->next[num];/// ptr2 sera el nodo num selcionado
            }
            else if( ptr->next[num] == NULL )  //si no
            {
                printf("No existe!\n");
                break;
            }
        }

        if ( ( c%2 ) == 0)// par
        {
            if( ptr2->next[num] != NULL )// ptr2 en NUM tiene algo dira
            {
                printf("Existe\n");
                ptr = ptr2->next[num];//ahora ptr es el nodo seleciondo
            }
            else if( ptr2->next[num] == NULL )  //si no
            {
                printf("No existe!\n");
                break;
            }
        }

        if (c == 4)
        {
            printf( "%s \n",  ptr->final );

        }
        c++;
    }
}

/**
 * Traverses list, printing its numbers.
 */
void traverse(void)
{

}
