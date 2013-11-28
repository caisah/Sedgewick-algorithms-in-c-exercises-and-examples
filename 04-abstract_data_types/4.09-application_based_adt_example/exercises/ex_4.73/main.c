#include <stdio.h> 
#include <stdlib.h> 
#include "poly.h"

int main(void) 
{
  Poly p, q, r;

  p = POLYadd(POLYterm(2, 2), POLYterm(1, 1));
  showPOLY(p);
  printf("\n");
  showPOLY(POLYdiff(p));
  printf("\n");
  showPOLY(POLYinteg(p));
  printf("\n");
  return 0;
}
