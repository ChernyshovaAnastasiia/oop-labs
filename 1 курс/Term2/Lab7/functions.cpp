#include "functions.h"

void printHeader() {
    cout << "\n" << setfill('-') << setw(65) << "-" << setfill(' ') << endl;
    cout << "| " << left << setw(61) << "Офісні пакети" << " |" << endl;
    cout << "|" << setfill('-') << setw(63) << "-" << setfill(' ') << "|" << endl;
    cout << "|" << setw(15) << "Найменування" << "|" << setw(15) << "Виробник"
        << "|" << setw(20) << "К-сть складових" << "|" << setw(10) << "Ціна ($)" << "|" << endl;
    cout << "|" << setfill('-') << setw(63) << "-" << setfill(' ') << "|" << endl;
}

void printRecord(const OfficePackage& pkg) {
    cout << "|" << left << setw(15) << pkg.name << "|" << setw(15) << pkg.producer
        << "|" << right << setw(20) << pkg.components << "|" << setw(10) << pkg.price << "|" << endl;
}

void createFileFromScreen() {
    START_DEBUG();
    FILE* f;
    if (fopen_s(&f, FILENAME, "wb") != 0) {
        cout << "Помилка створення файлу." << endl; return;
    }

    int count;
    cout << "Введіть кількість пакетів для запису: ";
    cin >> count;

    OfficePackage pkg;
    for (int i = 0; i < count; i++) {
        cout << "Пакет #" << i + 1 << endl;
        cout << "Найменування: "; cin >> pkg.name;
        cout << "Виробник: "; cin >> pkg.producer;
        cout << "Кількість складових: "; cin >> pkg.components;
        cout << "Ціна ($): "; cin >> pkg.price;

        fwrite(&pkg, sizeof(OfficePackage), 1, f);
    }
    fclose(f);
    cout << "Дані успішно збережено у файл." << endl;
    END_DEBUG();
}

void createFileRandom() {
    START_DEBUG();
    FILE* f;
    if (fopen_s(&f, FILENAME, "wb") != 0) {
        cout << "Помилка створення файлу." << endl; return;
    }

    int count;
    cout << "Введіть кількість випадкових пакетів для генерації: ";
    cin >> count;

    OfficePackage templates[3] = {
        {"Office", "Microsoft", 4, 870.0},
        {"SmartSuite", "Lotus", 5, 1020.0},
        {"StarOffice", "Sun", 4, 9.0}
    };

    OfficePackage pkg;
    for (int i = 0; i < count; i++) {
        pkg = templates[rand() % 3];

        fwrite(&pkg, sizeof(OfficePackage), 1, f);
    }
    fclose(f);
    cout << "Файл успішно заповнено випадковими пакетами." << endl;
    END_DEBUG();
}

void addRecordToBeginning() {
    START_DEBUG();
    OfficePackage newPkg;
    cout << "\n Новий запис (у початок) " << endl;
    cout << "Найменування: "; cin >> newPkg.name;
    cout << "Виробник: "; cin >> newPkg.producer;
    cout << "Кількість складових: "; cin >> newPkg.components;
    cout << "Ціна ($): "; cin >> newPkg.price;

    if (rename(FILENAME, "temp.dat") != 0) {
        FILE* f;
        fopen_s(&f, FILENAME, "wb");
        fwrite(&newPkg, sizeof(OfficePackage), 1, f);
        fclose(f);
        cout << "Файл не існував, створено новий із цим записом." << endl;
        return;
    }

    FILE* fNew, * fOld;
    fopen_s(&fNew, FILENAME, "wb");
    fopen_s(&fOld, "temp.dat", "rb");

    fwrite(&newPkg, sizeof(OfficePackage), 1, fNew);

    OfficePackage temp;
    while (fread(&temp, sizeof(OfficePackage), 1, fOld) == 1) {
        fwrite(&temp, sizeof(OfficePackage), 1, fNew);
    }

    fclose(fNew);
    fclose(fOld);
    remove("temp.dat");
    cout << "Запис успішно додано в початок файлу." << endl;
    END_DEBUG();
}

void addRecordToEnd() {
    START_DEBUG();
    FILE* f;
    if (fopen_s(&f, FILENAME, "ab") != 0) {
        cout << "Помилка відкриття файлу." << endl; return;
    }

    OfficePackage newPkg;
    cout << "\n--- Новий запис (у кінець) ---" << endl;
    cout << "Найменування: "; cin >> newPkg.name;
    cout << "Виробник: "; cin >> newPkg.producer;
    cout << "Кількість складових: "; cin >> newPkg.components;
    cout << "Ціна ($): "; cin >> newPkg.price;

    fwrite(&newPkg, sizeof(OfficePackage), 1, f);
    fclose(f);
    cout << "Запис успішно додано в кінець файлу." << endl;
    END_DEBUG();
}

void printRecordByNumber() {
    START_DEBUG();
    FILE* f;
    if (fopen_s(&f, FILENAME, "rb") != 0) {
        cout << "Помилка. файл ще не створено." << endl; return;
    }

    int num;
    cout << "Введіть номер запису (починаючи з 1): "; cin >> num;

    fseek(f, 0, SEEK_END);
    long fileSize = ftell(f);
    long numRecords = fileSize / sizeof(OfficePackage);

    if (num < 1 || num > numRecords) {
        cout << "Помилка. такого запису немає. Всього записів: " << numRecords << endl;
        fclose(f);
        return;
    }

    fseek(f, (num - 1) * sizeof(OfficePackage), SEEK_SET);

    OfficePackage pkg;
    fread(&pkg, sizeof(OfficePackage), 1, f);

    printHeader();
    printRecord(pkg);
    cout << setfill('-') << setw(65) << "-" << setfill(' ') << endl;

    fclose(f);
    END_DEBUG();
}

void printAllRecords() {
    START_DEBUG();
    FILE* f;
    if (fopen_s(&f, FILENAME, "rb") != 0) {
        cout << "Помилка. файл ще не створено." << endl; return;
    }

    printHeader();
    OfficePackage pkg;
    int count = 0;

    while (fread(&pkg, sizeof(OfficePackage), 1, f) == 1) {
        printRecord(pkg);
        count++;
    }

    cout << setfill('-') << setw(65) << "-" << setfill(' ') << endl;
    if (count == 0) cout << "Файл порожній." << endl;

    fclose(f);
    END_DEBUG();
}

void modifyRecordField() {
    START_DEBUG();
    FILE* f;
    if (fopen_s(&f, FILENAME, "r+b") != 0) {
        cout << "Помилка. файл ще не створено." << endl; return;
    }

    int num;
    cout << "Введіть номер запису для редагування (починаючи з 1): "; cin >> num;

    fseek(f, 0, SEEK_END);
    long fileSize = ftell(f);
    long numRecords = fileSize / sizeof(OfficePackage);

    if (num < 1 || num > numRecords) {
        cout << "Помилка. запису з таким номером не існує!" << endl;
        fclose(f);
        return;
    }

    long offset = (num - 1) * sizeof(OfficePackage);
    fseek(f, offset, SEEK_SET);

    OfficePackage pkg;
    fread(&pkg, sizeof(OfficePackage), 1, f);

    cout << "\n Поточні дані запису " << endl;
    cout << "1. Найменування: " << pkg.name << endl;
    cout << "2. Виробник:     " << pkg.producer << endl;
    cout << "3. Складові:     " << pkg.components << endl;
    cout << "4. Ціна ($):     " << pkg.price << endl;

    int choice;
    cout << "Яке поле ви хочете змінити? (1-4): "; cin >> choice;

    switch (choice) {
    case 1: cout << "Нове найменування: "; cin >> pkg.name; break;
    case 2: cout << "Новий виробник: "; cin >> pkg.producer; break;
    case 3: cout << "Нова к-сть складових: "; cin >> pkg.components; break;
    case 4: cout << "Нова ціна: "; cin >> pkg.price; break;
    default: cout << "Некоректний вибір. Скасування." << endl; fclose(f); return;
    }

    fseek(f, offset, SEEK_SET);
    fwrite(&pkg, sizeof(OfficePackage), 1, f);

    cout << "Запис успішно оновлено." << endl;
    fclose(f);
    END_DEBUG();
}