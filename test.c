#include "src/neural.h"
#include "src/linear_ops/global_params.h"
#include <stdio.h>
#include <time.h>

int main() {
    srand ( time ( NULL));
    int layers[3] = {3,2,1};
    size_t layers_size = 3;
    NeuralNetwork* nn = neural_initialise(layers, layers_size, 0.5);

    neural_print_info(nn, TRUE, TRUE, TRUE, TRUE);

    // for(int i = 0; i < layers_size; i++) printf("%d ", nn->layers[i]);

    // printf("\n%zu\n", nn->num_layers);
    // printf("%f\n", nn->alpha);
    // print_matrix(nn->W[0]);
    // print_matrix(nn->W[1]);

    // for(int i = 0; i < layers_size; i++) {
    //     print_matrix(nn->W[i]);
    // }

    neural_free(nn, layers_size);
}