#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
    //input
    int n;
    scanf("%d", &n);
    if (n == 0)
    {
        return 1;
    }

    typedef struct
    {
        int value;
        int key;
    } attempt;

    for (int i = 0; i < n; i++)
    {
        int j;
        scanf("%d", &j);
        attempt[i].value = j;
        attempt[i].key = i;
    }

    //sort
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = (i+1); j < (n-1); j++)
        {
            if (attempt[i].value < attempt[j].value)
            {
                temp = attempt[i].value;
                attempt[i].value = attempt[j].value;
                attempt[j].value = temp;
            }
        }
    }
    int count = 0;



    for (int i = 0; i < n; i++)
    {
        printf("%i\n", a[i]);
    }
}
