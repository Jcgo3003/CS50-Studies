#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main (void)
{
    string s = get_string();
    int a;
    int b, c, d = 100;
    
    for(int i= 0 , n = strlen(s); i < n; i++)
    {
        if (s[i] == ' ')
        {
            a = a+1;
        }
        
      if (s[i] == ' '|| i == 0 || b == 100)
        {
           b = (0);
        }
    
    }
    printf(" %i %i %i %i \n", a, b, c, d);
    
}