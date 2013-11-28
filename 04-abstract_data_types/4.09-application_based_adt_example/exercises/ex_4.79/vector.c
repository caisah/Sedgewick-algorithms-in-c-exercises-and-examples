#include <stdio.h> 
#include <stdlib.h> 
#include "vector.h"

struct Vector
{
  float x;
  float y;
  float z;
};

vector vect_make(float x, float y, float z)
{
  vector v = malloc(sizeof(vector));

  v->x = x;
  v->y = y;
  v->z = z;
  return v;
}

vector vect_add(vector v, vector w)
{
 return  vect_make(v->x + w->x,
		   v->y + v->y,
		   v->z + w->z);
}

vector vect_dot_prod(vector v, vector w)
{
  return vect_make(v->x * w->x,
		   v->y * w->y,
		   v->z * w->z);
}

vector vect_cross_prod(vector v , vector w)
{
  return vect_make(v->y*w->z - v->z*w->y,
		   v->z*w->x - v->x*v->z,
		   v->x*w->y - v->y*w->z);
}

vector vect_scalar_prod(vector v, float x)
{
  return vect_make(x*v->x, x*v->y, x*v->z);
}

void vect_print(vector v)
{
  printf("(%2.2f, %2.2f, %2.2f)\n", v->x, v->y, v->z);
}
