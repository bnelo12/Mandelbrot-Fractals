#ifndef COMPLEX_NUMBER_H
#define COMPLEX_NUMBER_H

class CN {
public:
    CN(double r, double i);
    static CN add(CN a, CN b);
    static double mag(CN a);
    static CN square(CN a);
    double r;
    double i;
};

#endif
