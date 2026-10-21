#ifndef D3_H
#define D3_H

#include <iostream>
#include "D2.h"
using namespace std;

class D3 : public D2 {
private:
    int d3Value;

public:
    D3(const int b1ValueInit,
        const int d1ValueInit,
        const int b2ValueInit,
        const int d2ValueInit,
        const int d3ValueInit);

    int getD3Value() const;

    void show() const override;

    friend ostream& operator<<(ostream& out, const D3& obj);
};

#endif