#include "B1.h"
using namespace std;

B1::B1(const int b1ValueInit) : b1Value(b1ValueInit) {
}

B1::~B1() {
}

int B1::getB1Value() const {
    return b1Value;
}

void B1::show() const {
    cout << "B1 = " << b1Value << endl;
}

ostream& operator<<(ostream& out, const B1& obj) {
    out << "B1 = " << obj.b1Value;
    return out;
}