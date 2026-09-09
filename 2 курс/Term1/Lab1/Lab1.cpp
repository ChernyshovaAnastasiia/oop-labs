#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <windows.h>
#include "OfficePackage.h"
using namespace std;

void printTableHeader() {
    cout << "--------------------------------------------------------------\n";
    cout << "Найменування\tВиробник\tСкладові\tЦіна ($)\n";
    cout << "--------------------------------------------------------------\n";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ifstream fin("data.txt");
    int size1 = 0;
    if (fin.is_open()) {
        fin >> size1;
    }

    OfficePackage* arr1 = new OfficePackage[size1];
    char tempName[50], tempMan[50];
    int tempCount;
    double tempPrice;

    for (int i = 0; i < size1; i++) {
        fin >> tempName >> tempMan >> tempCount >> tempPrice;
        (*(arr1 + i)).setName(tempName);
        (*(arr1 + i)).setManufacturer(tempMan);
        (*(arr1 + i)).setComponentCount(tempCount);
        (*(arr1 + i)).setPrice(tempPrice);
    }
    fin.close();

    int size2 = 0;
    OfficePackage** arr2 = nullptr;

    OfficePackage** arr3 = new OfficePackage * [size1];
    for (int i = 0; i < size1; i++) {
        *(arr3 + i) = new OfficePackage(*(arr1 + i));
    }

    int choice = -1;
    while (choice != 0) {
        cout << "\nМЕНЮ:\n";
        cout << "1. Вивести Масив 1 (з файлу, Конструктор за умовчанням)\n";
        cout << "2. Ввести з екрану та вивести Масив 2 (Конструктор з параметрами)\n";
        cout << "3. Змінити параметри в Масиві 1 (тестування set та get)\n";
        cout << "4. Порівняти Масив 1 (змінений) та Масив 3 (первинна копія)\n";
        cout << "0. Вихід\n";
        cout << "Оберіть дію: ";
        cin >> choice;

        switch (choice) {
        case 1:
            printTableHeader();
            for (int i = 0; i < size1; i++) { (*(arr1 + i)).show(); }
            break;

        case 2:
            if (arr2 != nullptr) {
                cout << "Масив 2 створено.\n";
                break;
            }
            cout << "Введіть кількість пакетів для вводу: ";
            cin >> size2;
            arr2 = new OfficePackage * [size2];
            for (int i = 0; i < size2; i++) {
                cout << "Введіть Найменування, Виробника, К-ть складових, Ціну через пробіл:\n";
                cin >> tempName >> tempMan >> tempCount >> tempPrice;
                *(arr2 + i) = new OfficePackage(tempName, tempMan, tempCount, tempPrice);
            }
            printTableHeader();
            for (int i = 0; i < size2; i++) { (*(arr2 + i))->show(); }
            break;

        case 3: {
            if (size1 == 0) {
                cout << "Масив 1 порожній. Спочатку завантажте дані (Пункт 1).\n";
                break;
            }

            int index;
            cout << "\nВведіть номер пакету для зміни (від 1 до " << size1 << "): ";
            cin >> index;

            if (index < 1 || index > size1) {
                cout << "Пакету з таким номером не існує.\n";
                break;
            }

            int i = index - 1;

            cout << "\nПОТОЧНІ ДАНІ ОБРАНОГО ПАКЕТУ\n";
            cout << "1. Найменування: " << (*(arr1 + i)).getName() << "\n";
            cout << "2. Виробник: " << (*(arr1 + i)).getManufacturer() << "\n";
            cout << "3. К-ть складових: " << (*(arr1 + i)).getComponentCount() << "\n";
            cout << "4. Ціна: " << (*(arr1 + i)).getPrice() << " $\n";

            int subChoice;
            cout << "\nЩо саме ви хочете змінити? (1-4): ";
            cin >> subChoice;

            switch (subChoice) {
            case 1: {
                char newName[50];
                cout << "Введіть нове найменування: ";
                cin >> newName;
                (*(arr1 + i)).setName(newName);
                cout << "Найменування змінено.\n";
                break;
            }
            case 2: {
                char newMan[50];
                cout << "Введіть нового виробника: ";
                cin >> newMan;
                (*(arr1 + i)).setManufacturer(newMan);
                cout << "Виробника змінено.\n";
                break;
            }
            case 3: {
                int newCount;
                cout << "Введіть нову кількість складових: ";
                cin >> newCount;
                (*(arr1 + i)).setComponentCount(newCount);
                cout << "Кількість складових змінено\n";
                break;
            }
            case 4: {
                double newPrice;
                cout << "Введіть нову ціну: ";
                cin >> newPrice;
                (*(arr1 + i)).setPrice(newPrice);
                cout << "Ціну змінено.\n";
                break;
            }
            default:
                cout << "Невірний вибір.\n";
            }
            break;
        }
        case 4:
            cout << "\nПЕРВИННА ТАБЛИЦЯ (Масив 3 - копія)\n";
            printTableHeader();
            for (int i = 0; i < size1; i++) { (*(arr3 + i))->show(); }

            cout << "\nЗМІНЕНА ТАБЛИЦЯ (Масив 1)\n";
            printTableHeader();
            for (int i = 0; i < size1; i++) { (*(arr1 + i)).show(); }
            break;

        case 0:
            cout << "Вихід.\n";
            break;

        default:
            cout << "Невірний вибір.\n";
        }
    }

    delete[] arr1;
    if (arr2 != nullptr) {
        for (int i = 0; i < size2; i++) { delete* (arr2 + i); }
        delete[] arr2;
    }
    for (int i = 0; i < size1; i++) { delete* (arr3 + i); }
    delete[] arr3;

    return 0;
}