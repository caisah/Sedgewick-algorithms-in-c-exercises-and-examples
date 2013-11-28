#include <stdio.h> 
#include <stdlib.h> 
#include "poly.h"

int main(void) 
{
  Poly p;

  p = POLYadd(POLYterm(1, 5, 3), POLYterm(1, 1, 4));
  showPOLY(p);
  printf("\n");
  return 0;
}
