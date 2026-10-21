#ifndef DOG_H
#define DOG_H
#include "SOBAKA.h"

class DOG : public SOBAKA {
private:
    double height;

public:
    DOG();
    ~DOG();

    bool setHeight(const double heightInit);
    void show() const;
    void golos() const;
};

#endif