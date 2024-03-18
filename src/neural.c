#include "neural.h"


// NeuralNetwork* neural_initialise(int* layers, size_t layers_size, double alpha) {
//     if(layers_size < 3) {
//         return NULL;
//     }

//     NeuralNetwork* res = malloc(sizeof(NeuralNetwork));
//     res->layers = malloc(sizeof(size_t) * layers_size);

//     for(size_t i = 0; i < layers_size; i++) {
//         res->layers[i] = layers[i];
//     }

//     res->alpha = alpha;
//     res->num_layers = layers_size;
//     res->W = malloc(sizeof(Matrix*) * layers_size);

//     int W_counter = 0;

//     for(size_t i = 0; i < layers_size - 2; i++){
//         Matrix* w = initialise_random(layers[i] + 1, layers[i+1] + 1);
//         Matrix* sqrt_layer = linear_sqrt(w);
//         res->W[W_counter++] = linear_div(w, sqrt_layer);
//     }

//     Matrix* w = initialise_random(layers[layers_size - 2] + 1, layers[layers_size - 1]);
//     Matrix* sqrt_layer = linear_sqrt(w);
//     res->W[W_counter++] = linear_div(w, sqrt_layer);

//     return res;
// }


// void neural_free(NeuralNetwork* nn, int num_layers) {
//     free(nn->layers);
//     for (int i = 0; i < num_layers - 1; i++) {
//         free_matrix(nn->W[i]);
//         free(nn->W[i]);
//     }
//     free(nn->W);
// }

// void neural_print_info(NeuralNetwork* nn, int show_layer_sizes, int show_num_layers, int show_alpha, int show_matrices) {

//     if(show_num_layers == TRUE) {
//         printf("Number of layers=\n\t%zu\n", nn->num_layers);
//     }

//     if(show_alpha == TRUE) {
//         printf("Alpha value=\n\t%f\n", nn->alpha);
//     }

//     if(show_layer_sizes == TRUE) {
//         printf("Layers=\n");
//         for(int i = 0; i < nn->num_layers; i++) printf("%d ", nn->layers[i]);
//     }

//     if(show_matrices == TRUE) {
//         printf("Matrices=\n");
//         for(int i = 0; i < nn->num_layers; i++) {
//             printf("Layer %d\n", i);
//             print_matrix(nn->W[i]);
//         }
//     }
// }



// void fit(NeuralNetwork* nn, double* X, int* y, int size, int epochs, int display_update) {
//     // X = np.c_[X, np.ones((X.shape[0]))]

//     for(size_t epoch = 0; epoch < epochs; epoch++) {
//         for(size_t j = 0; j < size; j++) {
//             fit_partial(X[j], y[j]);
//         }

//         if(epoch == 0 || ((epoch + 1) % display_update == 0)) {
//             int loss = calculate_loss(X, y);
//             printf("[INFO] epoch=%d, loss=%.7f\n", epoch + 1, loss);
//         }
//     }
// }

// void fit_partial(NeuralNetwork* nn, double* x, int x_rows, double* y, int y_rows) {
//     Matrix** A = copy_matrix(x, 2, y_rows);
//     size_t A_index = 0;

//     for(size_t layer = 0; layer < nn->W[0]->rows; layer++) {
//         Matrix* net = linear_dot(A[layer], nn->W[layer]);
//         Matrix* out = linear_sigmoid(net);
//         A[A_index++] = out;
//     }

//     Matrix* error = linear_sub(A[A_index - 1], y);

//     Matrix** D = linear_dot(A[A_index - 1], linear_sigmoid_deriv(A[A_index - 1]));
//     size_t D_index = 0;

//     for(size_t layer = A_index - 2; layer > 0; layer--) {
//         Matrix* delta = linear_dot(D[A_index - 1], linear_sigmoid_deriv(A[layer]));
//         D[D_index++] = linear_dot(delta, linear_sigmoid_deriv(A[layer]));
//     }

//     // reverse deltas

//     for(size_t layer = 0; layer < A_index; layer++) {
//         Matrix* product = 
//         nn->W[layer] = linear_add(nn->W[layer], )
//     }



// }

NeuralNetwork* initialize_neural_network(int* layers, size_t num_layers, double alpha) {
    NeuralNetwork* nn = (NeuralNetwork*)malloc(sizeof(NeuralNetwork));
    nn->alpha = alpha;
    nn->num_layers = num_layers;
    nn->layers = layers;

    nn->W = (Matrix**)malloc((num_layers - 1) * sizeof(Matrix*));

    for (size_t i = 0; i < num_layers - 1; ++i) {
        nn->W[i] = initialise_random(layers[i] + 1, layers[i + 1] + 1);
    }

    return nn;
}

void free_neural_network(NeuralNetwork* nn) {
    for (size_t i = 0; i < nn->num_layers - 1; ++i) {
        free_matrix(nn->W[i]);
    }
    free(nn->W);
    free(nn->layers);
    free(nn);
}

void fit(NeuralNetwork* nn, Matrix* X, Matrix* y, int epochs, int display_update) {
    for (int epoch = 0; epoch < epochs; ++epoch) {
        for (int i = 0; i < X->rows; ++i) {
            fit_partial(nn, X, y);
        }

        if (epoch == 0 || (epoch + 1) % display_update == 0) {
            double loss = calculate_loss(nn, X, y);
            printf("[INFO] epoch=%d, loss=%.7f\n", epoch + 1, loss);
        }
    }
}

void fit_partial(NeuralNetwork* nn, Matrix* x, Matrix* y) {
    // Construct list of output activations for each layer
    Matrix** A = (Matrix**)malloc(nn->num_layers * sizeof(Matrix*));
    A[0] = copy_matrix(x->data[0], x->rows, x->cols);  // First activation is the input feature vector

    // Feedforward
    for (size_t layer = 0; layer < nn->num_layers - 1; ++layer) {
        Matrix* net = linear_dot(A[layer], nn->W[layer]);  // Net input
        Matrix* out = linear_sigmoid(net);               // Net output

        free_matrix(net);
        A[layer + 1] = out;  // Add net output to the list of activations
    }

    // Backpropagation
    Matrix* error = linear_sub(A[nn->num_layers - 1], y);  // Prediction error

    // Delta for the output layer
    Matrix* sigmoid_deriv_output = linear_sigmoid_deriv(A[nn->num_layers - 1]);
    Matrix* D_output = linear_mul_elementwise(error, sigmoid_deriv_output);
    free_matrix(sigmoid_deriv_output);

    // Build list of deltas
    Matrix** D = (Matrix**)malloc(nn->num_layers * sizeof(Matrix*));
    D[nn->num_layers - 1] = D_output;

    // Backpropagate deltas through hidden layers
    for (int layer = nn->num_layers - 2; layer >= 1; --layer) {
        Matrix* transpose_W = linear_transpose(nn->W[layer]);
        Matrix* delta_hidden = linear_dot(D[layer + 1], transpose_W);
        free_matrix(transpose_W);

        Matrix* sigmoid_deriv_hidden = linear_sigmoid_deriv(A[layer]);
        Matrix* delta_hidden_scaled = linear_mul_elementwise(delta_hidden, sigmoid_deriv_hidden);
        free_matrix(delta_hidden);
        free_matrix(sigmoid_deriv_hidden);

        D[layer] = delta_hidden_scaled;
    }

    // Weight Update
    for (size_t layer = 0; layer < nn->num_layers - 1; ++layer) {
        Matrix* transpose_A = linear_transpose(A[layer]);
        Matrix* update = linear_dot(transpose_A, D[layer]);
        linear_scale(update, -nn->alpha);  // Apply learning rate
        linear_add(nn->W[layer], update);

        free_matrix(transpose_A);
        free_matrix(update);
    }

    // Free allocated memory
    for (size_t i = 0; i < nn->num_layers; ++i) {
        free_matrix(A[i]);
        free_matrix(D[i]);
    }
    free(A);
    free(D);
    free_matrix(error);
}


Matrix* predict(NeuralNetwork* nn, Matrix* X, int add_bias) {
    Matrix* p = copy_matrix(X->data[0], X->rows, X->cols);

    if (add_bias) {
        // Insert a column of 1's as the last entry in the feature matrix (bias)
        Matrix* bias_column = make_matrix(X->rows, 1);
        for (int i = 0; i < X->rows; ++i) {
            bias_column->data[i][0] = 1.0;
        }

        Matrix* new_p = linear_add(p, bias_column);
        free_matrix(p);
        free_matrix(bias_column);
        p = new_p;
    }

    for (size_t i = 0; i < nn->num_layers - 1; ++i) {
        Matrix* net = linear_dot(p, nn->W[i]);
        Matrix* out = linear_sigmoid(net);

        free_matrix(p);
        free_matrix(net);
        p = out;
    }

    return p;
}

double calculate_loss(NeuralNetwork* nn, Matrix* X, Matrix* targets) {
    Matrix* predictions = predict(nn, X, 0);
    Matrix* error = linear_sub(predictions, targets);
    Matrix* squared_error = linear_exp(error);
    double loss = 0.5 * linear_sum(squared_error);

    free_matrix(predictions);
    free_matrix(error);
    free_matrix(squared_error);

    return loss;
}