#include "neural.h"


NeuralNetwork* neural_initialise(int* layers, size_t layers_size, double alpha) {
    if(layers_size < 3) {
        return NULL;
    }

    NeuralNetwork* res = malloc(sizeof(NeuralNetwork));
    res->layers = malloc(sizeof(size_t) * layers_size);

    for(size_t i = 0; i < layers_size; i++) {
        res->layers[i] = layers[i];
    }

    res->alpha = alpha;
    res->num_layers = layers_size;
    res->W = malloc(sizeof(Matrix*) * layers_size);

    int W_counter = 0;

    for(size_t i = 0; i < layers_size - 2; i++){
        Matrix* w = initialise_random(layers[i] + 1, layers[i+1] + 1);
        Matrix* sqrt_layer = linear_sqrt(w);
        res->W[W_counter++] = linear_div(w, sqrt_layer);
    }

    Matrix* w = initialise_random(layers[layers_size - 2] + 1, layers[layers_size - 1]);
    Matrix* sqrt_layer = linear_sqrt(w);
    res->W[W_counter++] = linear_div(w, sqrt_layer);

    return res;
}


void neural_free(NeuralNetwork* nn, int num_layers) {
    free(nn->layers);
    for (int i = 0; i < num_layers - 1; i++) {
        free_matrix(nn->W[i]);
        free(nn->W[i]);
    }
    free(nn->W);
}

void neural_print_info(NeuralNetwork* nn, int show_layer_sizes, int show_num_layers, int show_alpha, int show_matrices) {

    if(show_num_layers == TRUE) {
        printf("Number of layers=\n\t%zu\n", nn->num_layers);
    }

    if(show_alpha == TRUE) {
        printf("Alpha value=\n\t%f\n", nn->alpha);
    }

    if(show_layer_sizes == TRUE) {
        printf("Layers=\n");
        for(int i = 0; i < nn->num_layers; i++) printf("%d ", nn->layers[i]);
    }

    if(show_matrices == TRUE) {
        printf("Matrices=\n");
        for(int i = 0; i < nn->num_layers; i++) {
            printf("Layer %d\n", i);
            print_matrix(nn->W[i]);
        }
    }
}