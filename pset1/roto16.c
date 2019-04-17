#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (void)
{
    printf("Dame un numero ");
    long long n = get_long_long();

    int a = n * pow(10,-14);
    printf("ant %i\n",a);
    n = n - (a*pow(10,14));
    printf("ant %i\n",a);
    int id = a;
    
    int b = n * pow(10,-12);
    n = n - (b*pow(10,12));
    
    int c = n * pow(10,-10);
    n = n - (c*pow(10,10));
    
    int d = n * pow(10,-8);
    n = n - (d*pow(10,8));

    int e = n * pow(10,-6);
    n = n - (e*pow(10,6));

    int f = n * pow(10,-4);
    n = n - (f*pow(10,4));

    int g = n * pow(10,-2);
    n = n - (g*pow(10,2));

    int h = n;
    
    int a1 = a*.1;
    int b2 = b*.1;
    int c3 = c*.1;
    int d4 = d*.1;
    int e5 = e*.1;
    int f6 = f*.1;
    int g7 = g*.1;
    int h8 = h*.1;
    

    printf("A %i \n", a);
    printf("B %i \n", b);
    printf("C %i \n", c);
    printf("D %i \n", d);
    printf("E %i \n", e);
    printf("F %i \n", f);
    printf("G %i \n", g);
    printf("H %i \n", h);
    
    
    a = (((a%10*2)*.1)+(a%10*2)%10);
    b = (((b%10*2)*.1)+(b%10*2)%10);
    c = (((c%10*2)*.1)+(c%10*2)%10);
    d = (((d%10*2)*.1)+(d%10*2)%10);
    e = (((e%10*2)*.1)+(e%10*2)%10);
    f = (((f%10*2)*.1)+(f%10*2)%10);
    g = (((g%10*2)*.1)+(g%10*2)%10);
    h = (((h%10*2)*.1)+(h%10*2)%10);
    
    int mod1 = (a+b+c+d+e+f+g+h+a1+b2+c3+d4+e5+f6+g7+h8)%10;
    
    printf("\n");
    printf("A %i \n", a);
    printf("B %i \n", b);
    printf("C %i \n", c);
    printf("D %i \n", d);
    printf("E %i \n", e);
    printf("F %i \n", f);
    printf("G %i \n", g);
    printf("H %i \n", h);

    printf("Sum1 %i \n",a+b+c+d+e+f+g+h);
    printf("Sum2 %i \n",a1+b2+c3+d4+e5+f6+g7+h8);
    printf("mod1 %i \n",mod1);
    printf("id%i \n",id);

}

