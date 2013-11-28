#ifndef VECTOR_H
#define VECTOR_H

typedef struct Vector *vector;

vector vect_make(float, float, float);
vector vect_add(vector, vector);
vector vect_dot_prod(vector, vector);
vector vect_cross_prod(vector, vector);
vector vect_scalar_prod(vector, float);
void vect_print(vector);

#endif
