#ifndef B2_H
#define B2_H

#include <iostream>
using namespace std;

class B2 {
private:
    int b2Value;

public:
    B2(const int b2ValueInit);
    virtual ~B2();

    int getB2Value() const;

    virtual void show() const;

    friend ostream& operator<<(ostream& out, const B2& obj);
};

#endif