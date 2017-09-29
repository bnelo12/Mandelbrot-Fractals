#include "ComplexNumber.h"
#include "math.h"

CN CN::add(CN a, CN b) {
    return CN(a.r + b.r, a.i + b.i);
}

double CN::mag(CN a) {
    return sqrt(pow(a.r, 2) + pow(a.i, 2));
}

CN CN::square(CN a) {
    return CN(pow(a.r, 2) - pow(a.i, 2), 2*a.r*a.i);
}

CN::CN(double r, double i) {
    this->r = r;
    this->i = i;
}
