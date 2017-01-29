#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include "image.h"

using namespace std;

vector< vector <unsigned int>> readBM (char  filename[]);

int main() {
    // Variable declarations
	char filename[40];
    Image original;

	printf("Enter BMP filename: ");
	cin >> filename;

    original.readBM(filename);
    original.histogramEqualization();

	return 0;
}
