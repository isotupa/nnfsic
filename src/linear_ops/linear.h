#include "global_params.h"

typedef struct Matrix {
    int rows; // number of rows
    int cols; // number of columns
    double** data; // a pointer to an array of n_rows pointers to rows; a row is an array of n_cols doubles 
} Matrix;

Matrix* make_matrix(int n_rows, int n_cols);

void free_matrix(Matrix* m);

Matrix* copy_matrix(double* data, int n_rows, int n_cols);

void print_matrix(Matrix* m);

Matrix* linear_dot(Matrix* m1, Matrix* m2);

Matrix* linear_add(Matrix*, Matrix*);

Matrix* initialise_random(int n_rows, int n_cols);

Matrix* linear_div(Matrix* m1, Matrix* m2);

Matrix* linear_sqrt(Matrix* m);

Matrix* linear_exp(Matrix* m);