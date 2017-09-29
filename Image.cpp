#include "Image.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

Image::Image(int w, int h) {
    this->width = w;
    this->height = h;
    for (int i = 0; i < w*h; i++) {
      this->pixels.push_back(RGB(0,0,0)); 
    }
}

string Image::createImage() {
    string str = "P3\n";
    str += to_string(this->width) + " " + to_string(this->height) + "\n";
    str += "255\n";
    for (int i = 0; i < this->width*this->height; i++) {
        str +=  to_string(this->pixels[i].R) + " ";
        str +=  to_string(this->pixels[i].G) + " ";
        str +=  to_string(this->pixels[i].B) + " ";
        str += "\t";
        if (i % this->width == 0) str += "\n";
    }
    return str;
}

void Image::writeImageFile(string filename) {
    ofstream myfile;
    myfile.open (filename);
    myfile << this->createImage();
    myfile.close();
}

void Image::setPixel(int x, int y, RGB color) {
    this->pixels[y*this->width + x] = color;
}
