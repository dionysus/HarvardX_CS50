#include <cs50.h>
#include <stdio.h>
#include <string.h>

void initials (string s);

int main (void)
{
    string s = get_string();
    initials (s);
    printf("\n");
}

void initials (string s)
{
    int length = strlen(s);

    // Loop through each letter of the string
    for (int i = 0; i <= length -1; i++)
    {
        // if letter is not a space
        // and is the first letter or the letter before it is a space.
        if (s[i] != ' ' && (s[i-1] == ' ' || i == 0))
        {
            //if letter is lower case, return Upper Case
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                printf("%c", s[i] - 32);
            }

            // if letter is already upper case, return lower case
            else
            {
                printf("%c", s[i]);
            }

        }
    }

}