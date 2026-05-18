#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <iomanip>
#include <cstring>
#include <ctime>
#include <cstdio>
using namespace std;

// #define DEBUG  

struct OfficePackage {
    char name[50];
    char producer[50];
    int components;
    double price;
};

#ifdef DEBUG
#define START_DEBUG() { \
        time_t now = time(0); \
        char buf[26]; \
        ctime_s(buf, sizeof(buf), &now); \
        cout << "[DEBUG] Початок: " << buf; \
    }
#define END_DEBUG() { \
        cout << "[DEBUG] Файл: " << __FILE__ << " | Функція: " << __FUNCTION__ << endl; \
    }
#else
#define START_DEBUG()
#define END_DEBUG()
#endif

const char FILENAME[] = "packages.dat";

void createFileFromScreen();
void createFileRandom();
void addRecordToBeginning();
void addRecordToEnd();
void printRecordByNumber();
void printAllRecords();
void modifyRecordField();


void printHeader();
void printRecord(const OfficePackage& pkg);

#endif