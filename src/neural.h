#include "linear_ops/linear.h"

typedef struct NeuralNetwork
{
    double alpha;
    size_t num_layers;
    int* layers;
    Matrix** W;
} NeuralNetwork;

NeuralNetwork* neural_initialise(int* layers, size_t layers_size, double alpha);

void neural_free(NeuralNetwork* nn, int num_layers);

void neural_print_info(NeuralNetwork* nn, int show_layer_sizes, int show_num_layers, int show_alpha, int show_matrices);