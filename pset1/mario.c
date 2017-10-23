#include <cs50.h>
#include <stdio.h>

void row(int n, int h);

int main(void)
{
    printf("Height: ");
    int h = get_int();

    // Test for valid integer less than 24
    if (h >= 0 && h < 24)
    {
        // Return Row() for each row up to height
        for (int i = 0; i < h; i++)
        {
            row(i, h);
        }
    }

    // Repeat if number is invalid
    else
    {
        main();
    }

}

// Print pattern for each row
void row(int r, int h)
{
    // Columns for height + 1
    for (int i = 0; i < h + 1; i++)
    {
        // Print blank spaces (height - row)
        if (i < h - r - 1)
        {
            printf(" ");
        }

        // Print blocks for rest
        else
        {
            printf("#");
        }
    }

    // new line
    printf("\n");
}