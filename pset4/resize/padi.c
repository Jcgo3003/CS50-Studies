#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
           
#include "bmp.h"


int main (void)
{
    
    
    int Width = get_int();
    
    int padding =  (4 - (Width * sizeof(RGBTRIPLE)) % 4) % 4;
    printf(" Padding = %i\n", padding);
}