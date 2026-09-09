#define _CRT_SECURE_NO_WARNINGS
#include "OfficePackage.h"
#include <iostream>
#include <cstring>

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
    std::cout << name << "\t\t"
        << manufacturer << "\t\t"
        << componentCount << "\t\t"
        << price << std::endl;
}