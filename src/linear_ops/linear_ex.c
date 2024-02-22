#include <stdlib.h>
#include <stdio.h>
#include "linear.h"

int main(void) {
    // double a[] = { 
    //     1, 2, 3, 
    //     4, 5, 6, 
    //     7, 8, 9,
    //     10,11,12
    //     };
    double a[] = {
        2,2,2,2
    };
    double b[] = {
        2,2,2,2
    };
    Matrix* m1 = copy_matrix(a, 2,2);
    Matrix* m2 = copy_matrix(b, 2,2);
    // print_matrix(m1);
    Matrix* res = dot_product(m1, m2);
    print_matrix(res);
    res = add(res, m1);
    print_matrix(res);
    return 0;
}