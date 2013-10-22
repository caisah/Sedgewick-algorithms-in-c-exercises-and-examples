#include <math.h>
#include "point.h"
#include "triangle.h"

float area(triangle t)
{
  float a, b, c;

  a = distance(t.a, t.b);
  b = distance(t.b, t.c);
  c = distance(t.a, t.c);

  return sqrt((a+b-c)*(a-b+c)*(b+c-a)*(a+b+c))/4;
}
