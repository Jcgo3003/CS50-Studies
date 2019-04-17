#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (void)
{
    printf("Number: ");
    long long n = get_long_long();
    
    if ( n < pow(10,12) )
    {
        printf("INVALID\n");

    }
    /////////////////////////////// 1
    else if ( n > (pow(10,12)-1) && n < pow(10,13) )
    {

    int a = n * pow(10,-11);
    n = n - (a*pow(10,11));
    int id = a;
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

    int a1 = a*.1;
    int b2 = b*.1;
    int c3 = c*.1;
    int d4 = d*.1;
    int e5 = e*.1;
    int f6 = f*.1;
    int g7 = g;
    a = (((a%10*2)*.1)+(a%10*2)%10);
    b = (((b%10*2)*.1)+(b%10*2)%10);
    c = (((c%10*2)*.1)+(c%10*2)%10);
    d = (((d%10*2)*.1)+(d%10*2)%10);
    e = (((e%10*2)*.1)+(e%10*2)%10);
    f = (((f%10*2)*.1)+(f%10*2)%10);
    int mod = (a+b+c+d+e+f+a1+b2+c3+d4+e5+f6+g7)%10;

    if (id>39 && id<50 && mod == 0)
    {
        printf("VISA\n");
    }
    else 
    {
        printf("INVALID\n");
    }

    }
    ///////////////////////////////////////3
    else if ( n > (pow(10,13)-1) && n < pow(10,14) )
    {
        printf("INVALID\n");

    }
    //////////////////////////////////////5
    else if ( n > (pow(10,14)-1) && n < pow(10,15) )
    {

    int a = n * pow(10,-13);
    n = n - (a*pow(10,13));
    int id = a;
    int b = n * pow(10,-11);
    n = n - (b*pow(10,11));
    int c = n * pow(10,-9);
    n = n - (c*pow(10,9));
    int d = n * pow(10,-7);
    n = n - (d*pow(10,7));
    int e = n * pow(10,-5);
    n = n - (e*pow(10,5));
    int f = n * pow(10,-3);
    n = n - (f*pow(10,3));
    int g = n * pow(10,-1);
    n = n - (g*pow(10,1));
    int h = n;
    
    int a1 = a*.1;
    int b2 = b*.1;
    int c3 = c*.1;
    int d4 = d*.1;
    int e5 = e*.1;
    int f6 = f*.1;
    int g7 = g*.1;
    int h8 = h;
    a = (((a%10*2)*.1)+(a%10*2)%10);
    b = (((b%10*2)*.1)+(b%10*2)%10);
    c = (((c%10*2)*.1)+(c%10*2)%10);
    d = (((d%10*2)*.1)+(d%10*2)%10);
    e = (((e%10*2)*.1)+(e%10*2)%10);
    f = (((f%10*2)*.1)+(f%10*2)%10);
    g = (((g%10*2)*.1)+(g%10*2)%10);

    int mod = (a+b+c+d+e+f+g+a1+b2+c3+d4+e5+f6+g7+h8)%10;
    
    if ((id == 34 || id == 37) && mod==0  )
    {
        printf("AMEX\n");
    }
    else
    {
        printf("INVALID\n");
    }
    }
    //////////////////////////////   6
    else if ( n > (pow(10,15)-1) && n < pow(10,16) )
    {

    int a = n * pow(10,-14);
    n = n - (a*pow(10,14));
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
    
    a = (((a%10*2)*.1)+(a%10*2)%10);
    b = (((b%10*2)*.1)+(b%10*2)%10);
    c = (((c%10*2)*.1)+(c%10*2)%10);
    d = (((d%10*2)*.1)+(d%10*2)%10);
    e = (((e%10*2)*.1)+(e%10*2)%10);
    f = (((f%10*2)*.1)+(f%10*2)%10);
    g = (((g%10*2)*.1)+(g%10*2)%10);
    h = (((h%10*2)*.1)+(h%10*2)%10);
    
    int mod = (a+b+c+d+e+f+g+h+a1+b2+c3+d4+e5+f6+g7+h8)%10;

    if (id>39 && id<50 && mod==0 )
    {
        printf("VISA\n");
    }
    else if(id>50 && id<56 && mod==0 )
    { 
        printf("MASTER\n");
    }
    else
    {
        printf("INVALID\n");
    }
    }
    /////////////////7 
    else if (  n > pow(10,16)-1)
    {
        printf("INVALID\n");
    }
}
