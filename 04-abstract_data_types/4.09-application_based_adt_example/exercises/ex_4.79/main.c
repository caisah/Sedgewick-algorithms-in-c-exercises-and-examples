#include "vector.h"

int main(void) 
{
  vector v, w;

  v = vect_make(1.0, 2.0, 3.0);
  w = vect_make(2.0, 2.0, 2.0);
  vect_print(v);
  vect_print(w);
  vect_print(vect_add(v, w));
  vect_print(vect_dot_prod(v, w));
  vect_print(vect_cross_prod(v, w));
  vect_print(vect_scalar_prod(v, 3));
  return 0;
}
