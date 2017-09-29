#ifndef IMAGE_hpp
#define IMAGE_hpp

#include "RGB.h"
#include <vector>
#include <string>

using namespace std;

class Image {
public:
   Image(int w, int h);
   int width;
   int height;
   vector<RGB> pixels;
   string createImage();
   void writeImageFile(string filename);
   void setPixel(int a, int b, RGB color);
};

#endif
