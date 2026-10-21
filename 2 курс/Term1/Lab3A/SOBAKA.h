#ifndef SOBAKA_H
#define SOBAKA_H

class SOBAKA {
private:
    double weight;
    int age;

public:
    SOBAKA();
    ~SOBAKA();

    bool setData(const double weightInit, const int ageInit);
    double getWeight() const;
    int getAge() const;

    void show() const;
    void golos() const;
};

#endif