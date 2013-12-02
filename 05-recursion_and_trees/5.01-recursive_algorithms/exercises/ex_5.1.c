#include <stdio.h> 
#include <math.h>

#define N 10

float fac_log(int n)
{
  if (n == 1)
    return 0;
  else
    return fac_log(n-1) + log2f( (float) n);
}

int main(void) 
{
  printf("%.4f\n", fac_log(N));
}
