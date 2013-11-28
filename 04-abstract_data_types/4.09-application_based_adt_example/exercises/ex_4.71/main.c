#include <stdio.h> 
#include <stdlib.h> 
#include "poly.h"

int main(void) 
{
  Poly p, q, r;

  p = POLYterm(2, 2);
  showPOLY(p);
  printf("\n");
  q = POLYterm(1, 1);
  showPOLY(q);
  printf("\n");
  r = POLYadd(p, q);
  showPOLY(r);
  printf("\n");  
  return 0;
}
