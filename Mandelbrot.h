#include "ComplexNumber.h"
#include "Image.h"

#ifndef MANDELBROT_H
#define MANDELBROT_H

class Mandelbrot {
    public:
    Mandelbrot(double x0, double x1, double y0, double y1);
    double x0, x1, y0, y1;
    unsigned int n_max;
    void setNMax(unsigned int new_max);
    void writeToFile(string filename, unsigned int width, unsigned int height);
    private:
    int _recursePoint(CN number); 
};

#endif
