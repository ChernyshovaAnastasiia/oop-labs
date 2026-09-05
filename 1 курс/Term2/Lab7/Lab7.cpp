#include <windows.h>
#include "functions.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand((unsigned)time(0));

    int choice;

    for (;;) {
        cout << "\nМЕНЮ\n" << endl;
        cout << "1 - Введення з екрану і запис у файл" << endl;
        cout << "2 - Введення випадковим чином і запис у файл" << endl;
        cout << "3 - Додати запис в початок файлу" << endl;
        cout << "4 - Додати запис в кінець файлу" << endl;
        cout << "5 - Друк одного запису з файлу по номеру" << endl;
        cout << "6 - Друк всіх записів з файлу" << endl;
        cout << "7 - Змінити будь-яке поле в запису" << endl;
        cout << "8 - Вихід з програми" << endl;
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
        case 1: createFileFromScreen(); break;
        case 2: createFileRandom(); break;
        case 3: addRecordToBeginning(); break;
        case 4: addRecordToEnd(); break;
        case 5: printRecordByNumber(); break;
        case 6: printAllRecords(); break;
        case 7: modifyRecordField(); break;
        case 8: cout << "Роботу завершено." << endl; return 0;
        default: cout << "Невірний вибір. Спробуйте ще раз." << endl;
        }
    }

    return 0;
}