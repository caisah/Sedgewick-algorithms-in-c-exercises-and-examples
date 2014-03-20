#include <stdio.h>

#define a 127
#define st "blabla"

int hash(char *v, int M)
{
  int h = 0;

  for (; *v != '\0'; v++)
    h = (a*h + *v) % M;
  return h;
}

int main(void) 
{
  int M = 100;
  
  printf("Hash for \'%s\' in %d range is: %d\n", st, M, hash(st, M));
  return 0;
}
