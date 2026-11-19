#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <stdexcept>
#include <windows.h>
#include "OfficePackage.h"
#include "OfficePackageFile.h"
using namespace std;

void printTableHeader() {
    cout << string(79, '-') << endl;
    cout << "| " << left << setw(3) << "№"
        << " | " << setw(20) << "Найменування"
        << " | " << setw(15) << "Виробник"
        << " | " << setw(15) << "Складові"
        << " | " << setw(10) << "Ціна ($)" << " |" << endl;
    cout << string(79, '-') << endl;
}

int readNumber(const char* message) {
    cout << message;

    string line;
    if (!getline(cin, line)) {
        throw runtime_error("Помилка читання з клавіатури.");
    }

    istringstream input(line);
    int number;
    char extra;

    if (!(input >> number) || (input >> extra)) {
        throw invalid_argument("Необхідно ввести ціле число.");
    }

    return number;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const char* binaryFile = "packages.dat";

    OfficePackage* arr = nullptr;
    int size = 0;

    int choice = -1;

    while (choice != 0) {
        try {
            cout << "\nМЕНЮ:\n";
            cout << "1. Завантажити початкові дані з data.txt\n";
            cout << "2. Вивести масив офісних пакетів\n";
            cout << "3. Зберегти один об'єкт у бінарний файл\n";
            cout << "4. Прочитати один об'єкт із бінарного файлу\n";
            cout << "5. Зберегти весь масив у бінарний файл\n";
            cout << "6. Прочитати весь масив із бінарного файлу\n";
            cout << "0. Вихід\n";

            choice = readNumber("Оберіть дію: ");

            switch (choice) {
            case 1: {
                ifstream fin("data.txt");

                if (!fin.is_open()) {
                    throw runtime_error("Не вдалося відкрити data.txt.");
                }

                int newSize = 0;

                if (!(fin >> newSize)) {
                    throw runtime_error("Помилка читання кількості об'єктів.");
                }

                if (newSize <= 0 || newSize > 10000) {
                    throw out_of_range("Некоректна кількість об'єктів.");
                }

                OfficePackage* newArr = new OfficePackage[newSize];

                try {
                    for (int i = 0; i < newSize; i++) {
                        char tempName[50];
                        char tempManufacturer[50];
                        int tempCount;
                        double tempPrice;

                        if (!(fin >> setw(50) >> tempName
                            >> setw(50) >> tempManufacturer
                            >> tempCount >> tempPrice)) {
                            throw runtime_error("Помилка читання даних із файлу.");
                        }

                        *(newArr + i) = OfficePackage(
                            tempName, tempManufacturer,
                            tempCount, tempPrice);
                    }
                }
                catch (...) {
                    delete[] newArr;
                    throw;
                }

                fin.close();

                delete[] arr;
                arr = newArr;
                size = newSize;

                cout << "Успішно завантажено " << size
                    << " об'єктів із data.txt.\n";
                break;
            }

            case 2: {
                if (arr == nullptr || size == 0) {
                    throw runtime_error("Масив порожній.");
                }

                cout << "\nМАСИВ ОФІСНИХ ПАКЕТІВ\n";
                printTableHeader();

                for (int i = 0; i < size; i++) {
                    (*(arr + i)).show(i + 1);
                }

                break;
            }

            case 3: {
                if (arr == nullptr || size == 0) {
                    throw runtime_error("Спочатку завантажте масив.");
                }

                cout << "\nЗБЕРЕЖЕННЯ ОДНОГО ОБ'ЄКТА\n";

                int number = readNumber("Введіть номер об'єкта: ");

                if (number < 1 || number > size) {
                    throw out_of_range("Об'єкта з таким номером немає.");
                }

                OfficePackageFile::saveOne(
                    *(arr + number - 1), binaryFile);

                cout << "Об'єкт №" << number
                    << " успішно збережено у packages.dat.\n";
                break;
            }

            case 4: {
                cout << "\nЧИТАННЯ ОДНОГО ОБ'ЄКТА\n";

                int number = readNumber("Введіть номер об'єкта у файлі: ");

                OfficePackage package =
                    OfficePackageFile::loadOne(binaryFile, number);

                cout << "\nЗНАЙДЕНИЙ ОБ'ЄКТ\n";
                printTableHeader();
                package.show(number);

                break;
            }

            case 5: {
                if (arr == nullptr || size == 0) {
                    throw runtime_error("Спочатку завантажте масив.");
                }

                OfficePackageFile::saveAll(
                    arr, size, binaryFile);

                cout << "Успішно збережено " << size
                    << " об'єктів у packages.dat.\n";
                break;
            }

            case 6: {
                int newSize = 0;

                OfficePackage* newArr =
                    OfficePackageFile::loadAll(binaryFile, newSize);

                delete[] arr;

                arr = newArr;
                size = newSize;

                cout << "Успішно прочитано " << size
                    << " об'єктів із packages.dat.\n";

                break;
            }

            case 0:
                cout << "Завершення роботи...\n";
                break;

            default:
                throw invalid_argument("Невірний пункт меню.");
            }
        }
        catch (const exception& e) {
            cout << "Помилка: " << e.what() << endl;
        }
    }

    delete[] arr;

    return 0;
}