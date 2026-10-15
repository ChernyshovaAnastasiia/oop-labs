#ifndef FIGURE_H
#define FIGURE_H

class Figure {
private:
    double firstValue;
    double secondValue;

public:
    Figure(const double firstValue = 0.0,
        const double secondValue = 0.0);

    double calculateArea() const;
    bool isTriangle() const;
    double getFirstValue() const;
    double getSecondValue() const;
};

#endif
