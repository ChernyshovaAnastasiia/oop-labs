#define _CRT_SECURE_NO_WARNINGS
#include "OfficePackage.h"
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

OfficePackage::OfficePackage() : componentCount(0), price(0.0) {
    name = new char[1];
    *name = '\0';
    manufacturer = new char[1];
    *manufacturer = '\0';
}

OfficePackage::OfficePackage(const char* nameInit, const char* manufacturerInit, const int componentCountInit, const double priceInit)
    : componentCount(componentCountInit), price(priceInit) {
    name = new char[strlen(nameInit) + 1];
    strcpy(name, nameInit);
    manufacturer = new char[strlen(manufacturerInit) + 1];
    strcpy(manufacturer, manufacturerInit);
}

OfficePackage::OfficePackage(const OfficePackage& other)
    : componentCount(other.componentCount), price(other.price) {
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
    manufacturer = new char[strlen(other.manufacturer) + 1];
    strcpy(manufacturer, other.manufacturer);
}

OfficePackage::~OfficePackage() {
    delete[] name;
    delete[] manufacturer;
}

void OfficePackage::setName(const char* nameInit) {
    delete[] name;
    name = new char[strlen(nameInit) + 1];
    strcpy(name, nameInit);
}

void OfficePackage::setManufacturer(const char* manufacturerInit) {
    delete[] manufacturer;
    manufacturer = new char[strlen(manufacturerInit) + 1];
    strcpy(manufacturer, manufacturerInit);
}

void OfficePackage::setComponentCount(const int componentCountInit) {
    componentCount = componentCountInit;
}

void OfficePackage::setPrice(const double priceInit) {
    price = priceInit;
}

const char* OfficePackage::getName() const { return name; }
const char* OfficePackage::getManufacturer() const { return manufacturer; }
int OfficePackage::getComponentCount() const { return componentCount; }
double OfficePackage::getPrice() const { return price; }

void OfficePackage::show() const {
    cout << "| " << left << setw(20) << name
        << " | " << setw(15) << manufacturer
        << " | " << setw(15) << componentCount
        << " | " << setw(10) << price << " |" << endl;
    cout << "-------------------------------------------------------------------------" << endl;
}

OfficePackage& OfficePackage::operator=(const OfficePackage& other) {
    if (this != &other) {
        delete[] name;
        delete[] manufacturer;

        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);

        manufacturer = new char[strlen(other.manufacturer) + 1];
        strcpy(manufacturer, other.manufacturer);

        componentCount = other.componentCount;
        price = other.price;
    }
    return *this;
}

bool OfficePackage::operator==(const OfficePackage& other) const {
    return this->price == other.price;
}

OfficePackage OfficePackage::operator+(const double extraPrice) const {
    return OfficePackage(this->name, this->manufacturer, this->componentCount, this->price + extraPrice);
}

bool operator==(const char* searchName, const OfficePackage& obj) {
    if (!searchName || !obj.name) return false;
    return strcmp(searchName, obj.name) == 0;
}

OfficePackage operator+(const int extraComp, const OfficePackage& obj) {
    return OfficePackage(obj.name, obj.manufacturer, obj.componentCount + extraComp, obj.price);
}

int OfficePackage::operator[](const int index) const {
    if (index == 0) return strlen(name);
    if (index == 1) return strlen(manufacturer);
    return -1;
}

void OfficePackage::operator()(const char* newName, const char* newMan, const int newComp, const double newPrice) {
    this->setName(newName);
    this->setManufacturer(newMan);
    this->setComponentCount(newComp);
    this->setPrice(newPrice);
}

ostream& operator<<(ostream& out, const OfficePackage& obj) {
    out << "| " << left << setw(20) << obj.name
        << " | " << setw(15) << obj.manufacturer
        << " | " << setw(15) << obj.componentCount
        << " | " << setw(10) << obj.price << " |";
    return out;
}

istream& operator>>(istream& in, OfficePackage& obj) {
    char tempName[50], tempMan[50];
    int tempComp;
    double tempPrice;

    in >> tempName >> tempMan >> tempComp >> tempPrice;
    obj(tempName, tempMan, tempComp, tempPrice);
    return in;
}