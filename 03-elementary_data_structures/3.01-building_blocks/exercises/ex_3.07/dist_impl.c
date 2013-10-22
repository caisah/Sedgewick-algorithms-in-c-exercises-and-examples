#include <math.h>
#include "point.h"

int distance (point a, point b)
{
  int x = b.x - a.x;
  int y = b.y - a.y;
  
  return sqrt(x*x + y*y);
}
