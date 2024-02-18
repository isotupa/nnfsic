#include <fcntl.h> 
#include <stdio.h> 
#include <string.h>
#include <unistd.h> 
#include <libkern/OSByteOrder.h>
#include "csv_reader.h"

Image* csv_reader(char * label_dir, char * image_dir) {
	Image* res;

	printf("Processing labels...\n");
	int fd = open(label_dir, O_RDONLY);
	if(fd == -1) printf("Error reading labels!\n");

	int input;
	read(fd, &input, sizeof(int));
	read(fd, &input, sizeof(int));

	int size = OSSwapInt32(input);

	int* labels = malloc(size*sizeof(int));
	res = malloc(size*sizeof(Image));

	int i = 0;
	unsigned char c;
	for(i = 0; read(fd, &c, 1) > 0; i++) {
		labels[i] = c;
		res[i].label = c;
	}

	close(fd);
	printf("Finished processing labels...\n");
	printf("Processing images...\n");

	fd = open(image_dir, O_RDONLY);
	if(fd == -1) printf("Error reading images!\n");

	read(fd, &input, sizeof(int));
	read(fd, &input, sizeof(int));
	read(fd, &input, sizeof(int));
	read(fd, &input, sizeof(int));

	int current[28][28];

	int j, k;
	for(i = 0; i < size; i++) {
		for(j = 0; j < 28; j++) {
			for(k = 0; k < 28; k++) {
				read(fd, &(res[i].image[j][k]), 1);
			}
		}
	}

	close(fd);
	printf("Finished processing images...\n");

	return res;
}
