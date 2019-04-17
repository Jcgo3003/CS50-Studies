#include <stdio.h>
#include <cs50.h>

void cough(int n);

int main(void)
{
    printf("dame un numero ");
    int a = get_int();
    
    cough(a);
}

void cough(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("cough\n");
    }
}
