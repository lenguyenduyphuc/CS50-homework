#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int lenght(int array[]);

int main(void)
{
    int m;
    int array[] = {7,5,6,8,0,3,1,2,4};
    int n = lenght(array);
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++){
            if (array[j] < array[i])
            {
                m = array[i];
                array[i] = array[j];
                array[j] = m;
            }
        }
    }
    for (int i = 0; i < n; i++)
    printf("%i\n", array[i]);
    return 0;
}



int lenght(int array[])
{
    int count = 0;
    for(int i = 0; strcmp(array[i] != "\0") == false; i++)
    {
        count++;
    }
    return count;
}
