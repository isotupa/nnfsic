#include "linear_ops/linear.h"

typedef struct NeuralNetwork
{
    double alpha;
    size_t num_layers;
    int* layers;
    Matrix** W;
} NeuralNetwork;

NeuralNetwork* initialize_neural_network(int* layers, size_t num_layers, double alpha);
void free_neural_network(NeuralNetwork* nn);
// void neural_print_info(NeuralNetwork* nn, int show_layer_sizes, int show_num_layers, int show_alpha, int show_matrices);
void fit_partial(NeuralNetwork* nn, Matrix* x, Matrix* y);
void fit(NeuralNetwork* nn, Matrix* X, Matrix* y, int epochs, int display_update);
Matrix* predict(NeuralNetwork* nn, Matrix* X, int add_bias);
double calculate_loss(NeuralNetwork* nn, Matrix* X, Matrix* targets);