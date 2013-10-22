#include <stdio.h>
#include "point.h"

int main(void) 
{
  point a, b, c;

  printf("Enter the coordinates of the 1st point: ");
  scanf("%f %f", &a.x, &a.y);
  printf("Enter the coordinates of the 2nd point: ");
  scanf("%f %f", &b.x, &b.y);
  printf("Enter the coordinates of the 3rd point: ");
  scanf("%f %f", &c.x, &c.y);
  if (collinear(a, b, c))
    printf("The points are collinear\n");
  else
    printf("The points are not collinear\n");
    
  return 0;
}


