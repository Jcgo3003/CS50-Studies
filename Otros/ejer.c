#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int a[]={1,4,2,3,6};
    a[4] = a[1]*a[3];
    printf("1 es igual %i\n", a[0]);
    printf("1 es igual %i\n", a[1]);
    printf("1 es igual %i\n", a[2]);
    printf("1 es igual %i\n", a[3]);
    printf("1 es igual %i\n", a[4]);
    
    printf("a4 es igual %i\n", a[4]);
}