#include <iostream>
#include "functions.h"
using namespace std;

void clearBuffer()
{
    cin.clear();

    while (cin.get() != '\n')
    {
    }
}

int myStrLen(char* str)
{
    int len = 0;

    while (*(str + len) != '\0')
    {
        len++;
    }

    return len;
}

char* inputString(int size)
{
    char* str = new char[size];

    cin.getline(str, size);

    if (cin.fail())
    {
        cout << "Рядок занадто довгий.\n";

        clearBuffer();

        delete[] str;

        return nullptr;
    }

    return str;
}

int findLastSubstring(char* text, char* sub)
{
    int textLen = myStrLen(text);
    int subLen = myStrLen(sub);

    if (subLen == 0)
    {
        return -1;
    }

    int lastIndex = -1;

    for (int i = 0; i <= textLen - subLen; i++)
    {
        bool equal = true;

        for (int j = 0; j < subLen; j++)
        {
            if (*(text + i + j) != *(sub + j))
            {
                equal = false;
                break;
            }
        }

        if (equal)
        {
            lastIndex = i;
        }
    }

    return lastIndex;
}