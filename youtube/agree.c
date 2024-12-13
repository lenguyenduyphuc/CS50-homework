#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char c = get_char("do you agree? ");
    if  (c == 'n' || c =='N')
    {
        printf("No\n ");
    }
}
