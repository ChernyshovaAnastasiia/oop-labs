#include "DOG.h"
#include <iostream>
using namespace std;

DOG::DOG() : height(0.0) {
    cout << "Конструктор класу DOG" << endl;
}

DOG::~DOG() {
    cout << "Деструктор класу DOG" << endl;
}

bool DOG::setHeight(const double heightInit) {
    if (heightInit <= 0.0) {
        return false;
    }

    height = heightInit;
    return true;
}

void DOG::show() const {
    SOBAKA::show();
    cout << "Зріст: " << height << " см" << endl;
}

void DOG::golos() const {
    if (getWeight() >= 10.0) {
        cout << "ГАВ" << endl;
    }
    else {
        cout << "гав" << endl;
    }
}
