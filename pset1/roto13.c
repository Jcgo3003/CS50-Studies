#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (void)
{
    printf("Dame un numero ");
    long long n = get_long_long();

    int a = n * pow(10,-11);
    n = n - (a*pow(10,11));
    
    int b = n * pow(10,-9);
    n = n - (b*pow(10,9));
    
    int c = n * pow(10,-7);
    n = n - (c*pow(10,7));
    
    int d = n * pow(10,-5);
    n = n - (d*pow(10,5));
    
    int e = n * pow(10,-3);
    n = n - (e*pow(10,3));

    int f = n * pow(10,-1);
    n = n - (f*pow(10,1));
    
    int g = n;

    printf("A  %i \n", a);
    printf("B  %i \n", b);
    printf("C  %i \n", c);
    printf("D  %i \n", d);
    printf("E  %i \n", e);
    printf("F  %i \n", f);
    printf("G  %i \n", g);
}