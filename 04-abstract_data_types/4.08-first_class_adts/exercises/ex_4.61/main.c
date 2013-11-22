#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "point.h"

#define N 5

int main(void) 
{
  point *p, p1, p2;
  int x, y;
  float min_dist = FLT_MAX;
  int i, j;

  p = malloc(N * sizeof(point));
  for (i = 0; i < N; i++)
    {
      printf("Enter coordinates for point %d: ", i);
      if (scanf("%d %d", &x, &y) == 2)
	  p[i] = create_point(x, y);
      else
	i--;
    }
  for (i = 0; i < N-1; i++)
    for (j = i+1; j < N; j++)
      if (distance(p[i], p[j]) < min_dist)
	{
	  min_dist = distance(p[i], p[j]);
	  p1 = p[i];
	  p2 = p[j];
	}
  printf("Minimum distance is between: ");
  print_point(p1);
  printf(" and ");
  print_point(p2);
  printf(" : %.4f\n", min_dist);
  return 0;
}
