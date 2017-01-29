#ifndef IMAGE_H_INCLUDED
#define IMAGE_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

class Image{
    private:
        int imageWidth ;
        int imageHeight ;
        int imageBits ;
        int offset ;
         vector< unsigned int> bmpData;         // Contains all the bytes extracted from the bitmap
         vector< vector <unsigned int>> pixels; // pixel bytes
         int header[54];                        // Header bytes

    public:
         void readBM (char  filename[]);
         void outputBM(char  filename[]);
         void histogramEqualization();
};

#endif // IMAGE_H_INCLUDED
