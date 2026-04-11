#include <algorithm>
#include "functions.h"

void inputFromScreen(OfficePackage data[], int& count) {
    START_DEBUG();
    cout << "Введіть кількість пакетів: ";
    cin >> count;
    for (int i = 0; i < count; i++) {
        cout << "Пакет #" << i + 1 << endl;
        cout << "Найменування: "; cin >> data[i].name;
        cout << "Виробник: "; cin >> data[i].producer;
        cout << "Кількість складових: "; cin >> data[i].components;
        cout << "Ціна ($): "; cin >> data[i].price;
    }
    END_DEBUG();
}

void inputRandom(OfficePackage data[], int& count) {
    START_DEBUG();
    count = 3;
    OfficePackage temp[3] = {
        {"Office", "Microsoft", 4, 870},
        {"SmartSuite", "Lotus", 5, 1020},
        {"StarOffice", "Sun", 4, 9}
    };
    srand((unsigned int)time(0));
    for (int i = 0; i < count; i++) {
        int j = rand() % count;
        swap(temp[i], temp[j]);
    }
    for (int i = 0; i < count; i++) {
        data[i] = temp[i];
    }
    cout << "Дані заповнені випадково.\n";
    END_DEBUG();
}

void sortData(OfficePackage data[], int count) {
    START_DEBUG();
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (data[j].name > data[j + 1].name) {
                swap(data[j], data[j + 1]);
            }
        }
    }
    cout << "Сортування завершено.\n";
    END_DEBUG();
}

void printData(OfficePackage data[], int count) {
    START_DEBUG();
    if (count == 0) {
        cout << "Таблиця порожня.\n";
    }
    else {
        cout << "\n" << setfill('-') << setw(65) << "-" << setfill(' ') << endl;
        cout << "| " << left << setw(61) << "Офісні пакети" << " |" << endl;
        cout << "|" << setfill('-') << setw(63) << "-" << setfill(' ') << "|" << endl;
        cout << "|" << setw(15) << "Найменування" << "|" << setw(15) << "Виробник"
            << "|" << setw(20) << "К-сть складових" << "|" << setw(10) << "Ціна ($)" << "|" << endl;
        cout << "|" << setfill('-') << setw(63) << "-" << setfill(' ') << "|" << endl;

        for (int i = 0; i < count; i++) {
            cout << "|" << setw(15) << data[i].name << "|" << setw(15) << data[i].producer
                << "|" << setw(20) << data[i].components << "|" << setw(10) << data[i].price << "|" << endl;
        }
        cout << setfill('-') << setw(65) << "-" << setfill(' ') << endl;
    }
    END_DEBUG();
}