#include "functions.h"
#include <cstdlib>
#include <ctime>
#include <windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int SIZE = 10;
    int arr[SIZE];
    int choice;

    srand(time(0));

    while (true)
    {
        cout << "\nМЕНЮ\n";
        cout << "1 - Ввести числа вручну\n";
        cout << "2 - Заповнити випадковими числами\n";
        cout << "3 - Вихід з програми\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        if (choice == 3)
        {
            cout << "\nПрограма завершує роботу.\n";
            break;
        }

        if (choice == 1)
        {
            cout << "\nВведіть " << SIZE << " чисел:\n";
            for (int i = 0; i < SIZE; i++)
            {
                cin >> arr[i];
            }
        }
        else if (choice == 2)
        {
            cout << "\nЗгенерований масив:\n";
            for (int i = 0; i < SIZE; i++)
            {
                arr[i] = rand() % 21 - 10;
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "\nНевірний вибір. Спробуйте ще раз.\n";
            continue;
        }

        int (*funcPtr)(int[], int);

        funcPtr = sumPositive;
        cout << "\nСума додатних елементів: "
            << funcPtr(arr, SIZE) << endl;

        funcPtr = productNegative;
        cout << "Добуток від’ємних елементів: "
            << funcPtr(arr, SIZE) << endl;
    }

    return 0;
}