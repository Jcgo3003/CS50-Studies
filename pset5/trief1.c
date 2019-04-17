#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <cs50.h>
#include <ctype.h>
#define  alpha 27


// Defining struct node
typedef struct node
{
    bool is_word;
    struct node *next[alpha];
}
node;

// linked list
node *root = NULL;

// prototypes
void insert(char *infile);
void search(void);
void delete( node *ptr);

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./read infile outfile\n");
        return 1;
    }

    // remember file names
    char *infile = argv[1];             //Name infile


    //Creating root
    if( root == NULL)
    {
        node *newroot = malloc(sizeof(node));
        if ( newroot == NULL )
        {
            fprintf(stderr,"Could not create ROOT node\n");
        }

        for( int i = 0; i < alpha; i++)
        {
            newroot->next[i]=NULL;
        }
        root = newroot;
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
            case 1: insert(infile); break;
            case 2: search(); break;
            case 3: delete( ptr ); break;
        }
    }
    while (c != 0);

}

/**
 * Tries to insert a number into list.
 */
void insert(char *infile)
{
    // open input file
    FILE *inptr = fopen(infile, "r");//Pointer inptr   and opens the file with the name of the comand line
    if ( inptr == NULL )              //Keeping the program safe
    {
        fprintf(stderr, "Could not open %s.\n", infile);
    }

    // Buffer and couters
    char buffer = 'p';
    int  c = 1;
    int num = 0;

    // Creating next nodes
    node *ptr = root;
    node *ptr2 = NULL;

    // reading words and building nodes
    while( buffer != EOF )
    {
        buffer = fgetc(inptr);// Reading the file

        // Transforming the letters into numers
        num = buffer - 97;///necesito que se acuerde cada vez del numero anterior

        //getting a number for " ' "
        if (buffer == '\'')
        {
        num = 26;
        }

        // building nodes
        if ( (num >= 0 && num <= 26) ) // || (num_b >= 0 && num_b <= 26) )//protejo el programa de signos raros
        {
            printf("c%i ", c);
            // Odd number
            if( c%2 != 0 )
            {
                if ( ptr->next[num] == NULL) // if node doest NOT EXIST
                {
                    node *newnode = malloc(sizeof(node));
                    if (newnode == NULL)
                    {
                        fprintf(stderr, "Error! Could not create next node\n");
                        break;
                    }
                    for( int i = 0; i < alpha; i++)
                    {
                        newnode->next[i]=NULL;
                    }
                    ptr->next[num] = newnode; // new node asinated to ptr -> next [ num ]
                    ptr2 = ptr->next[num];    // ptr2 will point to ptr -> next [ num ] - (the new node)
                    printf("%i ", num);

                }
                else if ( ptr->next[num] != NULL ) // if node doest EXIST
                {
                    ptr2 = ptr->next[num];   // ptr2 will point to ptr -> next [ num ] - (node in next[num] )
                    printf("%i ", num);
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
                        fprintf(stderr, "Error! Could not create next node\n");
                        break;
                    }
                    for( int i = 0; i < alpha; i++)
                    {
                        newnode->next[i]=NULL;
                    }
                    ptr2->next[num]= newnode;  // new node asinated to ptr2 -> next [ num ]
                    ptr = ptr2->next[num];     // ptr will point to ptr2 -> next [ num ] - (the new node)
                    printf("%i ", num);
                }
                else if (  ptr2->next[num] != NULL )// if node doest exist
                {
                    ptr = ptr2->next[num];   // ptr will point to ptr2 -> next [ num ] - (node in next[num] )
                    printf("%i ", num);
                }
            }


           ///printf("%i ", num);///EN vez de este creara el nodo
            c ++;///creo que este contador me va ayudar a la hora de hacer las uniones
        }

        // Closing the node
        if (buffer == '\n'|| buffer == EOF)///
        {
            if ( (c-1)%2 != 0)//if c is odd
                ptr2->is_word = true;
            else
                ptr->is_word = true;

            ptr = root;
            ptr2 = NULL;

            printf(" C M%i", c-1);
            printf("\n");
            c = 1;
        }
    }
    fclose(inptr);
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

    while ( c < 10)
    {
        printf("Introduce the numbers of letter you are looking for\n");
        printf("%i ",c);
        num = get_int();
        // Odd number
        if ( ( c%2 ) != 0)
        {
            if( ptr->next[num] != NULL )  // if node Exist
            {
                printf("Node Exists\n");
                ptr2 = ptr->next[num];/// ptr2 points to the next [ num ] pointer
                if ( ptr2->is_word == true )
                    printf("TRUE \n");
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
                if ( ptr->is_word == true )
                    printf("TRUE \n");
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
            //printf( "%s\n",  ptr->name );
        }
        c++;
    }
}


/**
 * Searches for a number in list.
 */
///(struct TrieNode* root, char str[], int level)
void delete( node *ptr )
{
    if ( ptr->next[0]==NULL && ptr->next[1]==NULL && ptr->next[2]==NULL && ptr->next[3]==NULL && ptr->next[4]==NULL &&
        ptr->next[5]==NULL && ptr->next[6]==NULL && ptr->next[7]==NULL && ptr->next[8]==NULL && ptr->next[9]==NULL &&
        ptr->next[10]==NULL && ptr->next[11]==NULL && ptr->next[12]==NULL && ptr->next[13]==NULL && ptr->next[14]==NULL &&
        ptr->next[15]==NULL && ptr->next[16]==NULL && ptr->next[17]==NULL && ptr->next[18]==NULL && ptr->next[19]==NULL &&
        ptr->next[20]==NULL && ptr->next[21]==NULL && ptr->next[22]==NULL && ptr->next[23]==NULL && ptr->next[24]==NULL &&
        ptr->next[25]==NULL && ptr->next[26]==NULL  )
        {
            free(ptr);
        }
    else
    {
        for( int j = 0; j < alpha; j++)
        {
            if ( ptr->next[j] != NULL)
            {
                node *ptr2 = ptr->next[j];
                delete(ptr2);
            }
        }
        free(ptr);
    }
}