#ifndef B1_H
#define B1_H

#include <iostream>
using namespace std;

class B1 {
private:
    int b1Value;

public:
    B1(const int b1ValueInit);
    virtual ~B1();

    int getB1Value() const;

    virtual void show() const;

    friend ostream& operator<<(ostream& out, const B1& obj);
};

#endif