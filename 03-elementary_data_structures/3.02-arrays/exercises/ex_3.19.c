#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000

int rand_100(void);

int main(void) 
{
  int i, a[N], n, j;
  long count=0;

  srand(time(NULL));
  for (i = 0; i < N; i++)   // initialize map array to 0
    a[i] = 0;
  for (;;) 
    {
      n = rand_1000();
      if (n < N)
	{
	  if (a[n])
	    {
	      for (j = 0; j < N; j++)
		if (a[j] == 0)
		  break;
	      if (j == N)
		break;
	    }
	  else
	    a[n] = 1;
	  count++;
	}
    }
  printf("%ld\n", count);
  return 0;
}

int rand_1000()        // generate numbers up to 1000
{
  return (rand() % 1000);
}
