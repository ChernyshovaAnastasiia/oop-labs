#include <iostream>
#include <windows.h>
using namespace std;

void fillArray(int** arr, int rows, int cols) {
    cout << "Введіть елементи масиву:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> *(*(arr + i) + j);
        }
    }
}

void printArray(int** arr, int rows, int cols) {
    cout << "\nВведений масив:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << *(*(arr + i) + j) << " ";
        }
        cout << endl;
    }
}

void processArray(int** arr, int rows, int cols) {
    int* maxPtr = *arr;
    int* firstEvenPtr = nullptr;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int* current = *(arr + i) + j;

            if (*current > *maxPtr) {
                maxPtr = current;
            }

            if (*current % 2 == 0 && firstEvenPtr == nullptr) {
                firstEvenPtr = current;
            }
        }
    }

    cout << "\nНайбільший елемент: " << *maxPtr << endl;

    if (firstEvenPtr != nullptr) {
        cout << "Перший парний елемент: " << *firstEvenPtr << endl;
    }
    else {
        cout << "Парних елементів немає\n";
    }

    if (firstEvenPtr != nullptr) {
        int temp = *maxPtr;
        *maxPtr = *firstEvenPtr;
        *firstEvenPtr = temp;
    }

    int countNeg = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (*(*(arr + i) + j) < 0) {
                countNeg++;
            }
        }
    }

    int* negArray = new int[countNeg];
    int k = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int value = *(*(arr + i) + j);
            if (value < 0) {
                *(negArray + k) = value;
                k++;
            }
        }
    }

    if (countNeg == 0) {
        cout << "\nНегативних елементів немає\n";
    }
    else {
        cout << "\nНегативні елементи:\n";
        for (int i = 0; i < countNeg; i++) {
            cout << *(negArray + i) << " ";
        }
        cout << endl;
    }

    delete[] negArray;
}

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