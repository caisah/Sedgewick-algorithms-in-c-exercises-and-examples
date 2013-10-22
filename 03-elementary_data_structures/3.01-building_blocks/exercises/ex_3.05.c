#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef int Number;
Number randNumber(void);

Number randNumber()
{
  return rand() % 2;
}

int main(int argc, char *argv[])
{
  int i, N = atoi(argv[1]);
  float m1 = 0.0, m2 = 0.0;
  Number x;

  for (i = 0; i < N; i++)
    {
      x = randNumber();
      m1 += ((float) x)/N;
      m2 += ((float) x*x)/N;
    }
  printf("       Average: %.4f\n", m1);
  printf("Std. defiation: %.4f\n", sqrt(m2-m1*m1));
  return 0;
}
