#include <stdio.h>
#include <cs50.h>

int main (void)
{
    char res = 'a';
    while( res!='n' || res!='N')
    {
        printf("Dame un numero ");
        int num = get_int();

        printf("Tu numero es %i\n", num);
        printf("Quires continuar y/n ");
        res = get_char();
        if (res == 'y' || res =='Y')
        {
            printf("Aqui vamos de nuevo  \n");
        }
        else if (res == 'n'|| res == 'N')
        {
            printf("GAME OVER  \n");
            break;
        }
        else
        {
            printf("Error!!!!!!! \n");
        }

    }


}