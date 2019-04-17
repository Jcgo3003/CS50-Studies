#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "list0.h"

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
        ///Creo que hasta que no asignas a ningun hijo es nulo por defaul
        // for ( int i = 0; i < 10;  i++ )
        // {
        //     root->next[i] = NULL;
        // }
    }
    node *placer2 = root;
////        I
////        v
//////root  = placer2
    node *newptr = malloc(sizeof(node));///NUEVO NODO VACIO
            if ( newptr == NULL)
            {
                fprintf(stderr,"Could not create node\n");

            }
////        I
////        I
////        v
    placer2->next[2] = newptr;          /////root apunta a nuevo nodo en 2
    node *placer1 = placer2->next[2];   ///placer1 es NUEVO nodo
////        I
////        I
////        v
/////////////////////////////
    node *newptr2 = malloc(sizeof(node));////SEGUNDO NUEVO NODO
            if ( newptr2 == NULL)
            {
                fprintf(stderr,"Could not create node\n");
            }
////        I
////        I
////        v
    placer1->next[10] = newptr2;////////primer nodo apunta a NUEVO en 3
    placer2 = placer1->next[10];///////placer2 hace de nuevo nodo

    ///placer2->next[2] = NULL;
    placer2->final = true;


printf("Terminado \n");


    // traverse list/////
    printf("\nLIST IS NOW: \n");

    // node *ptr = root;///////de nuevo prt apunta a root
    // while (ptr != NULL) ////mienstras prt diferente de nullo
    // {
    //     printf("%i ", ptr->n);/////imprime los numeros de prt
    //     ptr = ptr->next;////refreca el puntero
    // }

    node *ptr = root;////Apuntando a ROOT

    /////de ROOT a primer nodo
    if( ptr->next[2] != NULL )///si en ROOT esta conectado en 2
    {
        printf("  Root en 2 \n");
    }

    ////de root nodo a primer nodo
    node *ptr2 = ptr->next[2];///ahora ptr2 es el PRIMER NODO apuntado en 2

    if ( ptr2->next[10] != NULL )////si prt2 next 2 hay una ->
    {
        printf("Primer Nodo en 10 \n");///si hay una flecha hacia otro nodo
    }

    ///de primer nodo a segundo nodo
    node *ptr1 = ptr2->next[10];///ahora ptr1 es el SEGUNDO NODO en 3

    if ( ptr1->next[12] != NULL)
    {
        printf("Por si acaso \n");
    }

    if ( ptr1->final == true)
    {
        printf("Es verdarero exito!!!\n");
    }



}