#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "Point.h"

float randFloat()
{
  return 1.0*rand()/RAND_MAX;
}

int main(int argc, char *argv[]) 
{
  float d = atof(argv[2]);
  int i, j, cnt = 0, n = atoi(argv[1]);
  point *a = malloc(n * sizeof(*a));

  for (i = 0; i < n; i++)
    {
      a[i].x = randFloat();
      a[i].y = randFloat();
    }
  for (i = 0; i < n; i++)
    for (j = i+1; j < n; j++)
      if (distance(a[i], a[j]) < d)
	cnt++;
  printf("%d edges shorter than %f\n", cnt, d);
  
  return 0;
}
