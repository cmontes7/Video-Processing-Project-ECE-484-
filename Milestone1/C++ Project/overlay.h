#ifndef OVERLAY_H_INCLUDED
#define OVERLAY_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>

#include "image.h"

using namespace std;

class Overlay{
    private:
		vector< vector <unsigned int> > pixelsOverlaid;

    public:
		bool twoImageSameDimension(Image background, Image foreground);
		void setPixelsOverlaid(Image background);
		void overlayImage(Image background, Image foreground);
};

#endif // OVERLAY_H_INCLUDED