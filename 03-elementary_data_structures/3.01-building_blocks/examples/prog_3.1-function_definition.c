#include <stdio.h>

int lg(int);

int main(void)
{
  int i, N;
  for (i = 1, N = 10; i <= 6; i++, N *= 10)
    printf("%7d %2d %9d\n", N, lg(N), N*lg(N));
  return 0;
}

int lg(int N)
{
  int i;
  for (i = 0; N > 0; i++, N /= 2);
  return i;
}
