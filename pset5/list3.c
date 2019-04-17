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
    int c;
    do
    {
        // print instructions
        printf("\nMENU\n\n"
            "1 - delete\n"
            "2 - insert\n"
            "3 - search \n"
            "4 - traverse\n"
            "0 - quit\n\n");

        // get command
        printf("Command: ");
        c = get_int();

        // try to execute command
        switch (c)
        {
            case 1: delete(); break;
            case 2: insert(); break;
            case 3: search(); break;
            case 4: traverse(); break;
        }
    }
    while (c != 0);

    // free list before quitting
    node *ptr = root;
    int i = 0;
    while (ptr != NULL && i < 0)
    {

        node *predptr = ptr;
        ptr = ptr->next[i];
        free(predptr);
        i++;
    }
}

/**
 * Tries to delete a number.
 */
void delete(void)
{

    // // prompt user for number
    // printf("Number to delete: ");
    // int n = get_int();

    // // get list's rootnode
    // node *ptr = root;

    // // try to delete number from list
    // node *predptr = NULL;
    // while (ptr != NULL)
    // {
    //     // check for number
    //     if (ptr->final == n)
    //     {
    //         // delete from head
    //         if (ptr == root)
    //         {
    //             root= ptr->next;
    //             free(ptr);
    //         }

    //         // delete from middle or tail
    //         else
    //         {
    //             predptr->next = ptr->next;
    //             free(ptr);
    //         }

    //         // all done
    //         break;
    //     }
    //     else
    //     {
    //         predptr = ptr;
    //         ptr = ptr->next;
    //     }
    // }

    // traverse list
    traverse();
}

/**
 * Tries to insert a number into list.
 */
void insert(void)
{

/// Creare una cadena desde nivel 0
    if( root == NULL) //si NO EXISTE root
    {
        // CREAR ESPACIO en memoria //
        node *newroot = malloc(sizeof(node));
        if ( newroot == NULL )
        {
            fprintf(stderr,"Could not create ROOT node\n");
            return;
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

///////////////////////////////////////////////////////////
    char res = 'a';
    node *placer2 = root;

    while( res != 'n' || res != 'N')
    {

        // Obteniendo num
        printf("Dame un numero ");////per
        int num = get_int();//obtengo el numero

        ////node *placer2;///apuntador
        /// Si NUM ya exite entonces
        if (placer2->next[num] != NULL)///placer apuntando a ROOT si comienza a Otro nodo si no
        {
            printf("Ya exite!!! \n");
            placer2 = placer2->next[num];///placer2 apunta a ese nodo descrito por 'num' por si quiere seguir agregando nodos
        }
        else //si NUM NO EXISTE
        {
            //Creo un nuevo nodo
            node *newptr = malloc(sizeof(node));
            if ( newptr != NULL)
            {
                fprintf(stderr,"Could not create node\n");
                return;
            }

            //hago que apunte ROOT la punte hacie el
            newptr->final = false;//los organizo

            placer2->next[num] = newptr;

            //apuntto hacia el nuevo NODO
            ///???? por cambiar placer2 de nodo se persera al que ya estaba apuntando
            ////placer2 = placer2->next[num];///placer2 apunta a ese nodo descrito por 'num'
            placer2 = placer2->next[num];
        }

        ////pregunto sobre continuar la cadena
        printf("Quieres agregar mas numeros Y/N ");
        res = get_char();
        if (res == 'y' || res == 'Y')
        {
            printf("Obteniendo siguiente numero \n");
        }
        else if ( res == 'n' || res == 'N')
        {
        ////aqui tengo que hacer que el ultimo node tenga final == TRUE
            break;
            placer2->final = true;
        }

    }

//         while(true)
//         {
//             //si no existe ese puantador
//             if (placer2->next[num] == NULL)
//             {
//                 node* newptr = malloc(sizeof(node))
//                 if (newptr == NULL)
//                 {
//                     return;
//                 }
//                 placer2->next[num] == newprt;//hago que apunte hacia el nuevo espacio
//             }
//             else if (placer2->[num] != NULL)///si ya existe aquel numero de apuntador
//             {
//                 free(newptr);
//             }

//         }

//     }




//     ///// debe haber un nodo que se quede apuntando por cada numero creado?????







// /// COLOCANDO EL NODO EN SU SITIO // PENSANDO QUE AQUI ESTOY CONSTRUENDO UNA CADENA DESDE CERO

//     // si es el PRIMERO DEL TODO // si num no existe antes
//     // colocalo al principio
//     if (root == NULL)// si sustituyo aqui ROOT por otro que tenga un numero distinto se perdera
//     {
//         root = newptr;////o bastara con nombrara aquel numero para regesara a su raiz
//     }


// //// si YA EXISTE entonces revisara que este nuevo nodo NO SE@!!!
//     else
//     {
//         node *placer2 = root;///// apunta a root
//             // si ya existe // NO DUPLICADOS!!!
//             // borralo
//             if (placer2->next[num] == newptr->next[num])/////si pred prt N es igual al Nuevo
//             {
//                 free(newptr);////borrar
//                 //  break;
//             }

//             //
//             else if (placer2->next[num] == NULL)///placer2 que es la copia de ROOT next
//             {
//                 placer2->next[num] = newptr;/////pred ptr NEXT es el NUEVO
//                 // break
//             }

//             // check for insertion in middle
//             else if (predptr->next->n  >  newptr->n)//////si pred NEXT N es MAYOR que n de nuevo
//             {
//                 newptr->next = predptr->next;////Nuevo next apunte a pred NEXT apunte al mayor
//                 predptr->next = newptr;/////pred ptr NEXT  apunte a NUEVO asi queda insertado en medio
//                 break;
//             }

//             // update pointer
//             predptr = predptr->next;//////cuando termina y no dio ninguno se esos
//             ////hace que pred ptr apunte hacia otro numero

//         }












//     }



//     printf("Quieres seguir insertando numeros dentro de esta canadena N / Y \n");
//     char res = get_char();
//     if (res == 'Y' || res == 'y')
//     {
//         node *placer1 = root;///placer 1 == predptr // Aqui tengo

//             placer->next[] = newptr;
//             break;



//             predptr = predptr->next;
//     }
//     else
//     {
//         break;
//     }


//     // // SI NO LO ES // NO ME SIRVE EN EL OTRO PROGRAMA EL CONTADOR CUIDA QUE TODOS SE UNAN A EL DESPUES NO ANTES
//     // else if (newptr->n < root->n)///AQUI DICE SI este era por si el numero era menor pero en un trie asi que no habra necesidad
//     // {////////////////////////////////////////////////////////////////
//     //     newptr->next[num] = root;////////////////////////////////////NO SIRVE
//     //     root = newptr;//////////////////////////////////////////////////////NO SIRVE
//     // }///////////////////////////////////////////////////////////////////////////NO SIRVE

//     // else try to insert number in middle or tail
//     else
//     {

//     }


}

/**
 * Searches for a number in list.
 */
void search(void)
{
    // // prompt user for number
    // printf("Number to search for: ");
    // int n = get_int();

    // // get list's rootnode
    // node *ptr = root;

    // // search for number
    // while (ptr != NULL)
    // {
    //     if (ptr->n == n)
    //     {
    //         printf("\nFound %i!\n", n);
    //         sleep(1);
    //         break;
    //     }
    //     ptr = ptr->next;
    // }
}

/**
 * Traverses list, printing its numbers.
 */
void traverse(void)
{
    // // traverse list
    // printf("\nLIST IS NOW: ");
    // node *ptr = root;
    // while (ptr != NULL)
    // {
    //     printf("%i ", ptr->n);
    //     ptr = ptr->next;
    // }

    // // pause before continuing
    // sleep(1);
    // printf("\n\n");
}
