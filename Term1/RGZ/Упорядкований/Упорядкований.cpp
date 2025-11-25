#include <iostream>    
#include <vector>
#include <chrono>
#include <windows.h>
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

    vector<vector<int>> buckets(n);
    for (int i = 0; i < n; i++) {
        int index = (arr[i] * n) / (maxVal + 1);
        buckets[index].push_back(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < buckets[i].size(); j++) {
            int temp = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > temp) {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = temp;
        }
    }

    int idx = 0;
    for (int i = 0; i < n; i++)
        for (int x : buckets[i])
            arr[idx++] = x;
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

    vector<int> allowed = { 5,10,15,20,25,30,35,40,45 };
    int arrFull[45] = { 20, 5, 12, 8, 3, 25, 15, 18, 7, 10,
                        1, 9, 14, 11, 4, 6, 2, 13, 16, 17,
                        19, 21, 22, 23, 24, 26, 27, 28, 29, 30,
                        31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
                        41, 42, 43, 44, 45 };

    const int REPEATS = 100;  

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

        long long totalTimeShell = 0;  
        long long totalTimeBlock = 0;  

        cout << "\nВсі 100 кроків сортування:\n";

        for (int step = 1; step <= REPEATS; step++) {
            int* arrShell = new int[n];
            int* arrBlock = new int[n];

            for (int i = 0; i < n; i++) {
                arrShell[i] = arrFull[i];
                arrBlock[i] = arrFull[i];
            }

            // Час сортування Шелла
            auto startShell = high_resolution_clock::now();
            shellSort(arrShell, n);
            auto endShell = high_resolution_clock::now();
            auto timeShell = duration_cast<nanoseconds>(endShell - startShell).count();
            totalTimeShell += timeShell;

            // Час блокового сортування
            auto startBlock = high_resolution_clock::now();
            blockSort(arrBlock, n);
            auto endBlock = high_resolution_clock::now();
            auto timeBlock = duration_cast<nanoseconds>(endBlock - startBlock).count();
            totalTimeBlock += timeBlock;

            // Вивід часу для кожного кроку
            cout << "Крок " << step << ": Шелла = " << timeShell
                << " нс, Блокове = " << timeBlock << " нс\n";

            delete[] arrShell;
            delete[] arrBlock;
        }

        // Середнє значення часу
        double avgShell = totalTimeShell / (double)REPEATS;
        double avgBlock = totalTimeBlock / (double)REPEATS;

        cout << "\nСередній час після " << REPEATS << " повторів:\n";
        cout << "Шелла: " << avgShell << " нс\n";
        cout << "Блокове: " << avgBlock << " нс\n";

        cout << "\nБажаєте повторити з іншою кількістю елементів? (1 — Так, 0 — Вихід): ";
        int choice;
        cin >> choice;
        if (choice == 0) exitProgram = true;
    }

    cout << "\nПрограма завершена.\n";
    return 0;
}
