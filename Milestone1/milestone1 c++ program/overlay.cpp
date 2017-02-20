#include "overlay.h"

bool Image::twoImageSameDimension(Image background, Image foreground){
	if(background.getImageWidth() == foreground.getImageWidth() && background.getImageHeight() == foreground.getImageHeight())
		return true;
	else
		return false;
}

void Image::setPixelsOverlaid(Image background){
	vector<unsigned int> row; // vector that will be filled with row pixels
    int cnt = 0;              // count for knowing when we have a complete row
    int r = 0;

	int size = background.getBmpData().size();
	int imageWidth = background.getImageWidth();
	vector< unsigned int> bmpData = background.getBmpData();

    // read only the pixel values (starting at the offset
    //cout << "\nOverlay Function: sizeof(bmpData) = " <<  background.getBmpData().size() << endl;
    for  (int i=background.getOffset() ; i < size +1; i++){
        if (cnt > imageWidth - 1 ){
            pixelsOverlaid.push_back(row);
            row.clear();
            cnt=0;
            r++;
        }
        row.push_back(bmpData[i]);
        cnt++;
    }
}
void Image::overlayImage(Image foreground){

    ///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // create overlay pixels
	vector< vector <unsigned int> > pixelsB = background.getPixels();
	vector< vector <unsigned int> > pixelsF = foreground.getPixels();

    vector< vector <unsigned int> >::iterator vitrB = pixelsB.begin();
	vector< vector <unsigned int> >::iterator vitrF = pixelsF.begin();
	vector< vector <unsigned int> >::iterator vitrO = pixelsOverlaid.begin();

    vector <unsigned int>::iterator itrB;
	vector <unsigned int>::iterator itrF;
	vector <unsigned int>::iterator itrO;

    while (vitrO != pixelsOverlaid.end()){
        itrB = vitrB->begin();
		itrF = vitrF->begin();
		itrO = vitrO->begin();
        while (itrO != vitrO->end()){
			if(*itrF == 0){
				*itrO = 255;
			}

			//printf("value at pointer: %d \n", *itrO);
            itrB++;
			itrF++;
			itrO++;
        }
        vitrB++;
		vitrF++;
		vitrO++;
    }

	// printf("finished the overlayImage function \n");
    // Print overlaid image to file
    char filename[40] = "overlaid.bmp";
    background.outputBM(filename, pixelsOverlaid);
}
