#ifndef D1_H
#define D1_H

#include <iostream>
#include "B1.h"
using namespace std;

class D1 : public B1 {
private:
    int d1Value;

public:
    D1(const int b1ValueInit, const int d1ValueInit);

    int getD1Value() const;

    void show() const override;

    friend ostream& operator<<(ostream& out, const D1& obj);
};

#endif