#include "Figure.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Figure kr(10);
    Figure tr(10, 20);

    cout << fixed << setprecision(2);
    cout << "Круг (радіус 10): площа = "
        << kr.calculateArea() << '\n';
    cout << "Трикутник (висота 10, основа 20): площа = "
        << tr.calculateArea() << "\n\n";

    ifstream inputFile("figures.txt");

    if (!inputFile.is_open()) {
        cout << "Помилка: не вдалося відкрити файл figures.txt\n";
        return 1;
    }

    int count = 0;

    if (!(inputFile >> count) ||
        count <= 0 || count > 1000) {
        cout << "Помилка: неправильна кількість фігур (1..1000).\n";
        return 1;
    }

    Figure* figures = new Figure[count];

    for (int i = 0; i < count; ++i) {
        char type;
        double firstValue = 0.0;
        double secondValue = 0.0;

        if (!(inputFile >> type >> firstValue)) {
            cout << "Помилка: неправильний запис № "
                << i + 1 << '\n';

            delete[] figures;
            return 1;
        }

        if (type == 'T') {
            if (!(inputFile >> secondValue) ||
                firstValue <= 0.0 ||
                secondValue <= 0.0) {
                cout << "Помилка: неправильні параметри трикутника № "
                    << i + 1 << '\n';

                delete[] figures;
                return 1;
            }
            *(figures + i) = Figure(firstValue, secondValue);
        }
        else if (type == 'C') {
            if (firstValue <= 0.0) {
                cout << "Помилка: неправильний радіус круга № "
                    << i + 1 << '\n';

                delete[] figures;
                return 1;
            }
            *(figures + i) = Figure(firstValue);
        }
        else {
            cout << "Помилка: невідомий тип фігури № "
                << i + 1 << '\n';

            delete[] figures;
            return 1;
        }
    }

    cout << "Фігури, зчитані з файлу:\n";

    for (int i = 0; i < count; ++i) {
        const Figure& figure = *(figures + i);

        cout << i + 1 << ". ";

        if (figure.isTriangle()) {
            cout << "Трикутник: висота = "
                << figure.getFirstValue()
                << ", основа = "
                << figure.getSecondValue();
        }
        else {
            cout << "Круг: радіус = "
                << figure.getFirstValue();
        }

        cout << ", площа = "
            << figure.calculateArea() << '\n';
    }

    delete[] figures;

    inputFile.close();

    return 0;
}
