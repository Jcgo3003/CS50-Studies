#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Defining struct node
typedef struct node
{
    string name;
    struct node *next[10];
}
node;

// linked list
node *root = NULL;

// prototypes
void insert(void);
void search(void);
void delete( node *ptr, int n);

int main(void)
{
    //Creating the root
    if( root == NULL)
    {
        node *newroot = malloc(sizeof(node));
        if ( newroot == NULL )
        {
            fprintf(stderr,"Could not create ROOT node\n");
        }
        for( int i = 0; i < 10; i++)
        {
            newroot->next[i]=NULL;
        }
        newroot->name = "Root";
        root = newroot;//setting new node as root

    }

    node *ptr = root;

    int c;
    do
    {
        // print instructions
        printf("\n  MENU TRIES\n\n"
            "1 - insert\n"
            "2 - search\n"
            "0 - quit\n\n");

        // get command
        printf("Command: ");
        c = get_int();

        // try to execute command
        switch (c)
        {
            case 1: insert(); break;
            case 2: search(); break;
            case 3: delete( ptr, 0 ); break;
        }
    }
    while (c != 0);

// free list before quitting
    // node *ptr = root;// hago que ptr  apunte a root
    // while (ptr != NULL)////mientras ptr sea diferente de NULL
    // {
    //     node *predptr = ptr;////crea un ptr2 y hace que apunte hacia ptr
    //     ptr = ptr->next;///ptr apunta hacia el proximo
    //     free(predptr);///borra al nuevo
    // }
/////esto funciona porque va de abajo hacia arriva pero cuando son varios
/////


}

/**
 * Tries to insert a number into list.
 */
void insert(void)
{
    printf("Introduce the numbers of the year of the university\n");
    int num;
    // using c to count the order i get the numbers
    int c = 1;

    node *ptr = root;
    node *ptr2 = NULL;

    while ( c < 5)
    {
        printf("%i ", c);
        num = get_int();
        {
            // Odd number
            if( c%2 != 0 )
            {
                if ( ptr->next[num] == NULL) // if node doest not exist
                {
                    node *newnode = malloc(sizeof(node));
                    if (newnode == NULL)
                    {
                        printf("Error! Could not create next node\n");
                        break;
                    }
                    for( int i = 0; i < 10; i++)
                    {
                        newnode->next[i]=NULL;
                    }
                    printf("Creating new node\n");
                    ptr->next[num] = newnode; // new node asinated to ptr -> next [ num ]
                    ptr2 = ptr->next[num];    // ptr2 will point to ptr -> next [ num ] - (the new node)
                }
                else if ( ptr->next[num] != NULL ) // if node doest exist
                {
                    printf("This node exist\n");
                    ptr2 = ptr->next[num];   // ptr2 will point to ptr -> next [ num ] - (node in next[num] )
                }
            }
            // Even number
            else if( (c%2) == 0 )
            {
                if( ptr2->next[num] == NULL ) // if node doest not exist
                {
                   node *newnode = malloc(sizeof(node));
                    if (newnode == NULL)
                    {
                        printf("Error! Could not create next node\n");
                        break;
                    }
                    for( int i = 0; i < 10; i++)
                    {
                        newnode->next[i]=NULL;
                    }
                    printf("Creating new node\n");
                    ptr2->next[num]= newnode;  // new node asinated to ptr2 -> next [ num ]
                    ptr = ptr2->next[num];     // ptr will point to ptr2 -> next [ num ] - (the new node)
                }
                else if (  ptr2->next[num] != NULL )// if node doest exist
                {
                    printf("This node exist\n");
                    ptr = ptr2->next[num];   // ptr will point to ptr2 -> next [ num ] - (node in next[num] )
                }
            }
            // Getting the university name
            if (c == 4)
            {
                printf("\nName of the university: ");
                ptr->name = get_string();
                printf("\n");
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
    node *ptr2 = NULL;
    int num;

    // Counter for the order i get the numbers
    int c = 1;

    while ( c < 5)
    {
        printf("Introduce the numbers of the year of the university\n");
        printf("%i ",c);
        num = get_int();
        // Odd number
        if ( ( c%2 ) != 0)
        {
            if( ptr->next[num] != NULL )  // if node Exist
            {
                printf("Node Exists\n");
                ptr2 = ptr->next[num];/// ptr2 points to the next [ num ] pointer
            }
            else if( ptr->next[num] == NULL ) // If node does not exist
            {
                printf("Node does not exists\n");
                break;
            }
        }
        // even number
        if ( ( c%2 ) == 0)
        {
            if( ptr2->next[num] != NULL ) // if node Exist
            {
                printf("Node Exist\n");
                ptr = ptr2->next[num];//ahora ptr es el nodo seleciondo
            }
            else if( ptr2->next[num] == NULL ) // If node does not exist
            {
                printf("Node does not exists\n");
                break;
            }
        }
        // printing the university name
        if (c == 4)
        {
            printf( "\nUniversity name: ");
            printf( "%s\n",  ptr->name );
        }
        c++;
    }
}
/**
 * Searches for a number in list.
 */
///(struct TrieNode* root, char str[], int level)
void delete( node *ptr , int i)
{
    ////Caso base
    if ( ptr->next[i] == NULL)//al momento de entrar ptr esta apuntando a root i sera el numero que se esta
    {               ///que se revisara y esta iterando de la siguiente manera
        printf(" %s \n", ptr->name);////cuando encuentra un nodo final imprime su nombre
    }
    ////quiero que se meta a cada nodo y
    ///corre un contador
    for( int j = 0; j < 10; j++)///if ptr apuntado de
    {
        if ( ptr->next[j] )///si verdadero
        {
            printf(" %i ", j );///imprime el numero en el que lo encontro
            node *ptr2 = ptr->next[j];///creo ptr2 apunto al siguiente nodo
            delete( ptr2 , j );///ahora hago que el siguiente nodo apuntado sea caso siguiente
        }/////se metio ese nodo y si

    }





}