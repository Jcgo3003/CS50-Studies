/**
 * Demonstrates a linked list for numbers.
 */

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
    while (ptr != NULL)
    {
        node *predptr = ptr;
        ptr = ptr->next;
        free(predptr);
    }
}

/**
 * Tries to delete a number.
 */
void delete(void)
{
    // prompt user for number
    printf("Number to delete: ");
    int n = get_int();

    // get list's rootnode
    node *ptr = root;///apunta a root

    // try to delete number from list
    node *predptr = NULL;////nodo pred ptr NULLO
    while (ptr != NULL)/////mientras no tope con NULLO
    {
        // check for number
        if (ptr->n == n)/////cuando lo encuentre
        {
            // delete from head
            if (ptr == root)//////si esta al pricipio
            {
                root= ptr -> next;////hace que rootapunte el proximo
                free(ptr);////borra ese numero malloc prt
            }

            // delete from middle or tail
            else
            {
                predptr->next = ptr->next;////hace que pred prt == a prt NEXT
                free(ptr);////borra ptr
            }//////pred prt NEXT apunta al numero que solia apuntar el numero que se borro

            // all done
            break;
        }
        else/////si ptr no lo encuentra////actualiza los datos y continua
        {
            predptr = ptr;////pred ptr sera ptr
            ptr = ptr->next;/////hace que prt sea apunte a NEXT
        }
    }

    // traverse list
    traverse();///mostrar lista
}

/**
 * Tries to insert a number into list.
 */
void insert(void)
{
    // CREAR NODO //
    node *newptr = malloc(sizeof(node));
    if (newptr == NULL)
    {
        return;
    }

    // RELLENAR NODO //
    printf("Number to insert: ");
    newptr->n = get_int();
    newptr->next = NULL;

    // check for empty list
    if (root== NULL)//////si rootes nullo esta vacio
    {
        root = newptr;///hace que rootsea el nuevo
    }

    ////si no es nullo es que ya hay otros numeros////////////////////////////////

    // else check if number belongs at list's head
    ///SI nuevo es MENOR!!!!//////////
    else if (newptr->n   <   root->n)///revisa si el numero de nuevo es menor que root
    {
        newptr->next = root;////hace que nuevo apunte a root////AQUI HACE EXACTAMENTE ESO
        root = newptr;//////ahora nuevo es root///hace que nuevo apunte a ROOT, despues hace que root a nuevo
    }

    // else try to insert number in middle or tail
    else
    {
        node *predptr = root;////crea un tercer apuntador pred ptr
        while (true)/////lo apunta a rooty hacae un ciclo infinito verdadero
        {
            // avoid duplicates// NO DUPLICADOS!!!
            if (predptr->n == newptr->n)/////si pred prt N es igual al Nuevo
            {
                free(newptr);////borrar
                break;
            }

            // check for insertion at tail//BUSCA EL FINAL DEL TODO Y LO METE HASTA EL FINAL
            else if (predptr->next == NULL)///si pred prt NEXT es NULO
            {
                predptr->next = newptr;/////pred ptr NEXT es el NUEVO
                break;
            }

            // check for insertion in middle
            else if (predptr->next->n  >  newptr->n)//////si pred NEXT N es MAYOR que n de nuevo
            {
                newptr->next = predptr->next;////Nuevo next apunte a pred NEXT apunte al mayor
                predptr->next = newptr;/////pred ptr NEXT  apunte a NUEVO asi queda insertado en medio
                break;
            }

            // update pointer
            predptr = predptr->next;//////cuando termina y no dio ninguno se esos
            ////hace que pred ptr apunte hacia otro numero

        }

    }

    // traverse list
    traverse();////mostrar lista
}

/**
 * Searches for a number in list.
 */
void search(void)
{
    // prompt user for number
    printf("Number to search for: ");
    int n = get_int();

    // get list's rootnode
    node *ptr = root;/////apunta ptr apunta a root

    // search for number
    while (ptr != NULL)/////mientras no topes con nullo
    {
        if (ptr->n == n)///////cuando lo encuntres
        {
            printf("\nFound %i!\n", n);///di encontrado lists
            sleep(1);
            break;
        }
        ptr = ptr->next;//////actualiza su buscador
    }
}

/**
 * Traverses list, printing its numbers.
 */
void traverse(void)
{
    // traverse list/////
    printf("\nLIST IS NOW: ");

    node *ptr = root;///////de nuevo prt apunta a root
    while (ptr != NULL) ////mienstras prt diferente de nullo
    {
        printf("%i ", ptr->n);/////imprime los numeros de prt
        ptr = ptr->next;////refreca el puntero
    }

    // pause before continuing
    sleep(1);
    printf("\n\n");
}
