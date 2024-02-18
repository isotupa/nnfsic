#include "mynn.h"

int mynn(int layers, int* l_sizes) {


	return 0;
}

double* calculate_layer_output(Layer* l, double inputs[], int size) {
	int i, j;
	double* output = malloc(sizeof(double)*size);

	for(i = 0; i < size; i++) {
		for(j = 0; j < l->n_neurons; j++){
			output[i] = sigmoid(l->weight[i]*inputs[j] + l->bias[i]);
		}
	}

	return output;
}

double sigmoid(double x) {
	return 1 / (1 + exp(x));
}
