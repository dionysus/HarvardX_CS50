#include <cs50.h>
#include <stdio.h>
#include <string.h>

string encrypt (string s, int k);

int main (int argc, string argv[])
{
    // works when command line has 2 entries (./caesar k)
    if (argc == 2)
    {
        printf("plaintext: ");
        string s = get_string();


        int k = atoi(argv[1]);
        string t = encrypt (s, k);

        printf("ciphertext: %s\n", t);
        return 0;
    }

    // error if command line has no entries, or more than one entry
    else {
        printf("Usage: ./caesar k");
        return 1;
    }


}

// shift string
string encrypt (string s, int k)
{

    int length = strlen(s);


    // Loop through each letter of the string
    for (int i = 0; i <= length -1; i++)
    {

        // check if character is a letter
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
        {

            int n;

            // set bounds for CAPITAL LETTERS
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                n = 65;
            }

            // set bounds for lower case letters
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                n = 97;
            }

            char p = s[i];

            int m = (int) p;

            //apply algorithm, shifting for ASCII
            char c = (((m - n) + k) % 26) + n ;

            s[i] = c;

        }

    }

   return s;
}