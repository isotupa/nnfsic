#include <stdio.h>
#include <stdlib.h>
#include <src/neural.h>
#include <src/data.h>
#include <src/csv_reader.h>

#define DATASET_SIZE 10000
#define TEST_PERCENTAGE 30
#define TRAIN_PERCENTAGE 70

int main() {
    const char** label_path = "datasets/t10k-images-idx3-ubyte";
    const char** data_path = "datasets/t10k-labels-idx1-ubyte";

    printf("[INFO] Loading MNIST dataset...");
    Data* data = csv_reader(label_path, data_path);

    Data* data_train = malloc(sizeof(Data) * (TRAIN_PERCENTAGE/100 * DATASET_SIZE));
    int i = 0;
    for(i = 0; i < TRAIN_PERCENTAGE/100 * DATASET_SIZE; i++) {
        data_train
    }
    
}