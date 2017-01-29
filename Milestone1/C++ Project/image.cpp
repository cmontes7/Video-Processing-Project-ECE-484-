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
    vector< vector <unsigned int>>::iterator vitr = pixels.begin();
    while (vitr != pixels.end()){
        vector <unsigned int>::iterator itr = vitr->begin();
            while (itr != vitr->end()){
                fputc(*itr,outputFile);
                itr++;
            }
            vitr++;
    }

    fclose(outputFile);
}

void Image::histogramEqualization(){

    // create histogram
    int hist[256] = {0};
    vector< vector <unsigned int>>::iterator vitr = pixels.begin();
    vector <unsigned int>::iterator itr;

    while (vitr != pixels.end()){
        itr = vitr->begin();
        while (itr != vitr->end()){
            hist[*itr]++;
            itr++;
        }
        vitr++;
    }


    // create cumulative histogram
    int cumulative[256] = {0};

    for (int i=1; i<256; i++){
        cumulative[i]=cumulative[i-1] + hist[i];
    }

    // Adjust the pixel values
    vitr = pixels.begin();
    while (vitr != pixels.end()){
        itr = vitr->begin();
            while (itr != vitr->end()){
                *itr = round(255*(cumulative[*itr])/(imageHeight*imageWidth));
                itr++;
            }
            vitr++;
    }

    // Print equalized image to file
    char filename[40] = "equalized.bmp";
    outputBM(filename);
}
