#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "functions.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(time(0));

    int n;
    cout << "Введіть розмір масиву: ";
    cin >> n;

    int* arr = new int[n];

    int mode;
    cout << "\nОберіть спосіб заповнення масиву:\n";
    cout << "1 - вручну\n";
    cout << "2 - випадкові числа\n";
    cin >> mode;

    if (mode == 1)
    {
        cout << "Введіть елементи масиву:\n";
        for (int* p = arr; p < arr + n; p++)
        {
            cin >> *p;
        }
    }
    else if (mode == 2)
    {
        for (int* p = arr; p < arr + n; p++)
        {
            *p = rand() % 100;
        }

        cout << "Згенерований масив:\n";
        for (int* p = arr; p < arr + n; p++)
        {
            cout << *p << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Невірний вибір.\n";
        delete[] arr;
        return 0;
    }

    int choice;
    cout << "\nОберіть метод:\n";
    cout << "1 - через покажчики\n";
    cout << "2 - через посилання\n";
    cin >> choice;

    int min1, min2, min3;

    switch (choice)
    {
    case 1:
        findMinPointer(arr, n, &min1, &min2, &min3);
        break;

    case 2:
        findMinReference(arr, n, min1, min2, min3);
        break;

    default:
        cout << "Невірний вибір.\n";
        delete[] arr;
        return 0;
    }

    cout << "\nТри мінімальні числа:\n";
    cout << min1 << " " << min2 << " " << min3 << endl;

    delete[] arr;
    return 0;
}