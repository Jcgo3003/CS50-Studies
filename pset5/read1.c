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

///setting a new root
node *root = NULL;

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

    // open input file
    FILE *inptr = fopen(infile, "r");//Pointer inptr   and opens the file with the name of the comand line
    if ( inptr == NULL )              //Keeping the program safe
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

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

                }
                else if ( ptr->next[num] != NULL ) // if node doest EXIST
                {
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
                        fprintf(stderr, "Error! Could not create next node\n");
                        break;
                    }
                    for( int i = 0; i < alpha; i++)
                    {
                        newnode->next[i]=NULL;
                    }

                    ptr2->next[num]= newnode;  // new node asinated to ptr2 -> next [ num ]
                    ptr = ptr2->next[num];     // ptr will point to ptr2 -> next [ num ] - (the new node)
                }
                else if (  ptr2->next[num] != NULL )// if node doest exist
                {
                    ptr = ptr2->next[num];   // ptr will point to ptr2 -> next [ num ] - (node in next[num] )
                }
            }

            printf("c%i ", c);
            printf("%i ", num);///EN vez de este creara el nodo
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