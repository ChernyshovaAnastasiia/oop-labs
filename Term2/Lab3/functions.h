#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
using namespace std;

#define DEBUG  
#define PRINT_TYPE 1

struct OfficePackage {
    string name;
    string producer;
    int components;
    double price;
};

const int MAX_SIZE = 100;

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

void inputFromScreen(OfficePackage data[], int& count);
void inputRandom(OfficePackage data[], int& count);
void sortData(OfficePackage data[], int count);
void printData(OfficePackage data[], int count);

#endif