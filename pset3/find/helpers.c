/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{

    // TODO: implement a searching algorithm

    // error if list length is not positive
    if (n <= 0)
    {
        return false;
    }

    int m = n / 2;

    // if middle test is value
    if (value == values[m])
    {
        return true;
    }

    // value search in Left
    if (n > 1 && value < values[m])
    {
        int leftcount = m;

        // create new array of Left
        int leftvalues[leftcount];

        for (int i = 0; i < leftcount; i++)
        {
            leftvalues[i] = values[i];
        }
        // repeat Search on Left
        if (search(value, leftvalues, leftcount))
        {
            return true;
        }
    }

    // value search in Right
    else if (n > 1 && value > values[m])
    {
        int rightcount = m - 1 + n % 2;

        // create new array of Right
        int rightvalues[rightcount];


        for (int i = 0; i < rightcount; i++)
        {
            rightvalues[i] = values[m + 1 + i];
        }

        // repeat SEARCH on Right
        if (search(value, rightvalues, rightcount))
        {
            return true;
        }
    }

    return false;
}

/**
 * Sorts array of n values.
*/

void sort(int values[], int n)
{
    // bubble sort

    // for swaps not zero
    int swaps;
    int newValues[2];

    for (int x = 0; x < n; x++)
    {
        swaps = 0;

        // for (length - 1)clea
        for (int i = 0; i < n - 1; i++)
        {

            //new list of current (test) and next
            newValues[0] = values[i];
            newValues[1] = values [i + 1];

            // Swap if current (test) is larger than next
            if (newValues[0] > values[i + 1])
            {
                values[i] = newValues[1];
                values[i + 1] = newValues[0];

                swaps ++;
            }
        }

        // return list if no swaps (in order)
        if (swaps == 0)
        {
            break;
        }
    }

    return;
}
