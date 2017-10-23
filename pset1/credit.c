#include <cs50.h>
#include <stdio.h>

int count(long long num);
int start(long long num, int length, int places);
bool valid(long long num);

int main(void)
{
    long long i = get_long_long("Number: ");

    if (i == LLONG_MAX)
    {
        main();
    }

    int length = count(i);

    if (length != 13 && length != 15 && length != 16)
    {
        printf("INVALID\n");
        return false;
    }

    // Return first X digits

    int startone = start(i, length, 1);
    int starttwo = start(i, length, 2);

    // Test Visa

    if ((length == 13 || length == 16) && startone == 4)
    {
        if (valid(i))
        {
            printf("VISA\n");
        }
    }

    // Test Amex

    else if (length == 15 && (starttwo == 34 || starttwo == 37))
    {
        if (valid(i))
        {
            printf("AMEX\n");
        }
    }

    // Test Mastercard
    else if (length == 16 && (starttwo == 51 || starttwo == 52 || starttwo == 53 || starttwo == 54 || starttwo == 55))
    {
        if (valid(i))
        {
            printf("MASTERCARD\n");
        }
    }

    // Test falls through
    else
    {
        printf("INVALID\n");
    }

}

// Count the length of the string.
int count(long long num)
{
    int i = 0;

    while (num > 0)
    {
        num /= 10;
        i ++;
    }
    //printf("Length: %i\n", i);

    return i;
}

// Get X starting numbers
int start(long long num, int length, int places)
{
    for (int i = 0; i < length - places; i++)
    {
        num /= 10;
    }

    //printf("Start: %lld\n", num);

    return num;
}

// Apply Luhn's Algorithm to test validity
bool valid(long long num)
{
    int i = 1;
    int sum = 0;

    while (num > 0)
    {
        // Even digits add 2* to sum
        if (i % 2 == 0)
        {
            int adder = (2 * (num % 10));

            // Single digit, add digit
            if (adder < 10)
            {
                sum += adder;
            }

            // Two Digit, add individual digits
            else
            {
                sum += adder % 10;
                sum += adder / 10;
            }
        }

        // Odd Digits add 1* to sum
        else
        {
            sum += (num % 10);
        }

        num /= 10;
        i ++;

    }

    // printf("Sum: %i\n", sum);

    if (sum % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}