#include <windows.h>
#include "functions.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    OfficePackage packages[MAX_SIZE];
    int count = 0;
    int choice;

    for (;;) {
        cout << "\n--- МЕНЮ ---" << endl;
        cout << "1 – Заповнення структури" << endl;
        cout << "2 – Сортування структури" << endl;
        cout << "3 – Друк структури" << endl;
        cout << "4 – Вихід" << endl;
        cout << "Ваш вибір: ";
        cin >> choice;

        if (choice == 1) {

#if PRINT_TYPE == 1
            inputFromScreen(packages, count);
#else
            inputRandom(packages, count);
#endif
        }
        else if (choice == 2) sortData(packages, count);
        else if (choice == 3) printData(packages, count);
        else if (choice == 4) break;
        else cout << "Невірний вибір." << endl;
    }

    return 0;
}