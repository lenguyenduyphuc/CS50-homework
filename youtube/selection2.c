#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>


int main(void)
{
    int m;
    int array[] = {7,5,6,8,0,3,1,2,4};
    bool n = true;
    for (int j = 0; j<9; j++)
    {
        for (int i = 0; i < 8; i++){
            if (array[i] > array[i+1])
            {
                m = array[i];
                array[i] = array[i+1];
                array[i+1] = m;
            }
        }
    }
    for (int i = 0; i < 9; i++)
    printf("%i\n", array[i]);
    return 0;
}
