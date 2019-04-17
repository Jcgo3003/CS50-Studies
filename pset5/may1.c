#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main (void)
{
    string word = get_string();
    int num;
    for (int i = 0; i < (strlen(word)+1); i++)
    {
        if ( isupper(word[i]))
        {
            num = word[i] - 'A';
            printf("No%i", num );
        }
        else if ( islower(word[i]) )
        {
            num = word[i] - 'a';
            printf("no%i", num );
        }
        else if( word[i] == '\'')
        {
            num = 26;
            printf("So%i", num );
        }

    }




        // if ( i%2 != 0)
        // {
        //     if ( isupper(word[i]))
        //     {
        //         int num = word[i] - 'A';
        //         printf("No%i", num );
        //     }
        //     else if ( islower(word[i]) )
        //     {
        //         int num = word[i] - 'a';
        //         printf("no%i", num );
        //     }
        //     else if( word[i] == '\'')
        //     {
        //         int num = 26;
        //         printf("So%i", num );
        //     }
        // }
        // if ( i%2 == 0)
        // {
        //     if ( isupper(word[i]))
        //     {
        //         int num = word[i] - 'A';
        //         printf("Ne%i", num );
        //     }
        //     else if ( islower(word[i]) )
        //     {
        //         int num = word[i] - 'a';
        //         printf("ne%i", num );
        //     }
        //     else if( word[i] == '\'')
        //     {
        //         int num = 26;
        //         printf("Se%i", num );
        //     }
        // }



    printf("\n");
    printf("fin de programa\n");


}