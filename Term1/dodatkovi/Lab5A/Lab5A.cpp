// Lab5A.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int MAX = 100;
    int arr[MAX];
    int n;

    cout << "Введiть кiлькiсть елементiв масиву > ";
    cin >> n;

    if (n < 0 || n > MAX) {
        cout << "Некоректний розмiр масиву.\n";
        return 1;
    }

    cout << "Введiть елементи масиву > ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }



    int posInsert, kInsert;
    cout << "\nВведiть позицiю вставлення > ";
    cin >> posInsert;
    cout << "Скiльки елементiв вставити > ";
    cin >> kInsert;

    if (posInsert < 0 || posInsert > n) {
        cout << "Вставлення в некоректну позицiю.\n";
    }
    else if (kInsert < 0 || n + kInsert > MAX) {
        cout << "Неможливо вставити таку кiлькiсть елементiв.\n";
    }
    else {
        for (int i = n - 1; i >= posInsert; i--) {
            arr[i + kInsert] = arr[i];
        }

        cout << "Введiть " << kInsert << " нових елементiв > ";
        for (int i = 0; i < kInsert; i++) {
            cin >> arr[posInsert + i];
        }

        n += kInsert;
    }

    cout << "\nМасив пiсля вставлення: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";



    int posDel, kDel;
    cout << "\n\nВведiть позицiю видалення > ";
    cin >> posDel;
    cout << "Скiльки елементiв видалити > ";
    cin >> kDel;

    if (posDel < 0 || posDel >= n) {
        cout << "Некоректна позицiя видалення.\n";
    }
    else if (kDel < 0 || posDel + kDel > n) {
        cout << "Неможливо видалити таку кiлькiсть елементiв.\n";
    }
    else {
        for (int i = posDel + kDel; i < n; i++) {
            arr[i - kDel] = arr[i];
        }
        n -= kDel;
    }

    cout << "\n Масив пiсля видалення: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
