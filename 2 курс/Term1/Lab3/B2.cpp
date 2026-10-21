#include "B2.h"
using namespace std;

B2::B2(const int b2ValueInit) : b2Value(b2ValueInit) {
}

B2::~B2() {
}

int B2::getB2Value() const {
    return b2Value;
}

void B2::show() const {
    cout << "B2 = " << b2Value << endl;
}

ostream& operator<<(ostream& out, const B2& obj) {
    out << "B2 = " << obj.b2Value;
    return out;
}