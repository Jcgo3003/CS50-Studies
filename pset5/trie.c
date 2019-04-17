#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "list0.h"

typedef struct node
{
    string final;//
    struct node *next[];//
}
node;

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
        root->final = false;
    }

    printf(" Welcome to TRIES \n");
    printf(" Introduce 4 numeros por cadena: \n");
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
            node *newnode = malloc(sizeof(node));
            if (newnode == NULL)
            {
                printf("Error! no se puede crear nodo\n");
                break;
            }

            if( ( c%2 ) != 0 )// impar
            {
            pla->next[num] = newnode;////NUEVO nodo asingado en NUM
            pla2 = pla->next[num];///pla2 NODO
            }
            else if( ( c%2 ) == 0 )// par
            {
                pla2->next[num]= newnode;///NUEVO nodo asignado a pla2 en NUM
                pla = pla2->next[num];///pla NODO
            }


            if (c == 4)
            {
                pla->final = "Hello word";
                printf("Fin de cadena\n");
            }

        c++;
        }

    }
    printf("\n");
    printf("Busqueda de numeros\n");

    node *ptr = root;
    node *ptr2;
    int num;
    int c2 = 1;
    while ( c2 < 5)
    {
        printf("%i ",c2);
        num = get_int();

        if ( ( c2%2 ) != 0)
        {
            if( ptr->next[num] != NULL )// ptr en NUM tiene algo dira
            {
                printf("En orden\n");
                ptr2 = ptr->next[num];/// ptr2 sera el nodo num selcionado
            }
            else
            {
                printf("No existe!\n");
                break;
            }


        }
        if ( ( c2%2 ) == 0)
        {
            if( ptr2->next[num] != NULL )// ptr2 en NUM tiene algo dira
            {
                printf("En orden\n");
                ptr = ptr2->next[num];//ahora ptr es el nodo seleciondo
            }
            else
            {
                printf("No existe!\n");
                break;
            }

        }

        if (c2 == 4)
        {
            printf( "%s \n",  ptr2->final );

        }


        c2++;
    }

    printf("FIN\n");


    necesito alguien que mire en root
    si encuentra salidas a nodos
    siguelas

    no
    borra ese nodo

    root con salidas a 2 4 6
    busco en 1 nada 2 si
    2 me llevo a otro nodo -- busco nodos encuentro uno en 3
      el nodo 3 NO tiene salidas  -- borralo
      regresa a 2


    necesito una funcion que se REVISE cada salida del nodo
    cuando encuentre una que se meta y


    ///Liberando memoria
    // int c3 = 1;

    // node *ptr = root;
    // node *ptr2;

    // while(true)
    // {
    //     if ( prt->next[c3] != NULL )// si Hay un nodo
    //     {
    //         node * ptr3 = ptr;////creo un nuevo ptr apuntando a ptr
    //         ptr = ptr->next[c3];//ptr apunta al proximo
    //         free(ptr3);/////libero el nuevo ptr que apuntaba al viejo
    //     }

    //     c3++;


    // }




    // node *ptr = root;
    // while (ptr != NULL)
    // {
    //     node *predptr = ptr;
    //     ptr = ptr->next;
    //     free(predptr);
    // }











}

