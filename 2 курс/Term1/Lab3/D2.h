#ifndef D2_H
#define D2_H

#include <iostream>
#include "D1.h"
#include "B2.h"
using namespace std;

class D2 : private D1, private B2 {
private:
    int d2Value;

public:
    D2(const int b1ValueInit,
        const int d1ValueInit,
        const int b2ValueInit,
        const int d2ValueInit);

    int getD2Value() const;

    void show() const override;

    friend ostream& operator<<(ostream& out, const D2& obj);
};

#endif