#include "D1.h"
using namespace std;

D1::D1(const int b1ValueInit, const int d1ValueInit)
    : B1(b1ValueInit), d1Value(d1ValueInit) {
}

int D1::getD1Value() const {
    return d1Value;
}

void D1::show() const {
    cout << "B1 = " << getB1Value()
        << ", D1 = " << d1Value << endl;
}

ostream& operator<<(ostream& out, const D1& obj) {
    out << "B1 = " << obj.getB1Value()
        << ", D1 = " << obj.d1Value;

    return out;
}