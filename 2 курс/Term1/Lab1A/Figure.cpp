#include "Figure.h"

Figure::Figure(const double firstValue, const double secondValue)
    : firstValue(firstValue),
    secondValue(secondValue) {
}

double Figure::calculateArea() const {
    const double PI = 3.141592653589793;

    if (isTriangle()) {
        return firstValue * secondValue / 2.0;
    }
    return PI * firstValue * firstValue;
}

bool Figure::isTriangle() const {
    return secondValue > 0.0;
}

double Figure::getFirstValue() const {
    return firstValue;
}

double Figure::getSecondValue() const {
    return secondValue;
}