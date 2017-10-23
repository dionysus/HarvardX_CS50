
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("Minutes: ");
    int i = get_int();
    printf("Bottles: %i\n", i * 12);
}