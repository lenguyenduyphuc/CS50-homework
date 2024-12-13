#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int numbers[] = {10,20,500,100,5,10,50,1};
    int n = get_int("Numbers? ");
    for (int i = 0; i< 7; i++)
    {
        if ((numbers[i]) == n)
        {
            printf("Find\n");
            return 0;
        }
    }
    printf("breh\n");
    return 1;
}
