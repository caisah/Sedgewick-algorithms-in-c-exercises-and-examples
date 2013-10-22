#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "num.h"

int main(int argc, char *argv[]) 
{
  int i, n = atoi(argv[1]);
  float m1 = 0.0, m2 = 0.0;
  Number x;

  for (i = 0; i < n; i++) 
    {
      x = randNum();
      m1 += ((float) x) / n;
      m2 += ((float) x*x) / n;
    }
  printf("Average: %f\n", m1);
  printf("Std. Deviations: %f\n", sqrt(m2-m1*m1));
  return 0;
}
