#include <stdio.h>
#include <stdlib.h>
// #include <src/neural.h>
// #include <src/data.h>
// #include <src/csv_reader.h>

// #define DATASET_SIZE 10000
// #define TEST_PERCENTAGE 30
// #define TRAIN_PERCENTAGE 70
#include "src/neural.h"

int main() {
    // const char** label_path = "datasets/t10k-images-idx3-ubyte";
    // const char** data_path = "datasets/t10k-labels-idx1-ubyte";

    // printf("[INFO] Loading MNIST dataset...");
    // Data* data = csv_reader(label_path, data_path);

    // Data* data_train = malloc(sizeof(Data) * (TRAIN_PERCENTAGE/100 * DATASET_SIZE));
    // int i = 0;
    // for(i = 0; i < TRAIN_PERCENTAGE/100 * DATASET_SIZE; i++) {
    //     data_train
    // }

    // XOR operation example
    int layers[] = {2, 2, 1};  // 2 input nodes, 2 hidden nodes, 1 output node
    size_t num_layers = sizeof(layers) / sizeof(layers[0]);
    double alpha = 0.1;

    NeuralNetwork* nn = initialize_neural_network(layers, num_layers, alpha);

    // XOR input and target data
    int num_samples = 4;
    int num_features = 2;

    double input_data[][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    double target_data[][1] = {{0}, {1}, {1}, {0}};

    Matrix* X = make_matrix(num_samples, num_features);
    Matrix* y = make_matrix(num_samples, 1);

    for (int i = 0; i < num_samples; ++i) {
        for (int j = 0; j < num_features; ++j) {
            X->data[i][j] = input_data[i][j];
        }
        y->data[i][0] = target_data[i][0];
    }

    // Train the neural network
    int epochs = 10000;
    int display_update = 1000;
    fit(nn, X, y, epochs, display_update);

    // Test predictions
    printf("Testing predictions for XOR operation:\n");
    for (int i = 0; i < num_samples; ++i) {
        Matrix* sample = make_matrix(1, num_features);
        for (int j = 0; j < num_features; ++j) {
            sample->data[0][j] = input_data[i][j];
        }

        Matrix* prediction = predict(nn, sample, 1);
        printf("Input: [%lf, %lf] => Prediction: %lf, Actual: %lf\n",
               sample->data[0][0], sample->data[0][1], prediction->data[0][0], target_data[i][0]);

        free_matrix(sample);
        free_matrix(prediction);
    }

    // Clean up
    free_matrix(X);
    free_matrix(y);
    free_neural_network(nn);

    return 0;
    
}