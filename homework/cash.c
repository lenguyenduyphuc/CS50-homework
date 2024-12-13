#include <cs50.h>
#include <stdio.h>

int get_cent(void);
int a(int cent);
int b(int cent);
int c(int cent);
int d(int cent);

int main(void)
{
    int cent = get_cent();

    int quarter = a(cent);
    cent = cent - quarter * 25;

    int ten = b(cent);
    cent = cent - ten * 10;

    int five = c(cent);
    cent = cent - five * 5;

    int one = d(cent);

    int total = quarter + ten + five + one;
    printf("%i\n", total);
}

int get_cent(void)
{
    int cent;
    do
    {
        cent = get_int("Change Owed? ");
    }
    while (cent < 0);
    return cent;
}

int a(int cent)
{
    return cent / 25;
}

int b(int cent)
{
    return cent / 10;
}

int c(int cent)
{
    return cent / 5;
}

int d(int cent)
{
    return cent / 1;
}
