#ifndef OFFICEPACKAGEFILE_H
#define OFFICEPACKAGEFILE_H

#include <iostream>
#include "OfficePackage.h"
using namespace std;

class OfficePackageFile {
private:
    static void writeRecord(ostream& out, const OfficePackage& package);
    static OfficePackage readRecord(istream& in);

public:
    static void saveOne(const OfficePackage& package, const char* fileName);
    static OfficePackage loadOne(const char* fileName, const int number);

    static void saveAll(const OfficePackage* packages, const int count, const char* fileName);
    static OfficePackage* loadAll(const char* fileName, int& count);
};

#endif