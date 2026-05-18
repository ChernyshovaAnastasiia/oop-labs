#include "functions.h"

int sumPositive(int arr[], int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > 0)
        {
            sum += arr[i];
        }
    }

    return sum;
}

int productNegative(int arr[], int size)
{
    int product = 1;
    bool hasNegative = false;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            product *= arr[i];
            hasNegative = true;
        }
    }

    if (!hasNegative)
    {
        return 0;
    }

    return product;
}