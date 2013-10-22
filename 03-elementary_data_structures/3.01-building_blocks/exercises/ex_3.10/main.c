#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "point.h"
#include "triangle.h"

#define N 20

float rand_float(void);

int main(void) 
{
  point a, b, c;
  triangle t;
  int i;
  float sum=0.0;

  srand(time(NULL));
  for (i = 0; i < N; i++) 
    {
      a.x = rand_float();
      a.y = rand_float();
      b.x = rand_float();
      b.y = rand_float();
      c.x = rand_float();
      c.y = rand_float();
      if (!collinear(a, b, c))
	{
	  t.a = a;
	  t.b = b;
	  t.c = c;
	  sum += area(t);
	}
    }
  printf("Average area: %f\n", sum/N);
  return 0;
}

float rand_float()
{
  int r = rand() % 1000;

  return r * 0.001;
}
