#ifndef OFFICEPACKAGE_H
#define OFFICEPACKAGE_H

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
};

#endif