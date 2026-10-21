#include "SOBAKA.h"
#include "SPANIEL.h"
#include "DOG.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    cout << "Базовий клас SOBAKA" << endl;

    {
        SOBAKA sobaka;

        sobaka.setData(8.0, 3);
        sobaka.show();

        cout << "Голос: ";
        sobaka.golos();
    }

    cout << "\nПохідний клас SPANIEL" << endl;

    {
        SPANIEL spaniel;

        spaniel.setData(12.0, 5);
        spaniel.setColor("Рудий");

        spaniel.show();

        cout << "Голос: ";
        spaniel.golos();
    }

    cout << "\nПохідний клас DOG" << endl;

    {
        DOG dog;

        dog.setData(10.0, 4);
        dog.setHeight(45.0);

        dog.show();

        cout << "Голос: ";
        dog.golos();
    }

    cout << "\nТестові дані з файлу dogs.txt" << endl;

    ifstream inputFile("dogs.txt");

    if (!inputFile.is_open()) {
        cout << "Помилка: не вдалося відкрити dogs.txt" << endl;
        return 1;
    }

    int count = 0;
    const int MAX_TESTS = 100;

    if (!(inputFile >> count) ||
        count <= 0 || count > MAX_TESTS) {
        cout << "Помилка: неправильна кількість тестів (1..100)" << endl;
        return 1;
    }

    string unusedLine;
    getline(inputFile, unusedLine);

    string* testData = new string[count];

    for (int i = 0; i < count; ++i) {
        if (!getline(inputFile, *(testData + i))) {
            cout << "Помилка: недостатньо рядків у файлі" << endl;

            delete[] testData;
            return 1;
        }
    }

    inputFile.close();

    for (int i = 0; i < count; ++i) {
        istringstream row(*(testData + i));

        char type = '\0';
        double weight = 0.0;
        int age = 0;

        if (!(row >> type >> weight >> age) ||
            weight <= 0.0 || age < 0) {
            cout << "Помилка: неправильні дані у тесті "
                << i + 1 << endl;

            delete[] testData;
            return 1;
        }

        cout << "\nТест № " << i + 1 << endl;

        if (type == 'S') {
            SOBAKA sobaka;

            sobaka.setData(weight, age);
            sobaka.show();

            cout << "Голос: ";
            sobaka.golos();
        }
        else if (type == 'P') {
            string color;

            if (!(row >> color)) {
                cout << "Помилка: не вказано колір" << endl;

                delete[] testData;
                return 1;
            }

            SPANIEL spaniel;

            spaniel.setData(weight, age);
            spaniel.setColor(color);

            spaniel.show();

            cout << "Голос: ";
            spaniel.golos();
        }
        else if (type == 'D') {
            double height = 0.0;

            if (!(row >> height) || height <= 0.0) {
                cout << "Помилка: неправильний зріст" << endl;

                delete[] testData;
                return 1;
            }

            DOG dog;

            dog.setData(weight, age);
            dog.setHeight(height);

            dog.show();

            cout << "Голос: ";
            dog.golos();
        }
        else {
            cout << "Помилка: невідомий тип класу" << endl;

            delete[] testData;
            return 1;
        }
    }

    delete[] testData;

    return 0;
}