#include <stdio.h>

#define st "b"

int hashU(char *v, int M)
{
  int h, a = 31415, b = 27183;

  for (h = 0; *v != '\0'; v++, a = a*b % (M-1))
    h = (a*h + *v) % M;
  return h;
}

int main(void) 
{
  int M = 5;
  
  printf("Hash for \'%s\' in %d range is: %d\n", st, M, hashU(st, M));
  return 0;
}
