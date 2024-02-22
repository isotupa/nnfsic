#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct Matrix {
    int rows; // number of rows
    int cols; // number of columns
    double** data; // a pointer to an array of n_rows pointers to rows; a row is an array of n_cols doubles 
} Matrix;

Matrix* make_matrix(int n_rows, int n_cols);

Matrix* copy_matrix(double* data, int n_rows, int n_cols);

void print_matrix(Matrix* m);

Matrix* dot_product(Matrix* m1, Matrix* m2);

Matrix* add(Matrix*, Matrix*);
