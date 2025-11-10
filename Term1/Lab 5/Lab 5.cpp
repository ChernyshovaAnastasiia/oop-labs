// Lab 5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int mas[] = { 10, -3, 1, 4, -5, 2 };
    int N = sizeof(mas) / sizeof(int);
    
	// заданий 
    cout << "Заданий масив > \n";
    for (int i = 0; i < N; i++)
        cout << mas[i] << " ";
    cout << endl;

    int maxNegAbs = 0;
    bool foundNeg = false;

    for (int i = 0; i < N; i++) {
        if (mas[i] < 0) {
            int absVal = abs(mas[i]);
            if (!foundNeg || absVal > maxNegAbs) {
                maxNegAbs = absVal;
                foundNeg = true;
            }
        }
    }

    if (!foundNeg) {
        cout << "У заданому масиві немає від’ємних елементів.\n";
        return 0;
    }

    for (int i = 0; i < N; i++) {
        if (mas[i] > 0)
            mas[i] = maxNegAbs;
    }

    cout << "Результат заданого масиву > \n";
    for (int i = 0; i < N; i++)
        cout << mas[i] << " ";
    cout << endl << endl;


    // рандомний
    char cont = 'y';
    while (cont == 'y' || cont == 'Y') {

    int n;
    cout << "Введіть розмір масиву до 20 елементів > ";
    cin >> n;

    if (n <= 0 || n > 20) {
        cout << "Некоректний розмір масиву.\n";
        return 0;
    }

    int arr[20];
    srand(time(NULL));

  
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 41 - 20;

    cout << "Рандомний масив > \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

 
    maxNegAbs = 0;
    foundNeg = false;

    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            int absVal = abs(arr[i]);
            if (!foundNeg || absVal > maxNegAbs) {
                maxNegAbs = absVal;
                foundNeg = true;
            }
        }
    }

    if (!foundNeg) {
        cout << "У масиві немає від’ємних елементів." << endl;
        return 0;
    }


    for (int i = 0; i < n; i++) {
        if (arr[i] > 0)
            arr[i] = maxNegAbs;
    }

    cout << "Результат рандомного масиву > \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    cout << "\n Бажаєте згенерувати новий рандомний масив? (y - так; n - ні.): ";
    cin >> cont;
    }
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
