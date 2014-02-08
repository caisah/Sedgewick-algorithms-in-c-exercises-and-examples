#include <stdio.h> 
#include <stdlib.h> 
#include "item.h"

double ITEMrand(void)
{
  return 1.0*rand()/RAND_MAX;
}

Item ITEMscan(double *x)
{
  return scanf("%lf", x);
}

void ITEMshow(double x)
{
  printf("%7.5f ", x);
}  
