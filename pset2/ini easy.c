#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main (void)
{
    string s = get_string(); /// I get the string from the user
    
    int cnt_spa = 0;        ///i start int cnt_spa for keep track of the number of spaces
    for(int a= 0 , n = strlen(s); a < n; a++)///this for will let me know the number of spaces
    {
        if (s[a] == ' ')
        {
            cnt_spa = cnt_spa + 1;
        }
    }
    int es = cnt_spa;
    
    int loc [es];      ///I start my array Loc to keep track in what number of the string are th spaces

    int b = 0, i = 0;       /// This 2 ints will going to be my courters
    while (cnt_spa > 0)    /// while cnt_spa 'aka' number of spaces > 0 keep doing this
    {
        while(s[i] != ' ') ///while the string s[i] != of ' ' keep
        {
           i++;             /// adding 1 to i 
        }
        loc[b]= i;       /// when s[i] = ' ' then i = log[c] !!!!!!aqui estoy cambiando la localizacion con +1!!!!
        
        i = loc[b]+1;       ///then i = to log[c] + 1 so the while will keeppp going to the next ' '!!!!!no confundir
        
        printf("%c", toupper (s[loc[b]+1]));/// es importante dejarlo aqui !!!!!!
        
        b ++;             ///then add 1 to c
        
        cnt_spa= cnt_spa -1;/// at the end subtract 1 fromm the cnt_spa aka number of spaces
    
        
    }   /// now i know in which number are the ' ' and it's stored in loc[c]
    printf("\n");

}