#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "complex.h"

#define PI 3.141592625

int main(int argc, char *argv[]) 
{
  int i, j, n = atoi(argv[1]);
  complex t, x;

  printf("%dth complex roots of unity\n", n);
  for (i = 0; i < n; i++)
    {
      float r = 2.0 * PI *i/n;
      t = COMPLEXinit(cos(r), sin(r));
      printf("%2d %6.3f %6.3f ", i, Re(t), Im(t));
      for (x = t, j = 0; j < n-1; j++)
	x = COMPLEXmult(t, x);
      printf("%6.3f %6.3f\n", Re(x), Im(x));
    }
  return 0;
}
