#include <stdio.h>
#include <stdlib.h>
#include "csv_reader.h"
#include "img_printer.h"
#include "mynn.h"

int main() {
	// Image* img = csv_reader("./datasets/t10k-labels-idx1-ubyte", "datasets/t10k-images-idx3-ubyte");

	// int i;
	// for(i = 0; i < 100; i++) {
	// 	img_printer(img[i]);
	// }
	//
	Layer l1 = {2, {0, 1}, {0, 0}};
	Layer l2 = {2, {0, 1}, {0, 0}};
	Layer l3 = {1, {1}, {0}};

	double inputs[] = {2,3};
	double* res = calculate_layer_output(&l1,inputs, 2);
	double* res2 = calculate_layer_output(&l3, res, 1);

	printf("%f\n", res2[0]);
	
	

	return 0;
}
