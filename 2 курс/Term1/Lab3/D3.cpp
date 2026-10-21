#include "D3.h"
using namespace std;

D3::D3(const int b1ValueInit,
    const int d1ValueInit,
    const int b2ValueInit,
    const int d2ValueInit,
    const int d3ValueInit)
    : D2(b1ValueInit, d1ValueInit,
        b2ValueInit, d2ValueInit),
    d3Value(d3ValueInit) {
}

int D3::getD3Value() const {
    return d3Value;
}

void D3::show() const {
    cout << *this << endl;
}

ostream& operator<<(ostream& out, const D3& obj) {
    out << static_cast<const D2&>(obj)
        << ", D3 = " << obj.d3Value;

    return out;
}