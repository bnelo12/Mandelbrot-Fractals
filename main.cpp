#include <iostream>
#include <string>
#include "Mandelbrot.h"

using namespace std;

int main(int argc, char* argv[]) {
    Mandelbrot a = Mandelbrot(-3, 1.5, -1.25, 1.25);
    a.writeToFile("fractal.ppm", 1920, 1080);
    cout << "Fractal Generation is Complete!\n";
    return 0;
}
