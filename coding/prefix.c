#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(void)
{
    //get user input
    int n;
    scanf("%d", &n);
    char *s = malloc(250000*sizeof(char));
    scanf("%s", s);
    if (s == NULL)
    {
        return 1;
    }

    //change
    int j = strlen(s);

    int count = 0;

    for (int i = 0; i < j; i+=2)
    {
        if ((s[i] == 'b') && (s[i+1] == 'b'))
        {
            s[i] = 'a';
            count++;
        }
        if ((s[i] == 'a') && (s[i+1] == 'a'))
        {
            s[i] = 'b';
            count++;
        }
    }

    printf("%i\n", count);
    printf("%s\n", s);

    free(s);
}
