#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include "OfficePackage.h"
using namespace std;

void printTableHeader() {
    cout << "-------------------------------------------------------------------------\n";
    cout << "| " << left << setw(20) << "Найменування"
        << " | " << setw(15) << "Виробник"
        << " | " << setw(15) << "Складові"
        << " | " << setw(10) << "Ціна ($)" << " |\n";
    cout << "-------------------------------------------------------------------------\n";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int size = 0;
    OfficePackage* arr = nullptr;

    int choice = -1;
    while (choice != 0) {
        cout << "\nМЕНЮ:\n";
        cout << "1. Завантажити дані з файлу (Перевантаження >>)\n";
        cout << "2. Вивести дані на екран (Перевантаження <<)\n";
        cout << "3. Тест привласнення '=' та ініціалізації '()'\n";
        cout << "4. Тест порівняння '==' (Функція-член та Дружня)\n";
        cout << "5. Тест складання '+' (Функція-член та Дружня)\n";
        cout << "6. Тест довжини рядків '[]'\n";
        cout << "0. Вихід\n";
        cout << "Оберіть дію: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            ifstream fin("data.txt");
            if (!fin.is_open()) {
                cout << "Помилка відкриття файлу.\n";
                break;
            }
            fin >> size;

            if (arr != nullptr) delete[] arr;
            arr = new OfficePackage[size];

            for (int i = 0; i < size; i++) {
                fin >> *(arr + i);
            }
            fin.close();
            cout << "Дані успішно завантажено.\n";
            break;
        }
        case 2: {
            if (arr == nullptr || size == 0) {
                cout << "Масив порожній. Спочатку завантажте дані.\n";
                break;
            }
            printTableHeader();
            for (int i = 0; i < size; i++) {
                cout << *(arr + i) << endl;
            }
            cout << "-------------------------------------------------------------------------\n";
            break;
        }
        case 3: {
            if (arr == nullptr || size == 0) {
                cout << "Масив порожній.\n";
                break;
            }

            int index;
            cout << "Введіть номер пакету для створення копії (від 1 до " << size << "): ";
            cin >> index;
            if (index < 1 || index > size) { cout << "Невірний номер.\n"; break; }

            OfficePackage temp;
            temp = *(arr + (index - 1));

            cout << "\n Створено точну копію обраного пакету \n";
            printTableHeader();
            cout << temp << endl;

            cout << "\nТепер введіть нові дані, щоб ініціалізувати цю копію оператором '()':\n";
            char nName[50], nMan[50];
            int nComp;
            double nPrice;
            cout << "Введіть Найменування, Виробника, К-ть складових, Ціну через пробіл:\n";
            cin >> nName >> nMan >> nComp >> nPrice;

            temp(nName, nMan, nComp, nPrice);

            cout << "\n Об'єкт після ініціалізації \n";
            printTableHeader();
            cout << temp << endl;
            break;
        }
        case 4: {
            if (arr == nullptr || size < 2) {
                cout << "Масив порожній або має менше 2 елементів.\n";
                break;
            }

            int subChoice;
            cout << "\nЩо ви хочете зробити?\n";
            cout << "1. Порівняти ціни двох пакетів (Метод класу)\n";
            cout << "2. Перевірити, чи має пакет певну назву (Дружня функція)\n";
            cout << "Вибір: ";
            cin >> subChoice;

            if (subChoice == 1) {
                int id1, id2;
                cout << "Введіть номери двох пакетів для порівняння цін (наприклад: 1 2): ";
                cin >> id1 >> id2;
                if (id1 < 1 || id1 > size || id2 < 1 || id2 > size) { cout << "Помилка вводу.\n"; break; }

                if (*(arr + (id1 - 1)) == *(arr + (id2 - 1))) {
                    cout << "Результат: Ціни пакетів ОДНАКОВІ.\n";
                }
                else {
                    cout << "Результат: Ціни пакетів РІЗНІ.\n";
                }
            }
            else if (subChoice == 2) {
                int id;
                char search[50];
                cout << "Введіть номер пакету: ";
                cin >> id;
                cout << "Введіть назву, яку хочете пошукати: ";
                cin >> search;
                if (id < 1 || id > size) { cout << "Помилка вводу.\n"; break; }

                if (search == *(arr + (id - 1))) {
                    cout << "Результат: ТАК, назви співпадають.\n";
                }
                else {
                    cout << "Результат: НІ, це інший пакет.\n";
                }
            }
            break;
        }
        case 5: {
            if (arr == nullptr || size == 0) {
                cout << "Масив порожній.\n";
                break;
            }

            int subChoice;
            cout << "\nЩо ви хочете зробити?\n";
            cout << "1. Додати націнку до ціни пакету (Метод класу)\n";
            cout << "2. Збільшити кількість складових пакету (Дружня функція)\n";
            cout << "Вибір: ";
            cin >> subChoice;

            int id;
            cout << "Введіть номер пакету (від 1 до " << size << "): ";
            cin >> id;
            if (id < 1 || id > size) { cout << "Помилка вводу.\n"; break; }

            if (subChoice == 1) {
                double extraPrice;
                cout << "Введіть суму націнки ($): ";
                cin >> extraPrice;

                OfficePackage expensive = *(arr + (id - 1)) + extraPrice;

                cout << "\n Пакет після подорожчання \n";
                printTableHeader();
                cout << expensive << endl;
            }
            else if (subChoice == 2) {
                int extraComp;
                cout << "Введіть кількість додаткових складових (шт.): ";
                cin >> extraComp;

                OfficePackage expanded = extraComp + *(arr + (id - 1));

                cout << "\n Пакет з новими складовими \n";
                printTableHeader();
                cout << expanded << endl;
            }
            break;
        }
        case 6: {
            if (arr == nullptr || size == 0) {
                cout << "Масив порожній.\n";
                break;
            }

            int id, fieldId;
            cout << "Введіть номер пакету (від 1 до " << size << "): ";
            cin >> id;
            if (id < 1 || id > size) { cout << "Помилка вводу.\n"; break; }

            cout << "Що рахувати? (0 - Довжина назви, 1 - Довжина виробника): ";
            cin >> fieldId;

            int length = (*(arr + (id - 1)))[fieldId];

            if (length == -1) {
                cout << "Помилка: Невірний індекс параметра.\n";
            }
            else {
                cout << "Довжина рядка становить: " << length << " символів.\n";
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

    if (arr != nullptr) {
        delete[] arr;
    }

    return 0;
}