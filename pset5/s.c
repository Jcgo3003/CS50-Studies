
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "list0.h"///libraries

node *head = NULL;

void delete(void);
void insert(void);

void traverse(void);

int main(void)
{
    int c;/////creates c
    do/////start a do while for the main menu
    {
        // print instructions////here's the main menu
        printf("\nMENU\n\n"
            "1 - crea\n"
            "2 - borrar\n"
            "3 - mostrar\n"
            "0 - Salir\n\n");

        // get command
        printf("Command: ");///obteniendo el numero de usuario
        c = get_int();

        // try to execute command
        switch (c)/////here c depending on the number going exeute a p
        {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: traverse(); break;
        }
    }
    while (c != 0);//Si les das 0 el programa sale

    printf(" Saliendo \n");///////imprimo el resultado via el segundo apuntador

    // free list before quitting
    node *bus = head;//creo otro puntero que apunta hacia head

    while (bus != NULL)//si head tiene algo
    {

        node *bus2 = segundo;///crea tercero apuntado hacia buscador

        bus  = bus -> next;///hace que bus apunta hacia NEXT



        free(bus2);// borra a bus2 es decir donde estaba bus, los
        //regresa hasta arriva
        ///crea otra vez bus2 y hace que sea igual a bus
        ////hace que bus apunte a bus next y borra bus2 es decir bus original
    }

}

/**
 * Tries to insert a number into list.
 */
void insert(void)
{
    // try to instantiate node for number//////crea un nodo para un numero
    node *nuevo = malloc(sizeof(node));///////crea nodo nuevo del tamano de nodo
    if (nuevo == NULL)////////lo protege en caso de no poder crearlo
    {
        return;
    }////////para que no explote

    // initialize node////////////////
    printf("Number to insert: ");///////inserta un numero al tal nodo
    nuevo->n = get_int();// inserta directamente en NUMERO
    nuevo->next = NULL;/// flecha la hace nulla

    // check for empty list revisa la lista
    if (bus == NULL)/////////si primer est nulo o esta vacio //////VACIO//////////
    {
        head = nuevo;/////////hace que head apunte a head
    }

    // else check if number belongs at list's head///////revisa el orden de ese numero
    else if (nuevo->n < primer->n)///si el numero que esta en n es MENOR   <  que el que esta en primer N
    {
        nuevo->next = primer;//// NEXT de nuevo sera a lo que apunte primer, CAMBIA de lugar con primer, en NEXT coloca el numero antiguo
        primer = nuevo;/////ahora primer es el NUEVO NUMERO
    }

    // else try to insert number in middle or tail
    else
    {
        node *tercero = primer;////hace que tercero sea primero
        while (true)//////mientras verdadero
        {
            // avoid duplicates
            if (tercero->n == nuevo->n)///////si tercero N es igual a N de nuevo
            {
                free(nuevo);///////////libera nuevo ////BORRALO
                break;
            }

            // check for insertion at tail/////////para insertarlo al final
            else if (tercero->next == NULL)////si segundo NEXT es nulo
            {
                tercero->next = nuevo;///////segundo next es IGUAL a NUEVO LO coloco al FINAL
                break;
            }

            // check for insertion in middle
            else if (tercero->next->n   >   nuevo->n)/////////si segundo NEXT  "N"  mayor  que Nuevo N
            {
                nuevo->next = tercero->next;//////DIRIGE  NEXT de nuevo hacia NEXT segundo
                tercero->next = nuevo;///////////NEXT se dirige hacia NUEVO///////Lo esta metiendo en MEDIO
                break;
            }

            // update pointer
            tercero = tercero->next;////Segundo apunta hacia DONDE APUNTA NEXT
        }
    }

    // traverse list
    traverse();
}
/**
 * Tries to delete a number.
 */
void delete(void)
{
    // prompt user for number
    printf("Number to delete: ");//////entra a este programa y le dice al usuario number to delete
    int n = get_int();///////////////obtiene aquel numero

    // get list's rootnode///obtiene el primer nodo de la lista
    node *segundo = primer;////crea un puntero a primero

    // try to delete number from list
    node *tercero = NULL;/////crea un terecero puntero NULO
    while (segundo != NULL)////mientras segundo sea diferente de NULO es decir si hay algo entrar aqui
    {
        // check for number
        if (segundo->n == n)//////si en numero en segundo es igual a n
        {
            // delete from head//////aqui borra a segundo porque segundo el quie lleva n
            if (segundo == primer)//////si segundo es igual que el primero////
            {
                primer = segundo->next;//////primer = NEXT en segundo /////hace que primero apunte a donde NEXT
                free(segundo);//////////////libera segundo
            }

            // delete from middle or tail
            else
            {
                tercero->next = segundo->next;
                free(segundo);
            }

            // all done
            break;
        }
        else////si en segundo  no estaba aquel numero entonces  tercero
        {
            tercero = segundo;///////////////tercero es igual a segundo////los dos estan apuntando hacia el mismo lugar
            segundo = segundo->next;//////////hace que segundo apunte hacia el mismo en NEXT
        ///////tercero es lo que fue segundo, sengundo ahora es el siguiente node, hacie lo hara hasta encuntre NULLO
        }
    }
    // traverse list
    traverse();
}

void search(void)
{
    // prompt user for number
    printf("Number to search for: ");///imprime en pantalla blabla
    int n = get_int();////guarda el numero en n

    // get list's rootnode
    node *segundo = primer;//// hace que apunte a la cabeza?

    // search for number
    while (segundo  != NULL)/////mientras segundo sea diferente de NUllO es decir mientras haya algo en
    //////////segundo
    {
        if (segundo->n == n)////////si el numero en segudo es igual a n
        {
            printf("\nFound %i!\n", n);//////imprimir encontrado
            sleep(1);
            break;
        }
        segundo = segundo->next;////hace que segundo apunte a NEXT
    }
}


void traverse(void)
{
    // traverse list
    printf("\nLIST IS NOW: ");////muestra la lista
    node *segundo = primer;//////
    while (segundo != NULL)////////mientras segundo sea dif de NULO
    {
        printf("%i ", segundo->n);////hace el puntero segudo muestre n
        segundo = segundo->next;////////apunta al siguiente struc
    }

    // pause before continuing
    sleep(1);
    printf("\n\n");

}

    // int *b = malloc (sizeof(int));
    // int m = 1;
    // int *a;

    // *b = 12;/////para asinar valores a b tengo que decirle que es un puntero *  y darle un valor
    // printf("B %i\n", *b );

    // a = b;/////////ambos son punteros no necesita mas nada
    // *a = 1222;
    // printf("B2 %i\n", *b );


    // printf("m %i\n",m );
    // a = &m;//////m es una integral regular////// entones asi se junta un puntero con una integral regulas por emdio de &
    // *a = 1999;///////para asignar valores tengo que decirle que es un puntero primero
    // printf("m %i\n",m );

    // printf("a %i \n", *a);
    // a = b;///b no lo es por lo que no me deja juntarla con a = &b
    // ////se tiene que hacer de esta manera a = b ambos son aputandores por lo que se entienden asi  entre ellos
    // printf("a2 %i \n", *a);


    // free(b);/////libero b