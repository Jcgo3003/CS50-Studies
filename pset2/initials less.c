#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main (void)
{
    string s = get_string();  /// I get the string from the user
    
    int spa0 = 0;               /// spa0 will keep the count of the number of spaces in 's'
    for (int a = 0, str = strlen (s); a < str; a++)
    {
        if (s[a] == ' ')
        {
            spa0 = spa0 + 1;
        }
        
    }
    int spa1 = spa0;        /// spa1 will also keep the count of spaces
 
    
    //////////////
    
    int loc [spa1];         /// this array will save the location of the spaces
    int b = 0, i = 0;       /// b and i will be my couters in this while
    
    printf("%c", toupper (s[0]));///this one will print  the firts leter of 's'
   
    while (spa0 > 0)        /// while spa0 > 0 keep doing this
    {
        while(s[i] != ' ')  /// while s[i] != ' ' 
        { 
            i++;            /// add 1 to i  
        }
        
        loc[b]= i;          /// save i in  loc [b]      
    
        i = loc[b]+1;       ///then i = add 1 to loc[b] so this while can keep going couting
        printf("%c", toupper (s[loc[b]+1])); /// printf s 'loc[b]+1' this will print the next char in s when a space is found
    
        b ++;               /// b++ so i'll be able to go to the next numberin my array loc
    
        spa0= spa0 - 1;     ///finally just subtract 1 from spa0 so thefirts do while will keep moving 
        
        
    }
    printf("\n");  ///print \n and finish
}