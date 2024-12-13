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

    if (n == 1)
    {
        printf("1");
        return 0;
    }

    typedef struct
    {
        int value;
        int key;
    } attempt;

    attempt a[n];

    for (int i = 0; i<n ; i++)
    {
        int j;
        scanf("%d", &j);
        a[i].value = j;
        a[i].key = i;
    }

    //sort
    int temp;
    for (int x = 0; x < n; x++)
    {
        for (int y = (x+1); y < (n-1); y++)
        {
            if (a[x].value < a[y].value)
            {
                temp = a[x].value;
                a[x].value = a[y].value;
                a[y].value = temp;
            }
        }
    }
    // int count = 0;
    // int m = 1;
    // int o = 1;

    // for (int i = 0; i < n; i++)
    // {
    //     if (i = 0)
    //     {
    //         count++;
    //         attempt[i].key = 1;
    //     }
    //     else
    //     {
    //         count =
    //     }
    // }



    for (int i = 0; i < n; i++)
    {
        printf("%i\n", a[i].value);
    }
}
