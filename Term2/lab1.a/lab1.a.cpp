#include <iostream>
#include <windows.h>
using namespace std;

const int MAX_SIZE = 100;

int arr[MAX_SIZE];
int n;
int max1, max2;

void reverseSequence(int index) {
    if (index == n)
        return;

    if (arr[index] > max1) {
        max2 = max1;
        max1 = arr[index];
    }
    else if (arr[index] > max2 && arr[index] != max1) {
        max2 = arr[index];
    }

    reverseSequence(index + 1);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Введіть кількість елементів: ";
    cin >> n;

    cout << "Введіть елементи масиву:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Масив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    max1 = arr[0];
    max2 = INT_MIN;

    reverseSequence(0);

    cout << "Максимальний елемент: " << max1 << endl;
    cout << "Другий за величиною: " << max2 << endl;

    return 0;
}