#ifndef MAT_H
#define MAT_H

#include "item.h"

typedef struct Matrix *mat;

mat mat_create(int, int);
int mat_rows(mat);
int mat_cols(mat);
void mat_add_elem(mat, int, int, int);
mat mat_add(mat, mat);
mat mat_sub(mat, mat);
mat mat_mul(mat, mat);
void mat_print(mat);

#endif
