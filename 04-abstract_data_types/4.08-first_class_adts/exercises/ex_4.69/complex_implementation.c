#include <stdio.h> 
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

complex COMPLEXadd(complex a, complex b)
{
  return COMPLEXinit(Re(a)+Re(b), Im(a)+Im(b));
}

void COMPLEXprint(complex z)
{
  float im = Im(z), re = Re(z);

  if (im < 0)
    printf("%.2f%.2fi\n",re, im);
  else
    printf("%.2f+%.2fi\n",re, im);
}
