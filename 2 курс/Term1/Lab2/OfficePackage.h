#ifndef OFFICEPACKAGE_H
#define OFFICEPACKAGE_H
#include <iostream>

class OfficePackage {
private:
    char* name;
    char* manufacturer;
    int componentCount;
    double price;

public:
    OfficePackage();
    OfficePackage(const char* nameInit, const char* manufacturerInit, const int componentCountInit, const double priceInit);
    OfficePackage(const OfficePackage& other);
    ~OfficePackage();

    void setName(const char* nameInit);
    void setManufacturer(const char* manufacturerInit);
    void setComponentCount(const int componentCountInit);
    void setPrice(const double priceInit);

    const char* getName() const;
    const char* getManufacturer() const;
    int getComponentCount() const;
    double getPrice() const;

    void show() const;

    OfficePackage& operator=(const OfficePackage& other);
    bool operator==(const OfficePackage& other) const;
    OfficePackage operator+(const double extraPrice) const;

    int operator[](const int index) const;
    void operator()(const char* newName, const char* newMan, const int newComp, const double newPrice);

    friend bool operator==(const char* searchName, const OfficePackage& obj);
    friend OfficePackage operator+(const int extraComp, const OfficePackage& obj);

    friend std::ostream& operator<<(std::ostream& out, const OfficePackage& obj);
    friend std::istream& operator>>(std::istream& in, OfficePackage& obj);
};

#endif
