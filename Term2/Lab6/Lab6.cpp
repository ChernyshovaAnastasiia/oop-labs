#include <iostream>
#include "functions.h"
#include <windows.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int SIZE = 10;

    while (true)
    {
        cout << "--------------------------\n";
        cout << "ПОШУК ОСТАННЬОГО ВХОДЖЕННЯ\n";
        cout << "--------------------------\n\n";

        cout << "Введіть рядок:\n";

        char* text = inputString(SIZE);

        if (text == nullptr)
        {
            continue;
        }

        cout << "\nВведіть підрядок:\n";

        char* sub = inputString(SIZE);

        if (sub == nullptr)
        {
            delete[] text;
            continue;
        }

        int result = findLastSubstring(text, sub);

        if (result == -1)
        {
            cout << "\nПідрядок не знайдено.\n";
        }
        else
        {
            cout << "\nОстаннє входження підрядка: "
                << result << endl;
        }

        delete[] text;
        delete[] sub;
    }

    return 0;
}