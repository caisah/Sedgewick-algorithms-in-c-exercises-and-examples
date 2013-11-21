#include <stdlib.h> 
#include "complex.h"

struct Complex
{
  float Re;
  float Im;
};

complex COMPLEXinit(float Re, float Im)
{
  complex t = malloc(sizeof *t);

  t->Re = Re;
  t->Im = Im;
  return t;
}

float Re(complex z)
{
  return z->Re;
}

float Im(complex z)
{
  return z->Im;
}

complex COMPLEXmult(complex a, complex b)
{
  return COMPLEXinit(Re(a)*Re(b) - Im(a)*Im(b),
		     Re(a)*Im(b) + Im(a)*Re(b));
}
