#include <stdio.h>
#include <math.h>
#include <stdlib.h> 
#include "point.h"

struct Point
{
  int x;
  int y;
};

point create_point(int x, int y)
{
  point p = malloc(sizeof(point));

  p->x = x;
  p->y = y;
  return p;
}

void print_point(point p)
{
  printf("(%d, %d)", p->x, p->y);
}

float distance(point a, point b)
{
  return sqrt(pow( (b->x - a->x), 2.0) +
	      pow( (b->y - a->y), 2.0));
}
