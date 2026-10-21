#include "SPANIEL.h"
#include <iostream>
using namespace std;

SPANIEL::SPANIEL() : color("не задано") {
    cout << "Конструктор класу SPANIEL" << endl;
}

SPANIEL::~SPANIEL() {
    cout << "Деструктор класу SPANIEL" << endl;
}

bool SPANIEL::setColor(const string& colorInit) {
    if (colorInit.empty()) {
        return false;
    }

    color = colorInit;
    return true;
}

void SPANIEL::show() const {
    SOBAKA::show();
    cout << "Колір: " << color << endl;
}

void SPANIEL::golos() const {
    if (getWeight() >= 10.0) {
        cout << "ГАВ" << endl;
    }
    else {
        cout << "гав" << endl;
    }
}