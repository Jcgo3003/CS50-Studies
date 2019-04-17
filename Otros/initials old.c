#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main (void)
{
    string s = get_string();  /// I get the string from the user
    if (s != NULL)  /// Just for protect the program
    {
    
    int spa0 = 0;               /// spa0 will keep the count of the number of spaces in 's'
    for (int a = 0, str = strlen (s); a < str; a++)
    {
        if (s[a] == ' ')
        {
            spa0 = spa0 + 1;
        }
        
    }
    int spa1 = spa0;        /// spa1 will also keep the count of spaces
    
    if (s[0] != ' ')      /// If the rootchar of s is different of ' ' means tht the user 
    {                     /// didn't made strage spaces at the begginir print out the firts letter in capital
        printf("%c", toupper (s[0]));
    } 
    
    //////////////
    if (spa1 != 0)
    {
    int loc [spa1];         /// this array will save the location of the spaces
    int b = 0, i = 0;       /// b and i will be my couters in this while
    
    while (spa0 > 0)        /// while spa0 > 0 keep doing this
    {
        while(s[i] != ' ')  /// while s[i] != ' ' 
        { 
            i++;            /// add 1 to i  
        }
        
        loc[b]= i;          /// save i in  loc [b]      
    
        i = loc[b]+1;       ///then i = add 1 to loc[b] so this while can keep going couting
        b ++;               /// b++ so i'll be able to go to the next numberin my array loc
    
        spa0 = spa0 - 1;     ///finally just subtract 1 from spa0 so thefirts do while will keep moving 
        
    }
    
    
        
    int r = 1, c = 1;       /// int r and c will be my couters for this while they start in 1 because my rootletter is  ' ' 
    while (spa1 - 1 > 0 )    /// So doing so i won't get my program crash that's why i also subtracting 1 from spa1 
        {
                
                
                while ( loc[c] != r )/// while loc[c]  is diffenret of r my couter go and ...
                {
                        printf("%c", toupper ( s[ loc[c-1] + 1 ])  );/// from loc c that containts my ' ' locations go to the previous
                        r = loc [c];///then make r the same value /// number of loc[c-1] and to that number add 1 so i will print out
                }                         /// the letter next to the space
                
                c ++;/// add 1 to c
                r ++;/// add 1 to r
                spa1 = spa1 - 1;///sutract 1 from spa1
        }

    printf("%c", toupper (s[ loc[c-1]+1 ]) );/// this program will only print the letters next a space this is
    printf("\n");/// to fix the last letter that wont be printed for the previos while
    }
    else
    printf("\n");/// so if the user input doesn't have ' ' i will get \n printed for the no space input
    }
}