#include <stdio.h>
#include <cs50.h>



int main(void)
{
    int x = get_int("x? ");
    int y = get_int("y? ");
    double z = (double) x / (double) y;
    printf(".30%f\n", z);
}

