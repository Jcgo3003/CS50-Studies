
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "list0.h"///libraries

// linked list
node *primer = NULL;/////node- tipo de dato, rootes como se llama esta fijado a nullo
/////////pero como es global nunca deja de ser nulo???
int *p = NULL;/////como es un puntero que esta apuntando hacia nada

// prototypes
void delete(void);
void insert(void);
void search(void);
void traverse(void);/////declares all the programs

int main(void)
{
    int c;/////creates c
    do/////start a do while for the main menu
    {
        // print instructions////here's the main menu
        printf("\nMENU\n\n"
            "1 - delete\n"
            "2 - insert\n"
            "3 - search \n"
            "4 - traverse\n"
            "0 - quit\n\n");

        // get command
        printf("Command: ");////getting the comenad from the user
        c = get_int();

        // try to execute command
        switch (c)/////here c depending on the number going exeute a p
        {
            case 1: delete(); break;
            case 2: insert(); break;
            case 3: search(); break;
            case 4: traverse(); break;
        }
    }
    while (c != 0);//////aqui termina el programa hacer lo anterios mientras c != 0



    int *m = malloc(sizeof(int));////creo el espacio con el apuntado pauntado hacia el
    *m = 100;/////le doy un valor
    p = m;////////apunto m hacia mi
    *p = 423;////////////utlizado el seegundo apuntado asigno otro valor a m

    printf(" p %i \n",*p);///////imprimo el resultado via el segundo apuntador

    // free list before quitting
    node *segundo = primer;/////creo el segundo puntero que apunta a roototro puntero

    while (segundo != NULL)//mientras segundo sea diferente de nulo-- segundo apunta hacia primer
    {///////////////////////mientras haya algo en root

        node *tercero = segundo;///pero este tambien es un apundador !!!!!!!!!!

        segundo  = segundo -> next;///aqui el segundo apuntador entra en si mismo y se apunta a next
        ///////////!!!!!!!!!!!!!!

        // printf("Segundo\n");

        free(tercero);////////libera a tercero

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
    }

    // initialize node////////////////
    printf("Number to insert: ");///////inserta un numero al tal nodo
    nuevo->n = get_int();///////guarda el numero en n
    nuevo->next = NULL;/// manda su flecha en nullo

    // check for empty list
    if (primer == NULL)/////////si primer est nulo o esta vacio //////VACIO//////////
    {
        primer = nuevo;/////////hace que primero apunte a nuevo
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