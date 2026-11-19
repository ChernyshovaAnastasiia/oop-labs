#define _CRT_SECURE_NO_WARNINGS
#include "OfficePackage.h"
#include <iostream>
#include <cstring>
#include <iomanip>
#include <stdexcept>
#include <string>
using namespace std;

OfficePackage::OfficePackage()
    : OfficePackage("", "", 0, 0.0) {
}

OfficePackage::OfficePackage(const char* nameInit,
    const char* manufacturerInit,
    const int componentCountInit,
    const double priceInit)
    : name(nullptr), manufacturer(nullptr),
    componentCount(componentCountInit), price(priceInit) {

    if (nameInit == nullptr || manufacturerInit == nullptr) {
        throw invalid_argument("Назва або виробник не можуть бути nullptr.");
    }

    if (componentCountInit < 0 || priceInit < 0) {
        throw invalid_argument("Кількість складових та ціна не можуть бути від'ємними.");
    }

    name = new char[strlen(nameInit) + 1];

    try {
        manufacturer = new char[strlen(manufacturerInit) + 1];
    }
    catch (...) {
        delete[] name;
        throw;
    }

    strcpy(name, nameInit);
    strcpy(manufacturer, manufacturerInit);
}

OfficePackage::OfficePackage(const OfficePackage& other)
    : OfficePackage(other.name, other.manufacturer,
        other.componentCount, other.price) {
}

OfficePackage::~OfficePackage() {
    delete[] name;
    delete[] manufacturer;
}

OfficePackage& OfficePackage::operator=(const OfficePackage& other) {
    if (this != &other) {
        char* newName = new char[strlen(other.name) + 1];
        char* newManufacturer = nullptr;

        try {
            newManufacturer = new char[strlen(other.manufacturer) + 1];
        }
        catch (...) {
            delete[] newName;
            throw;
        }

        strcpy(newName, other.name);
        strcpy(newManufacturer, other.manufacturer);

        delete[] name;
        delete[] manufacturer;

        name = newName;
        manufacturer = newManufacturer;
        componentCount = other.componentCount;
        price = other.price;
    }

    return *this;
}

void OfficePackage::setName(const char* nameInit) {
    if (nameInit == nullptr) {
        throw invalid_argument("Некоректна назва пакета.");
    }

    char* newName = new char[strlen(nameInit) + 1];
    strcpy(newName, nameInit);

    delete[] name;
    name = newName;
}

void OfficePackage::setManufacturer(const char* manufacturerInit) {
    if (manufacturerInit == nullptr) {
        throw invalid_argument("Некоректний виробник.");
    }

    char* newManufacturer = new char[strlen(manufacturerInit) + 1];
    strcpy(newManufacturer, manufacturerInit);

    delete[] manufacturer;
    manufacturer = newManufacturer;
}

void OfficePackage::setComponentCount(const int componentCountInit) {
    if (componentCountInit < 0) {
        throw invalid_argument("Кількість складових не може бути від'ємною.");
    }

    componentCount = componentCountInit;
}

void OfficePackage::setPrice(const double priceInit) {
    if (priceInit < 0) {
        throw invalid_argument("Ціна не може бути від'ємною.");
    }

    price = priceInit;
}

const char* OfficePackage::getName() const {
    return name;
}

const char* OfficePackage::getManufacturer() const {
    return manufacturer;
}

int OfficePackage::getComponentCount() const {
    return componentCount;
}

double OfficePackage::getPrice() const {
    return price;
}

void OfficePackage::show(const int number) const {
    cout << "| " << left << setw(3) << number
        << " | " << setw(20) << name
        << " | " << setw(15) << manufacturer
        << " | " << setw(15) << componentCount
        << " | " << setw(10) << price << " |" << endl;

    cout << string(79, '-') << endl;
}