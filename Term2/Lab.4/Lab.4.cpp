#include <iostream>
#include <windows.h>
#include "functions.h"

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int rows, cols;

    cout << "Введіть кількість рядків і стовпців: ";
    cin >> rows >> cols;

    int** arr = new int* [rows];
    for (int i = 0; i < rows; i++) {
        *(arr + i) = new int[cols];
    }

    fillArray(arr, rows, cols);

    printArray(arr, rows, cols);

    processArray(arr, rows, cols);

    cout << "\nМасив після обміну:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << *(*(arr + i) + j) << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < rows; i++) {
        delete[] * (arr + i);
    }
    delete[] arr;

    return 0;
}