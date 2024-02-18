#include <stdio.h>
#include "csv_reader.h"

void img_printer(Image img) {
	const char* pixels = " ·!%";
	int i, j;

	for(i = 0; i < 28; i++) {
		for(j = 0; j < 28; j++) {
			int pixel = img.image[i][j];
			if(pixel == 0) printf("%c", pixels[0]);
			else if(pixel > 0 && pixel <= 100) printf("%c", pixels[1]);
			else if(pixel > 100 && pixel < 255) printf("%c", pixels[2]);
			else printf("%c", pixels[4]);
		}
		printf("\n");
	}

	printf("Expected label: %d\n", img.label);
}
