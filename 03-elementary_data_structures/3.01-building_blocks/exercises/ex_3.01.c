#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void) 
{
  printf("int min: %d, int max: %d\n", INT_MIN, INT_MAX);
  printf("long min: %ld, long max: %ld\n", LONG_MIN, LONG_MAX);
  printf("short min: %d, short max: %d\n", SHRT_MIN, SHRT_MAX);
  printf("float min: %f, float max: %f\n", FLT_MIN, FLT_MAX);
  printf("double min: %lf, double max: %lf\n", DBL_MIN, DBL_MAX);

  return 0;
}
