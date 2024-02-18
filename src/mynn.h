#include <stdio.h>
#include <math.h>
#include "globals.h"

typedef struct Layer{
	int n_neurons;
	double weight[MAX_SIZE];
	double bias[MAX_SIZE];
} Layer;

typedef struct NN{
	Layer* layers;
} NN;

int mynn(int layers, int* l_sizes);
double sigmoid(double);
double* calculate_layer_output(Layer* l, double inputs[], int size);
