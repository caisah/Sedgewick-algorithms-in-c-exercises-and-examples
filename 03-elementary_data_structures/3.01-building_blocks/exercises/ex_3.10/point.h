#include <stdbool.h>

typedef struct
{
  float x;
  float y;
} point;

float distance(point, point);
int slope(point, point);
bool collinear(point, point, point);
