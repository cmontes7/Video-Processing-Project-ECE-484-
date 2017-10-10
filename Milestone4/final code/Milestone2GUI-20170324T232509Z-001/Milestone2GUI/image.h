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
        int maxLevelOrigImage;
        int minLevelOrigImage;
        //int hist[256]; // original histogram
         vector< unsigned int> bmpData;         // Contains all the bytes extracted from the bitmap
         vector< vector <unsigned int> > pixels; // pixel bytes
         int header[54];                        // Header bytes
         vector< vector <unsigned int> > pixelsOverlaid;
         vector< vector <unsigned int> > processed;

    public:
        bool twoImageSameDimension(Image img);
        void outputBM(char  filename[], vector< vector <unsigned int> > pixelsMulitpleImages);

         int getImageWidth();
         int getImageHeight();
         int getImageBits();
         int getOffset();
         int getMaxLevel();
         int getMinLevel();

         vector< unsigned int> getBmpData();
         vector<vector <unsigned int> > getPixels();

         void readBM (char  filename[]);
         void outputBM(char  filename[]);
         void calculateMinMax();
         void histogramEqualization();
         void contrast(int change);
         void overlay(char  filename[]);
};

#endif // IMAGE_H_INCLUDED
