/**
 * Demonstrates a linked list for students.
 */

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "list1.h"

// linked list
node *root= NULL;

// prototypes///// Declarando las funciones
void delete(void);
void insert(void);
void search(void);
void traverse(void);

int main(void)
{
    int c;/////usa a c para navegar entre las funciones
    do
    {
        // print instructions///Menu
        printf("\nMENU\n\n"
            "1 - delete\n"
            "2 - insert\n"
            "3 - search\n"
            "4 - traverse\n"
            "0 - quit\n\n");

        // get command
        printf("Command: ");
        c = get_int();///c

        // try to execute command
        switch (c)/////manda llamar cada programa por los cases
        {
            case 1: delete(); break;
            case 2: insert(); break;
            case 3: search(); break;
            case 4: traverse(); break;
        }
    }
    while (c != 0);//////esto pasara mientras el usuario  no introdusca 0

    // free list before quitting/////librarando los nodos antes de salir
    node *ptr = root;/////apunta a ptr a la cabeza del nodo
    while (ptr != NULL)////y corre este bucle mientras haya algo en ptr blabla
    {
        node *predptr = ptr;/////////crea nodo pred prt y hace que mire hacia ptr
        ptr = ptr->next;/////apunta prt al siguiente nodo
        if (predptr->student != NULL)//////si encuentra algo en pred ptr student name
        {/////////entra a cada uno de las varaibles y los borra uno por uno
            if (predptr->student->name != NULL)
            {
                free(predptr->student->name);/////NOMBRE
            }
            if (predptr->student->dorm != NULL)
            {
                free(predptr->student->dorm);/////DORMITORIO
            }
            free(predptr->student);////al final borra ese STUDENT
        }
        free(predptr);///// Borra ese NODO
    }///////Y termino con ese nodo///////No se por no borro id
}

/**
 * Tries to delete a student.
 */
void delete(void)//////borrando nodo
{
    // prompt user for ID
    printf("ID to delete: ");/////imprime en pantalla
    int n = get_int();////obtiene el numero del usuario a borrar

    // get list's rootnode
    node *ptr = root;/////apunta ptr a root

    // try to delete student from list
    node *predptr = NULL;//////crear pred ptr y lo manda a NULLO
    while (ptr != NULL)//////mientras haya algo dentro en ptr esto pasara
    {
        // check for ID
        if (ptr->student->id == n)/////si prt id es igual a N ///ENCONTRANDO A N
        {
            // delete from head///si es el  primero
            if (ptr == root)/////si prt resulta ser el primero es lo que dice
            {
                root= ptr->next;///////////hace que la rootapunte a next es decir al proximo nodo
                free(ptr->student->name);/////libera prt student NAME
                free(ptr->student->dorm);///DORM
                free(ptr->student);////Borra TODA la ESTRUCTURA
                free(ptr);//////Borra el NODO
            }
        ////////////como Ya lo encontro pero no en el PRIMER NODO hace lo siguiente/////////////////
            // delete from middle or tail////////de en medio o hasta atras //
            else                //      //
            {
                predptr->next = ptr->next;//////hace que pred ptr apunte a donde apunta prt que estara despues del segundo nodo o mas
                if (ptr->student->name != NULL)////si PTR STUDENT NAME hay algo en NAME
                {
                    free(ptr->student->name);///////BORRA NAME
                }
                if (ptr->student->dorm != NULL)
                {
                    free(ptr->student->dorm);/////Borra DORM
                }
                free(ptr->student);///////BORRA STRUCT student
                free(ptr);//////Borra el NODO
            }/////pred ptr esta apuntando a donde solia apuntar prt NEXT

            // all done
            break;/////no se por que no hace el break desde cada funcion???????
        }
        else///////mientras no lo encuentre hace que siga CAMBIANDO de NODO
        {
            predptr = ptr;/////pred prt se queda atras
            ptr = ptr->next;///prt apunta hacia NEXT
        }
    }

    // traverse list
    traverse();//////muestra la lista
}

/**
 * Tries to insert a student into list.
 */
void insert(void)
{
    // try to instantiate node for student
    node *newptr = malloc(sizeof(node));////CREA un NODO y cuida que este si sea hecho
    if (newptr == NULL)
    {
        return;
    }

    // initialize node
    newptr->next = NULL;/////////mada su apuntador a NULLO

    // try to instantiate student
    newptr->student = malloc(sizeof(student));////CREA una STRUCT STUDENT dentro
    if (newptr->student == NULL)
    {
        free(newptr);/////si NO PUEDE borra el NODO
        return;
    }

    // try to initialize student    ////// RELLENA los datos
    printf("Student's ID: ");
    newptr->student->id = get_int();/////ID
    printf("Student's name: ");
    newptr->student->name = get_string();///NAME
    printf("Student's dorm: ");
    newptr->student->dorm = get_string();/////DORM
    if (newptr->student->name == NULL || newptr->student->dorm == NULL)//SI nuevo student NAME  o sudentt DORM INEXISTENTE
    {
        if (newptr->student->name != NULL)
        {
            free(newptr->student->name);/////Borra NAME
        }
        if (newptr->student->dorm != NULL)
        {
            free(newptr->student->dorm);////borra DORM
        }
        free(newptr->student);//////libera STRUCT STUDENT
        free(newptr);///////Libera el NODO
        return;
    }

    /////////BUSCA DONDE COLOCARLO ////////////
    // check for empty list
    if (root== NULL)//////////si hasta arriva est vacio
    {
        root= newptr;///////hace que rootaputne hacia NEW
    }

    // else check if student belongs at list's head
    else if (newptr->student->id < root->student->id)///si va antes que root
    {
        newptr->next = root;//////hace que NEW NEXT apunte a root
        root= newptr;/////hace que NEW sea el nuevo root
    }

    // else try to insert student in middle or tail// EN medio o al final
    else
    {
        node *predptr = root;//////hace que pred prt apunte a root
        while (true)
        {
            // avoid duplicates // si STUDENT ID == a NEW STUDENT ID
            if (predptr->student->id == newptr->student->id)/////DUPLICADOS
            {
                free(newptr->student->name);///borra NAME
                free(newptr->student->dorm);//DORM
                free(newptr->student);//TODA la STRUTURA STUDENT
                free(newptr);/////Y el NODO
                break;//////SALIR
            }

            // check for insertion at tail // insertar hasta ATRAS
            else if (predptr->next == NULL)/// si pred ptr NEXT es NULLO
            {
                predptr->next = newptr;////hace que pred prt NEXT apunte al NEW
                break;//////SALIR
            }

            // check for insertion in middle/////en MEDIO
            else if (predptr->next->student->id   >   newptr->student->id)
            {///pred prt next  studen ID   MAYOR que NEW STUDENT ID
                newptr->next = predptr->next; ///NEW NEXT apunta hacia donde apuenta pred ptr NEXT
                predptr->next = newptr;/////pred prt est NEW
                break;//////SALIR
            }

            // update pointer
            predptr = predptr->next;////actualiza los datos pred ptr == a pred ptr NEXT
        }////asi el programa sigue cambiando datos mientras no caiga en ese if
    }

    // traverse list
    traverse();////MOSTRAR todo
}


/**
 * Searches for student in list via student's ID.
 */
void search(void)
{
    // prompt user for ID
    printf("ID to search for: ");
    int id = get_int();/////////numero a BUSCAR

    // get list's rootnode
    node *ptr = root;///////prt apunta a root

    // search for student
    while (ptr != NULL)////mientras ptr no se NULLO
    {
        if (ptr->student->id == id)/////si lo encuentras
        {
            printf("\nFound %s of %s (%i)!\n", ptr->student->name, ptr->student->dorm, id);///imprime
            sleep(1);/////////////found NAME of DORM (ID)!
            break;///Salir
        }
        ptr = ptr->next;/////actualiza el nodo prt = prt next
    }
}

/**
 * Traverses list, printing its numbers.
 */
void traverse(void)//////mostrar lista
{
    // traverse list
    printf("\nLIST IS NOW: ");
    node *ptr = root;//////prt apunta a root
    while (ptr != NULL)////mientras prt diferente de NULLO
    {
        printf("%s of %s (%i)  ", ptr->student->name, ptr->student->dorm, ptr->student->id);
        ptr = ptr->next;////imprime NAME of DORM (ID)
    }//////cambia de nodo

    // pause before continuing
    sleep(1);
    printf("\n\n");/////imprime doble \n
}
