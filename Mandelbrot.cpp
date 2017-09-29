#include "Mandelbrot.h"
#include "RGB.h"
#include "ComplexNumber.h"
#include <iostream>
#include "math.h"

Mandelbrot::Mandelbrot(double x0, double x1, double y0, double y1) {
    this->x0 = x0;
    this->x1 = x1;
    this->y0 = y0;
    this->y1 = y1;
    this->n_max = 50;
}

void Mandelbrot::setNMax(unsigned int new_max) {
    this->n_max = new_max;
} 

void Mandelbrot::writeToFile(string filename, unsigned int width, unsigned int height) {
    Image image = Image(width, height);
    double delta_x = (x1-x0)/width;
    double delta_y = (y1-y0)/height;
    for (double y = 0; y < height; y++) {
        for (double x = 0; x < width; x++) {
           int n = _recursePoint(CN(x0 + x*delta_x, y0 + y*delta_y));
           unsigned char intensity =  n*255/n_max;
           image.setPixel(x, y, RGB(intensity, intensity, intensity));
           if (n == -1) image.setPixel(x, y, RGB(255, 255, 255));
        }
    }
    image.writeImageFile(filename);
}

int Mandelbrot::_recursePoint(CN c) {
    int n = 0;
    CN z =CN(0, 0);
    while (true) {
        if (n > n_max) return -1;
        else if (CN::mag(z) > 2) return n;
        z = CN::add(CN::square(z), c);
        n++;
    }
}
