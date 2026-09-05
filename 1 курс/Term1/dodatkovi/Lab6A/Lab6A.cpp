#include <iostream>
#include <windows.h> 
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int rows = 3;
    const int cols = 4;

    int arr[rows][cols] = {
        {5, 2, 9, 1},
        {7, 3, 4, 8},
        {6, 0, 3, 2}
    };

    cout << "Початковий масив:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << arr[i][j] << "\t";
        cout << endl;
    }

    // max
    for (int i = 0; i < rows; i++) {
        int maxIndex = 0;
        for (int j = 1; j < cols; j++) {
            if (arr[i][j] > arr[i][maxIndex])
                maxIndex = j;
        }
        cout << "\nМаксимальний елемент рядка " << i + 1 << ": " << arr[i][maxIndex] << endl;

  
        int temp = arr[i][0];
        arr[i][0] = arr[i][maxIndex];
        arr[i][maxIndex] = temp;
    }

    cout << "\nМасив після обміну максимальних елементів у рядках:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << arr[i][j] << "\t";
        cout << endl;
    }

    // Min
    for (int j = 0; j < cols; j++) {
        int minIndex = 0;
        for (int i = 1; i < rows; i++) {
            if (arr[i][j] < arr[minIndex][j])
                minIndex = i;
        }
        cout << "\nМінімальний елемент стовпця " << j + 1 << ": " << arr[minIndex][j] << endl;


        int temp = arr[rows - 1][j];
        arr[rows - 1][j] = arr[minIndex][j];
        arr[minIndex][j] = temp;
    }

    cout << "\nМасив після обміну мінімальних елементів у стовпцях:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << arr[i][j] << "\t";
        cout << endl;
    }

    return 0;
}
