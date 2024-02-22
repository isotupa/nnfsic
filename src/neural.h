#include "linear_ops/linear.h"

typedef struct NeuralNetwork
{
    double alpha;
    int* layers;
    Matrix* W;
} NeuralNetwork;

NeuralNetwork* initialise(int* layers, double alpha);
