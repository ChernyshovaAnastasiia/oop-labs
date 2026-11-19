#include "OfficePackageFile.h"
#include <fstream>
#include <cstring>
#include <stdexcept>
#include <climits>
using namespace std;

void OfficePackageFile::writeRecord(ostream& out, const OfficePackage& package) {
    const char* name = package.getName();
    const char* manufacturer = package.getManufacturer();

    int nameLength = strlen(name);
    int manufacturerLength = strlen(manufacturer);

    if (nameLength > 4096 || manufacturerLength > 4096) {
        throw length_error("Занадто довгий рядок.");
    }

    int componentCount = package.getComponentCount();
    double price = package.getPrice();

    out.write((const char*)&nameLength, sizeof(nameLength));
    out.write(name, nameLength);

    out.write((const char*)&manufacturerLength, sizeof(manufacturerLength));
    out.write(manufacturer, manufacturerLength);

    out.write((const char*)&componentCount, sizeof(componentCount));
    out.write((const char*)&price, sizeof(price));

    if (!out) {
        throw runtime_error("Помилка запису об'єкта у бінарний файл.");
    }
}

OfficePackage OfficePackageFile::readRecord(istream& in) {
    int nameLength = 0;

    if (!in.read((char*)&nameLength, sizeof(nameLength))) {
        throw runtime_error("Помилка читання довжини назви.");
    }

    if (nameLength < 0 || nameLength > 4096) {
        throw length_error("Некоректна довжина назви.");
    }

    char* name = new char[nameLength + 1];
    char* manufacturer = nullptr;

    try {
        if (!in.read(name, nameLength)) {
            throw runtime_error("Помилка читання назви.");
        }
        *(name + nameLength) = '\0';

        int manufacturerLength = 0;

        if (!in.read((char*)&manufacturerLength, sizeof(manufacturerLength))) {
            throw runtime_error("Помилка читання довжини виробника.");
        }

        if (manufacturerLength < 0 || manufacturerLength > 4096) {
            throw length_error("Некоректна довжина виробника.");
        }

        manufacturer = new char[manufacturerLength + 1];

        if (!in.read(manufacturer, manufacturerLength)) {
            throw runtime_error("Помилка читання виробника.");
        }
        *(manufacturer + manufacturerLength) = '\0';

        int componentCount;
        double price;

        if (!in.read((char*)&componentCount, sizeof(componentCount))) {
            throw runtime_error("Помилка читання кількості складових.");
        }

        if (!in.read((char*)&price, sizeof(price))) {
            throw runtime_error("Помилка читання ціни.");
        }

        OfficePackage package(name, manufacturer, componentCount, price);

        delete[] name;
        delete[] manufacturer;

        return package;
    }
    catch (...) {
        delete[] name;
        delete[] manufacturer;
        throw;
    }
}

void OfficePackageFile::saveOne(const OfficePackage& package, const char* fileName) {
    if (fileName == nullptr || *fileName == '\0') {
        throw invalid_argument("Некоректна назва файлу.");
    }

    fstream file(fileName, ios::binary | ios::in | ios::out);

    if (!file.is_open()) {
        ofstream createFile(fileName, ios::binary | ios::app);

        if (!createFile.is_open()) {
            throw runtime_error("Не вдалося створити бінарний файл.");
        }

        createFile.close();

        file.clear();
        file.open(fileName, ios::binary | ios::in | ios::out);

        if (!file.is_open()) {
            throw runtime_error("Не вдалося відкрити бінарний файл.");
        }
    }

    file.seekg(0, ios::end);
    streampos fileSize = file.tellg();

    if (fileSize == streampos(-1)) {
        throw runtime_error("Не вдалося визначити розмір файлу.");
    }

    int count = 0;

    if (fileSize == streampos(0)) {
        file.seekp(0, ios::beg);
        file.write((const char*)&count, sizeof(count));

        if (!file) {
            throw runtime_error("Помилка створення заголовка файлу.");
        }
    }
    else {
        if (fileSize < static_cast<streamoff>(sizeof(int))) {
            throw runtime_error("Пошкоджений заголовок файлу.");
        }

        file.seekg(0, ios::beg);
        file.read((char*)&count, sizeof(count));

        if (!file || count < 0 || count == INT_MAX) {
            throw runtime_error("Некоректна кількість записів у файлі.");
        }
    }

    file.clear();
    file.seekp(0, ios::end);

    writeRecord(file, package);

    file.flush();

    if (!file) {
        throw runtime_error("Не вдалося зберегти об'єкт.");
    }

    count++;

    file.seekp(0, ios::beg);
    file.write((const char*)&count, sizeof(count));
    file.flush();

    if (!file) {
        throw runtime_error("Не вдалося оновити кількість записів.");
    }

    file.close();
}

OfficePackage OfficePackageFile::loadOne(const char* fileName, const int number) {
    if (fileName == nullptr || *fileName == '\0') {
        throw invalid_argument("Некоректна назва файлу.");
    }

    ifstream fin(fileName, ios::binary);

    if (!fin.is_open()) {
        throw runtime_error("Не вдалося відкрити бінарний файл.");
    }

    int count = 0;

    if (!fin.read((char*)&count, sizeof(count))) {
        throw runtime_error("Помилка читання кількості записів.");
    }

    if (count < 0) {
        throw runtime_error("Некоректна кількість записів у файлі.");
    }

    if (number < 1 || number > count) {
        throw out_of_range("Об'єкта з таким номером у файлі немає.");
    }

    for (int i = 1; i < number; i++) {
        readRecord(fin);
    }

    OfficePackage package = readRecord(fin);

    fin.close();

    return package;
}

void OfficePackageFile::saveAll(const OfficePackage* packages,
    const int count, const char* fileName) {

    if (fileName == nullptr || *fileName == '\0') {
        throw invalid_argument("Некоректна назва файлу.");
    }

    if (packages == nullptr || count <= 0) {
        throw invalid_argument("Масив порожній або некоректний.");
    }

    ofstream fout(fileName, ios::binary | ios::trunc);

    if (!fout.is_open()) {
        throw runtime_error("Не вдалося відкрити бінарний файл для запису.");
    }

    fout.write((const char*)&count, sizeof(count));

    if (!fout) {
        throw runtime_error("Помилка запису кількості об'єктів.");
    }

    for (int i = 0; i < count; i++) {
        writeRecord(fout, *(packages + i));
    }

    fout.flush();

    if (!fout) {
        throw runtime_error("Помилка збереження масиву у файл.");
    }

    fout.close();

    if (!fout) {
        throw runtime_error("Помилка закриття бінарного файлу.");
    }
}

OfficePackage* OfficePackageFile::loadAll(const char* fileName, int& count) {
    if (fileName == nullptr || *fileName == '\0') {
        throw invalid_argument("Некоректна назва файлу.");
    }

    ifstream fin(fileName, ios::binary);

    if (!fin.is_open()) {
        throw runtime_error("Не вдалося відкрити бінарний файл.");
    }

    int newCount = 0;

    if (!fin.read((char*)&newCount, sizeof(newCount))) {
        throw runtime_error("Помилка читання кількості об'єктів.");
    }

    if (newCount <= 0 || newCount > 10000) {
        throw runtime_error("Некоректна кількість об'єктів у файлі.");
    }

    OfficePackage* newArr = new OfficePackage[newCount];

    try {
        for (int i = 0; i < newCount; i++) {
            *(newArr + i) = readRecord(fin);
        }
    }
    catch (...) {
        delete[] newArr;
        throw;
    }

    fin.close();

    count = newCount;

    return newArr;
}