#include <stdio.h> 
#include <stdlib.h> 
#include "poly.h"

int main(void)
{
  Poly x, y, z;

  x = POLYterm(1, 1);
  y = POLYterm(1, 0);
  z = POLYadd(x, y);
  showPOLY(z);
  showPOLY(POLYmult(z, z));
  printf("%.2f\n", POLYeval(z, 2));
  return 0;
}
