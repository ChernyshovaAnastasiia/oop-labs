#include <iostream>
#include <fstream>
#include <windows.h>
#include "B1.h"
#include "B2.h"
#include "D1.h"
#include "D2.h"
#include "D3.h"
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int size = 0;
    D3** arr = nullptr;

    int choice = -1;

    while (choice != 0) {
        cout << "\nМЕНЮ:\n";
        cout << "1. Показати об'єкти всіх класів\n";
        cout << "2. Перевірити віртуальні функції show()\n";
        cout << "3. Завантажити масив об'єктів із файлу\n";
        cout << "4. Вивести завантажений масив\n";
        cout << "0. Вихід\n";
        cout << "Оберіть дію: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            B1 objB1(10);
            B2 objB2(20);
            D1 objD1(10, 30);
            D2 objD2(10, 30, 20, 40);
            D3 objD3(10, 30, 20, 40, 50);

            cout << "\n1. Базовий клас B1: "
                << objB1 << endl;

            cout << "2. Базовий клас B2: "
                << objB2 << endl;

            cout << "3. Похідний клас D1 (public від B1): "
                << objD1 << endl;

            cout << "4. Похідний клас D2 (private від D1 та B2): "
                << objD2 << endl;

            cout << "5. Похідний клас D3 (public від D2): "
                << objD3 << endl;

            break;
        }

        case 2: {
            D1 objD1(10, 30);
            D3 objD3(10, 30, 20, 40, 50);

            B1* ptrB1 = &objD1;
            D2* ptrD2 = &objD3;

            cout << "\nВиклик через покажчик B1*:\n";
            ptrB1->show();

            cout << "\nВиклик через покажчик D2*:\n";
            ptrD2->show();

            break;
        }

        case 3: {
            ifstream fin("data.txt");

            if (!fin.is_open()) {
                cout << "Помилка відкриття файлу data.txt.\n";
                break;
            }

            int newSize = 0;
            fin >> newSize;

            if (!fin || newSize <= 0) {
                cout << "Некоректна кількість об'єктів у файлі.\n";
                break;
            }

            D3** newArr = new D3 * [newSize] {};

            bool isCorrect = true;

            for (int i = 0; i < newSize; i++) {
                int b1, d1, b2, d2, d3;

                if (!(fin >> b1 >> d1 >> b2 >> d2 >> d3)) {
                    isCorrect = false;
                    break;
                }

                *(newArr + i) = new D3(b1, d1, b2, d2, d3);
            }

            fin.close();

            if (!isCorrect) {
                for (int i = 0; i < newSize; i++) {
                    delete* (newArr + i);
                }

                delete[] newArr;
                cout << "Помилка читання даних із файлу.\n";
                break;
            }

            for (int i = 0; i < size; i++) {
                delete* (arr + i);
            }
            delete[] arr;

            arr = newArr;
            size = newSize;

            cout << "Успішно завантажено " << size
                << " об'єктів класу D3.\n";

            break;
        }

        case 4: {
            if (arr == nullptr || size == 0) {
                cout << "Масив порожній. Спочатку завантажте дані.\n";
                break;
            }

            cout << "\nЗавантажені об'єкти класу D3:\n";

            for (int i = 0; i < size; i++) {
                cout << i + 1 << ". "
                    << *(*(arr + i)) << endl;
            }

            break;
        }

        case 0:
            cout << "Завершення роботи...\n";
            break;

        default:
            cout << "Невірний вибір.\n";
        }
    }

    for (int i = 0; i < size; i++) {
        delete* (arr + i);
    }

    delete[] arr;

    return 0;
}