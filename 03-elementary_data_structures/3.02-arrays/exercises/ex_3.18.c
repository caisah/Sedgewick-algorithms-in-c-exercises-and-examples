#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000

int main(void) 
{
  int count=0, i, a[N], n;

  srand(time(NULL));
  for (i = 0; i < N; i++)   // initialize map array to 0
    a[i] = 0;
  for (;;) 
    {
      n = rand();
      if (n < N)
	if (a[n])          // if generated number less than 100 and repeated: break
	  break;           // else mark number as generated and increase count
	else
	  {
	    a[n] = 1;
	    count++;
	  }
    }
  printf("%d\n", count);
  return 0;
}
