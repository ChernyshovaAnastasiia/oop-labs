#include "functions.h"

void findMinPointer(int* arr, int n, int* min1, int* min2, int* min3)
{
    *min1 = INT_MAX;
    *min2 = INT_MAX;
    *min3 = INT_MAX;

    for (int* p = arr; p < arr + n; p++)
    {
        if (*p < *min1)
        {
            *min3 = *min2;
            *min2 = *min1;
            *min1 = *p;
        }
        else if (*p < *min2)
        {
            *min3 = *min2;
            *min2 = *p;
        }
        else if (*p < *min3)
        {
            *min3 = *p;
        }
    }
}

void findMinReference(int* arr, int n, int& min1, int& min2, int& min3)
{
    min1 = INT_MAX;
    min2 = INT_MAX;
    min3 = INT_MAX;

    for (int* p = arr; p < arr + n; p++)
    {
        if (*p < min1)
        {
            min3 = min2;
            min2 = min1;
            min1 = *p;
        }
        else if (*p < min2)
        {
            min3 = min2;
            min2 = *p;
        }
        else if (*p < min3)
        {
            min3 = *p;
        }
    }
}