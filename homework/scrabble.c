#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int count(string a);
string upper(string b);

int main(void)
{
    string a = (get_string("Player1: "));
    string b = (get_string("Player2: "));
    a = upper(a);
    b = upper(b);

    int i = count(a);
    int j = count(b);
    if (i > j)
    {
        printf("Player 1 wins!\n");
    }
    else if (i < j)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int count(string a)
{
    int count = 0;
    for (int i = 0, n = strlen(a); i < n; i++)
    {
        if ((a[i] == 'A') || (a[i] == 'I') || (a[i] == 'L') || (a[i] == 'N') || (a[i] == 'O') || (a[i] == 'R') || (a[i] == 'S') ||
            (a[i] == 'T') || (a[i] == 'U'))
        {
            count++;
        }
        else if ((a[i] == 'D') || (a[i] == 'G'))
        {
            count += 2;
        }
        else if ((a[i] == 'B') || (a[i] == 'C') || (a[i] == 'M') || (a[i] == 'P'))
        {
            count += 3;
        }
        else if ((a[i] == 'H') || (a[i] == 'F') || (a[i] == 'V') || (a[i] == 'W') || (a[i] == 'Y'))
        {
            count += 4;
        }
        else if (a[i] == 'K')
        {
            count += 5;
        }
        else if ((a[i] == 'J') || (a[i] == 'X'))
        {
            count += 8;
        }
        else if ((a[i] == 'Q') || (a[i] == 'Z'))
        {
            count += 10;
        }
    }
    return count;
}

string upper(string b)
{
    for (int i = 0, n = strlen(b); i < n; i++)
    {
        b[i] = toupper(b[i]);
    }
    return b;
}
