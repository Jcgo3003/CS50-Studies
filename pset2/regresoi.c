#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int cnt_spa (void);

int main (void)
{
    string s = get_string();  /// I get the string from the user
    int str = strlen(s)
    printf("Numero de spacios %i", cnt_spa)
}


int cnt_spa(int n)
{
    int spa = 0;
    for(int a = 0; a < n; a++) 
    {
        if (s[a] == ' ')
        {
            spa = spa + 1;
        }
    }
    return spa;
}