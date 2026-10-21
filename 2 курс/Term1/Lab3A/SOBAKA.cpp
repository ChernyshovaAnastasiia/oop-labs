#include "SOBAKA.h"
#include <iostream>
using namespace std;

SOBAKA::SOBAKA() : weight(0.0), age(0) {
    cout << "Конструктор класу SOBAKA" << endl;
}

SOBAKA::~SOBAKA() {
    cout << "Деструктор класу SOBAKA" << endl;
}

bool SOBAKA::setData(const double weightInit,
    const int ageInit) {
    if (weightInit <= 0.0 || ageInit < 0) {
        return false;
    }

    weight = weightInit;
    age = ageInit;
    return true;
}

double SOBAKA::getWeight() const {
    return weight;
}

int SOBAKA::getAge() const {
    return age;
}

void SOBAKA::show() const {
    cout << "Вага: " << weight
        << " кг, вік (роки): " << age << endl;
}

void SOBAKA::golos() const {
    if (weight >= 10.0) {
        cout << "ГАВ" << endl;
    }
    else {
        cout << "гав" << endl;
    }
}