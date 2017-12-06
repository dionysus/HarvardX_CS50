#include <cs50.h>
#include <stdio.h>
#include <string.h>

char encryptletter (string s, string k, int i, int j);
string encrypt(string s, string k);
char lowercase (char c);
bool alpha(string s);

int main (int argc, string argv[])
{

    // error if command line has no entries, or more than one entry, or not alphabets
    if (argc != 2 || !(alpha(argv[1])))
    {
        printf("Usage: ./vigenere k \n");
        return 1;
    }

    // works when command line has 2 entries (./caesar k)
    if (argc == 2)
    {
        printf("plaintext: ");
        string s = get_string();
        string k = argv[1];

        printf("ciphertext: %s\n", encrypt(s, k));


        return 0;
    }



}

// encrypt letter using key
char encryptletter (string s, string k, int i, int j)
{
    int n;

    char c = s[i];
    int m = (int)c;

    if (c >= 'A' && c <= 'Z')
    {
        n = 65;
    }

    if (c >= 'a' && c <= 'z')
    {
        n = 97;
    }

    int p = (int)lowercase(k[j % strlen(k)]) - 97;

    return ((m - n) + p) % 26 + n;

}

// cycle through letters of string, calling encrypt letter
string encrypt(string s, string k)
{
    int j = 0;

    for (int i = 0; i <= strlen(s) -1; i++)

    if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
    {
        s[i] = encryptletter (s, k, i, j);
        j++;
    }

    return s;
}

// convert to lowercase
char lowercase (char c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return c + 32;
    }

    // if letter is already upper case, return lower case
    else
    {
        return c;
    }
}

bool alpha(string s)
{
    bool a = true;

    for (int i = 0; i <= strlen(s) -1; i++)

        if (!((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')))
        {
            a = false;
        }

    return a;
}