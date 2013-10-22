#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "Point.h"

#define N 100


float randFloat()
{
  return 1.0*rand()/RAND_MAX;
}

int main(void)
{
  float d = FLT_MAX, d2;
  int i, j, cnt = 0, n = N, ii, jj;
  point *a = malloc(n * sizeof(*a));

  for (i = 0; i < n; i++)
    {
      a[i].x = randFloat();
      a[i].y = randFloat();
    }
  for (i = 0; i < n-1; i++)
    for (j = i+1; j < n; j++)
      if ((d2=distance(a[i], a[j])) < d)
	{
	  d = d2;
	  ii = i;
	  jj = j;
	}
	cnt++;
	printf("Closest points: %f, %f and %f, %f\n",
	       a[ii].x, a[ii].y, a[jj].x, a[jj].y);
  return 0;
}
