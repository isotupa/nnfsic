#include "linear.h"

Matrix* make_matrix(int n_rows, int n_cols) {
    struct Matrix* matrix = malloc(sizeof(Matrix));
    matrix->rows = n_rows;
    matrix->cols = n_cols;
    double** data = malloc(sizeof(double*) * n_rows); 
    for(int x = 0; x < n_rows; x++){
        data[x] = calloc(n_cols, sizeof(double));
    }
    matrix->data = data;
    return matrix;
}

Matrix* copy_matrix(double* data, int n_rows, int n_cols) {
    struct Matrix *matrix = make_matrix(n_rows, n_cols);
    for(int x = 0; x < n_rows; x++) {
        for(int y = 0; y < n_cols; y++) {
            matrix->data[x][y] = data[n_cols*x+y];
        }
    }
    return matrix;    
}

void print_matrix(Matrix* m) {
    if(m == NULL) {
        printf("NULL\n");
        return;
    }
    for(int x = 0; x < m->rows; x++) {
        printf("%s", "\n");
        for(int y = 0; y < m->cols; y++) {
            printf("%f\t", m->data[x][y]);
        }
    }
}

Matrix* dot_product(Matrix* m1, Matrix* m2) {
    if(m1->cols != m2->rows) return NULL;

    Matrix* res = make_matrix(m1->rows, m2->cols);
    int i, j, k;

    for(i = 0; i < m1->rows; i++) {
        for(j = 0; j < m2->cols; j++) {
            res->data[i][j] = 0;
            for(k = 0; k < m2->rows; k++) {
                res->data[i][j] += m1->data[i][k]*m2->data[k][j];
            }
        }
    }

    return res;
}

Matrix* add(Matrix* m1, Matrix* m2) {
    if(m1->cols != m2->cols || m1->rows != m2->rows) return NULL;

    Matrix* res = make_matrix(m1->rows, m1->cols);
    int i, j;

    for(i = 0; i < m1->rows; i++) {
        for(j = 0; j < m1->cols; j++) {
            res->data[i][j] = m1->data[i][j] + m2->data[i][j];
        }
    }

    return res;
}
