#ifndef SPANIEL_H
#define SPANIEL_H
#include "SOBAKA.h"
#include <string>
using namespace std;

class SPANIEL : public SOBAKA {
private:
    string color;

public:
    SPANIEL();
    ~SPANIEL();

    bool setColor(const string& colorInit);
    void show() const;
    void golos() const;
};

#endif