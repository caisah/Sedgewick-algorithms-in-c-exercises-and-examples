#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include "point.h"

int main(void) 
{
  point first, n, closest;
  bool is_first_number = true;
  int shortest_dist;

  while (!feof(stdin))
    {
      printf("Enter the number: ");
      scanf ("%d %d", &n.x, &n.y);
      if (is_first_number)
	{
	  first = n;
	  shortest_dist = INT_MAX;
	  is_first_number = false;
	  continue;
	}
      if (distance(first, n) < shortest_dist)
	{
	  closest = n;
	  shortest_dist = distance(first, n);
	}
    }
  printf("Closest point: %d, %d\n", closest.x, closest.y);
  return 0;
}
