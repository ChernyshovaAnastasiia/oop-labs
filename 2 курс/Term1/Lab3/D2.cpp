#include "D2.h"
using namespace std;

D2::D2(const int b1ValueInit,
    const int d1ValueInit,
    const int b2ValueInit,
    const int d2ValueInit)
    : D1(b1ValueInit, d1ValueInit),
    B2(b2ValueInit),
    d2Value(d2ValueInit) {
}

int D2::getD2Value() const {
    return d2Value;
}

void D2::show() const {
    cout << *this << endl;
}

ostream& operator<<(ostream& out, const D2& obj) {
    out << static_cast<const D1&>(obj)
        << ", " << static_cast<const B2&>(obj)
        << ", D2 = " << obj.d2Value;

    return out;
}