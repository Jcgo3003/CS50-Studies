#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main (void)
{
  int n = get_int();
  while ( n >= 0)
  {
   printf("comienza %i\n", n);
   n--;
  }
  printf("\n");
  printf("termina int es %i\n",n);
}
 

 
 
 