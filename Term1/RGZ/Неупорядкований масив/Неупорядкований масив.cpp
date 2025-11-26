#include <iostream>
#include <chrono>
#include <windows.h>
#include <cstdlib> 
#include <ctime>   
using namespace std;
using namespace chrono;

// Сортування Шелла 
void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

// Блокове сортування   
void blockSort(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal)
            maxVal = arr[i];

    int buckets[45][45]; 
    int bucketSize[45] = { 0 };

	// Розкладання по блоках
    for (int i = 0; i < n; i++) {
        int index = (arr[i] * n) / (maxVal + 1);
        int pos = bucketSize[index];
        buckets[index][pos] = arr[i];
        bucketSize[index]++;
    }

	// Сортування всередині блоків 
    for (int b = 0; b < n; b++) {
        for (int j = 1; j < bucketSize[b]; j++) {
            int temp = buckets[b][j];
            int k = j - 1;
            while (k >= 0 && buckets[b][k] > temp) {
                buckets[b][k + 1] = buckets[b][k];
                k--;
            }
            buckets[b][k + 1] = temp;
        }
    }

	// Запис назад у масив
    int idx = 0;
    for (int b = 0; b < n; b++) {
        for (int i = 0; i < bucketSize[b]; i++) {
            arr[idx++] = buckets[b][i];
        }
    }
}

// Вивід масиву 
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int allowed[9] = { 5,10,15,20,25,30,35,40,45 };
    srand(static_cast<unsigned>(time(0))); 

    bool exitProgram = false;

    while (!exitProgram) {

        int n;
        cout << "\nОберіть кількість елементів (5,10,15,20,25,30,35,40,45): ";
        cin >> n;

        bool valid = false;
        for (int x : allowed)
            if (x == n) valid = true;
        if (!valid) {
            cout << "Неправильна кількість елементів." << endl;
            continue;
        }

        int* arrShell = new int[n];
        int* arrBlock = new int[n];

		// Випадкове заповнення масивів
        for (int i = 0; i < n; i++) {
            arrShell[i] = rand() % 100 + 1;  
            arrBlock[i] = arrShell[i];       
        }

		// Вивід масиву перед сортуванням   
        cout << "\nВипадковий масив (" << n << " елементів):\n";
        printArray(arrShell, n);

		// Час сортування Шелла
        auto startShell = high_resolution_clock::now();
        shellSort(arrShell, n);
        auto endShell = high_resolution_clock::now();
        auto timeShell = duration_cast<nanoseconds>(endShell - startShell);

		// Час блокового сортування
        auto startBlock = high_resolution_clock::now();
        blockSort(arrBlock, n);
        auto endBlock = high_resolution_clock::now();
        auto timeBlock = duration_cast<nanoseconds>(endBlock - startBlock);

		// Вивід результатів
        cout << "\nМасив після сортування Шелла:\n";
        printArray(arrShell, n);
        cout << "Час (Шелла): " << timeShell.count() << " наносекунд\n";

        cout << "\nМасив після блокового сортування:\n";
        printArray(arrBlock, n);
        cout << "Час (Блокове): " << timeBlock.count() << " наносекунд\n";


        // 
        cout << "\nБажаєте повторити з іншою кількістю елементів? (1 — Так, 0 — Вихід): ";
        int choice;
        cin >> choice;
        if (choice == 0) exitProgram = true;
    }

    cout << "\nПрограма завершена.\n";
    return 0;
}