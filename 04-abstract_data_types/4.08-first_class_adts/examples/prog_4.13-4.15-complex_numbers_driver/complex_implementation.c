#include "complex.h"

complex COMPLEXinit(float Re, float Im)
{
  complex t;

  t.Re = Re;
  t.Im = Im;
  return t;
}

float Re(complex z)
{
  return z.Re;
}

float Im(complex z)
{
  return z.Im;
}

complex COMPLEXmult(complex a, complex b)
{
  complex t;

  t.Re = a.Re*b.Re - a.Im*b.Im;
  t.Im = a.Re*b.Im + a.Im*b.Re;
  return t;
}
