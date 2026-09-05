// Lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <windows.h>
using namespace std;

struct OfficePackage {
    string name;
    string producer;
    int components;
    double price;
};

const int MAX_SIZE = 100;

void inputFromScreen(OfficePackage data[], int& count) {
    cout << "Введіть кількість пакетів: ";
    cin >> count;
    for (int i = 0; i < count; i++) {
        cout << "Пакет #" << i + 1 << endl;
        cout << "Найменування: "; cin >> data[i].name;
        cout << "Виробник: "; cin >> data[i].producer;
        cout << "Кількість складових: "; cin >> data[i].components;
        cout << "Ціна ($): "; cin >> data[i].price;
    }
}

void inputRandom(OfficePackage data[], int& count) {
    count = 3;
    OfficePackage temp[3] = {
        {"Office", "Microsoft", 4, 870},
        {"SmartSuite", "Lotus", 5, 1020},
        {"StarOffice", "Sun", 4, 9}
    };
    srand(time(0));
    for (int i = 0; i < count; i++) {
        int j = rand() % count;
        swap(temp[i], temp[j]);
    }
    for (int i = 0; i < count; i++) {
        data[i] = temp[i];
    }
    cout << "Дані заповнені випадково з таблиці.\n";
}

void sortData(OfficePackage data[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (data[j].name > data[j + 1].name) {
                swap(data[j], data[j + 1]);
            }
        }
    }
    cout << "Сортування за найменуванням завершено.\n";
}

void printData(OfficePackage data[], int count) {
    if (count == 0) {
        cout << "Таблиця порожня.\n";
        return;
    }

    cout << "\n" << setfill('-') << setw(65) << "-" << setfill(' ') << endl;
    cout << "| " << left << setw(61) << "Офісні пакети" << " |" << endl;
    cout << "|" << setfill('-') << setw(63) << "-" << setfill(' ') << "|" << endl;

    cout << "|" << setw(15) << "Найменування"
        << "|" << setw(15) << "Виробник"
        << "|" << setw(20) << "К-сть складових"
        << "|" << setw(10) << "Ціна ($)" << "|" << endl;

    cout << "|" << setfill('-') << setw(63) << "-" << setfill(' ') << "|" << endl;

    for (int i = 0; i < count; i++) {
        cout << "|" << setw(15) << data[i].name
            << "|" << setw(15) << data[i].producer
            << "|" << setw(20) << data[i].components
            << "|" << setw(10) << data[i].price << "|" << endl;
    }
    cout << setfill('-') << setw(65) << "-" << setfill(' ') << endl;
    cout << "Примітка: можливо безкоштовно отримати продукт StarOffice через Internet\n";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    OfficePackage packages[MAX_SIZE];
    int count = 0;
    int choice;

    for (;;) {
        cout << "\n--- МЕНЮ ---" << endl;
        cout << "1 – Заповнення структури з екрану" << endl;
        cout << "2 – Заповнення структури випадковим чином" << endl;
        cout << "3 – Сортування структури (по назві)" << endl;
        cout << "4 – Друк структури" << endl;
        cout << "5 – Вихід" << endl;
        cout << "Ваш вибір: ";
        cin >> choice;

        if (choice == 1) inputFromScreen(packages, count);
        else if (choice == 2) inputRandom(packages, count);
        else if (choice == 3) sortData(packages, count);
        else if (choice == 4) printData(packages, count);
        else if (choice == 5) break;
        else cout << "Невірний вибір, спробуйте ще раз." << endl;
    }

    return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
