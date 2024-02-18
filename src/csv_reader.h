#ifndef CSV_READER__
#define CSV_READER__
#include <stdio.h>
#include <stdlib.h>

typedef struct Image {
	int label; // Number from 0-9
	int image[28][28]; // 28x28 image of numbers between 0-255
} Image;

Image* csv_reader(char * label_dir, char * image_dir);

#endif
