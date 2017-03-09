#include "image.h"

void Image::readBM (char  filename[]){
    int byteValue;
    int index = 0;
    int fileSize = 0;
    FILE *inputFile;

    inputFile = fopen(filename, "rb"); //rb - read file as binary

    // check for file error
    if(inputFile == NULL) {
        fputs ("File error \n",stderr);
        exit (1);
    }

    // Finds the size of the bitmap
    fseek( inputFile, 0, SEEK_END );
    fileSize = ftell(inputFile);
    rewind(inputFile);
    printf("fileSize: %d \n", fileSize);

    //unsigned int bmpData[fileSize];

    // Loads in entire bitmap
    while(byteValue != EOF) {
        byteValue = fgetc(inputFile);
        bmpData.push_back(byteValue);
        //printf("byteValue: %d \n", byteValue);
        index++;
    }

    fclose(inputFile);

    // Sanity check
    imageWidth = bmpData[20-1] *256 + bmpData[19-1];
    imageHeight = bmpData[24-1] *256 + bmpData[23-1];
    imageBits = bmpData[29-1];
    offset =  bmpData[11]*256 + bmpData[10];

    printf("image width: %d \n", imageWidth);
    printf("image height: %d \n", imageHeight);
    printf("image bits: %d \n", imageBits);
    printf("characters in image: %d \n", index-1);
    printf("offset: %d \n", offset);

    vector<unsigned int> row; // vector that will be filled with row pixels
    int cnt = 0;              // count for knowing when we have a complete row
    int r = 0;

    // read only the pixel values (starting at the offset
    cout << "\nsizeof(bmpData) = " <<  bmpData.size() << endl;
    for  (int i=offset ; i < bmpData.size() +1; i++){
        if (cnt > imageWidth - 1 ){
            pixels.push_back(row);
            row.clear();
            cnt=0;
            r++;
        }
        row.push_back(bmpData[i]);
        cnt++;
    }

    processed = pixels;
};

void Image::outputBM (char  filename[]){

    FILE *outputFile;

    // output image
    outputFile = fopen(filename,"wb");

    // store bmp header first
    for (int i=0; i<offset; i++){
        //  bmp header
        if (i<54){
            fputc((bmpData[i]),outputFile);
        }
        // not sure what is here
        else
            fputc((bmpData[i]),outputFile);
    }
    // Store pixels
    vector< vector <unsigned int> >::iterator vitr = processed.begin();
    while (vitr != processed.end()){
        vector <unsigned int>::iterator itr = vitr->begin();
            while (itr != vitr->end()){
                fputc(*itr,outputFile);
                itr++;
            }
            vitr++;
    }

    fclose(outputFile);
}

int Image::getImageWidth(){
    //printf("Image Width from get: %d \n", imageWidth);
    return imageWidth;
}

int Image::getImageHeight(){
    //printf("Image Height from get: %d \n", imageHeight);
    return imageHeight;
}

int Image::getImageBits(){
    //printf("Image Bits from get: %d \n", imageBits);
    return imageBits;
}

int Image::getOffset(){
    //printf("Image offset from get: %d \n", offset);
    return offset;
}

int Image::getMinLevel(){
    printf("Image min level: %d \n", minLevelOrigImage);
    return minLevelOrigImage;
}

int Image::getMaxLevel(){
    printf("Image max level: %d \n", maxLevelOrigImage);
    return maxLevelOrigImage;
}

vector< unsigned int> Image::getBmpData(){
    //printf("Image bmpData from get: %lu \n", bmpData.size());
    return bmpData;
}

vector<vector <unsigned int> > Image::getPixels(){
    //printf("Image pixels from get: %lu \n", pixels.size());
    return pixels;
}

void Image::calculateMinMax(){
    // create histogram
    int hist[256] = {0};
    vector< vector <unsigned int> >::iterator vitr = pixels.begin();
    vector <unsigned int>::iterator itr;

    while (vitr != pixels.end()){
        itr = vitr->begin();
        while (itr != vitr->end()){
            hist[*itr]++;
            itr++;
        }
        vitr++;
    }

    maxLevelOrigImage = 255;
    minLevelOrigImage = 0;

    for(int i=0; hist[i] == 0; i++) {
        minLevelOrigImage = i;
    }
    printf("Value at minLevelOrigImage in ICMMF: %d \n", minLevelOrigImage);
    for(int i=255; hist[i] == 0; i--) {
        maxLevelOrigImage = i;
    }
    printf("Value at maxLevelOrigImage in ICMMF: %d \n", maxLevelOrigImage);
}

void Image::histogramEqualization(){

    ofstream f;
    f.open("Original_hist.txt");

    // create histogram
    int hist[256] = {0};
    vector< vector <unsigned int> >::iterator vitr = pixels.begin();
    vector <unsigned int>::iterator itr;
    vector< vector <unsigned int> >::iterator vitr1 = processed.begin();
    vector <unsigned int>::iterator itr1;

    while (vitr != pixels.end()){
        itr = vitr->begin();
        while (itr != vitr->end()){
            hist[*itr]++;
            itr++;
        }
        vitr++;
    }

    for(int i=0; i<255; i++){
        f << hist[i] << endl;
    }

    f.close();


    // create cumulative histogram
    int cumulative[256] = {0};

    for (int i=1; i<256; i++){
        cumulative[i]=cumulative[i-1] + hist[i];
    }

    // Adjust the pixel values
    vitr = pixels.begin();
    vitr1 = processed.begin();

    while (vitr != pixels.end()){
        itr = vitr->begin();
        itr1 = vitr1->begin();
            while (itr != vitr->end()){
                *itr1 = round(255*(cumulative[*itr])/(imageHeight*imageWidth));
                itr++;
                itr1++;
            }
            vitr++;
            vitr1++;
    }

    // Print equalized image to file
    char filename[40] = "out2.bmp";
    outputBM(filename);

    f.open("Equalized_hist.txt");

     for(int i=0; i<256; i++){
        hist[i] =0;
    }

    vitr = pixels.begin();

    while (vitr != pixels.end()){
        itr = vitr->begin();
        while (itr != vitr->end()){
            hist[*itr]++;
            itr++;
        }
        vitr++;
    }

    for(int i=0; i<255; i++){
        f << hist[i] << endl;
    }

    f.close();
}

void Image::contrast(int change){
    /*
    ofstream f;
    f.open("Original_hist.txt");

    // create histogram
    int hist[256] = {0};
    vector< vector <unsigned int> >::iterator vitr = pixels.begin();
    vector <unsigned int>::iterator itr;

    while (vitr != pixels.end()){
        itr = vitr->begin();
        while (itr != vitr->end()){
            hist[*itr]++;
            itr++;
        }
        vitr++;
    }

    for(int i=0; i<255; i++){
        f << hist[i] << endl;
    }

    f.close();

    int maxLevelOrigImage = 255;
    int minLevelOrigImage = 0;

    for(int i=0; hist[i] == 0; i++) {
        minLevelOrigImage = i;
    }
    printf("Value at minLevelOrigImage: %d \n", minLevelOrigImage);
    for(int i=255; hist[i] == 0; i--) {
        maxLevelOrigImage = i;
    }
    printf("Value at maxLevelOrigImage: %d \n", maxLevelOrigImage);
    */
    calculateMinMax();
    vector< vector <unsigned int> >::iterator vitr = pixels.begin();
    vector <unsigned int>::iterator itr;
    // Adjust the pixel values
    vitr = pixels.begin();
    while (vitr != pixels.end()){
        itr = vitr->begin();
        while (itr != vitr->end()){
            //printf("Before Value at *itr: %d \n", *itr);
            *itr = round(change + (2*change + maxLevelOrigImage - minLevelOrigImage) * (*itr - minLevelOrigImage)/(maxLevelOrigImage - minLevelOrigImage));
            //printf("After Value at *itr: %d \n", *itr);
                itr++;
        }
        vitr++;
    }

    // Print equalized image to file
    char filename[40] = "out3.bmp";
    outputBM(filename);
}

bool Image::twoImageSameDimension(Image compare){
    if( imageWidth == compare.getImageWidth() && imageHeight== compare.getImageHeight())
        return true;
    else
        return false;
}

void Image::overlay(char filename[]){
    Image foreground;
    foreground.readBM(filename);

    //check to see if the images are the same size
    if ( twoImageSameDimension(foreground) == false)
        exit(1);

    vector< vector <unsigned int> > foreground_pixels = foreground.getPixels();
    vector< vector <unsigned int> >::iterator vitrB = pixels.begin();
    vector< vector <unsigned int> >::iterator vitrC = processed.begin();
    vector< vector <unsigned int> >::iterator vitrF = foreground_pixels.begin();

    vector <unsigned int>::iterator itrB;
    vector <unsigned int>::iterator itrC;
    vector <unsigned int>::iterator itrF;

    // Adjust the pixel values
    while (vitrB != pixels.end()){
        itrB = vitrB->begin();
        itrC = vitrC->begin();
        itrF = vitrF->begin();
        while (itrB != vitrB->end()){

            if(*itrF == 0){
                *itrC = 255;
            }
            else{
                *itrC = *itrB;
            }
            itrB++;
            itrC++;
            itrF++;
        }
        vitrB++;
        vitrC++;
        vitrF++;
    }
    printf("Image Overlayed \n");
    // Print equalized image to file
    char fn[40] = "out1.bmp";
    outputBM(fn);

}

