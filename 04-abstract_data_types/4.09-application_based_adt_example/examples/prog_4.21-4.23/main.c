#include <stdio.h> 
#include <stdlib.h> 
#include "poly.h"

int main(int argc, char *argv[]) 
{
  int N = 2;/* atoi(argv[1]); */
  float p = 1;/* atof(argv[2]); */
  Poly t, x;
  int i;

  printf("Binomial coefficients\n");
  t = POLYadd(POLYterm(1, 1), POLYterm(1, 0));
  for (i = 0, x = t; i < N-1; i++)
    {
      x = POLYmult(t, x);
      showPOLY(x);
    }
  printf("%f\n", POLYeval(x, p));
  return 0;
}
