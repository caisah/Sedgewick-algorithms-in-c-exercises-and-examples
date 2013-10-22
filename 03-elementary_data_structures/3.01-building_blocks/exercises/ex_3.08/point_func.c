#include <math.h>
#include <stdbool.h>
#include "point.h"

float distance(point a, point b)
{
  float dx = a.x - b.x, dy = a.y - b.y;
  return sqrt(dx*dx + dy*dy);
}

int slope(point a, point b)
{
  int x = (b.x - a.x) * pow (10, 4);
  int y = (b.y - a.y) * pow (10, 4);

  return x/y;
}
bool collinear(point a, point b, point c)
{
  return (slope(a, b) == slope(b, c));
}
