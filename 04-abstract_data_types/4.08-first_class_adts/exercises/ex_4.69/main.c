#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "complex.h"

/* suffix add and multiplication of complex numbers */
int main(int argc, char *argv[]) 
{
  char *a = "1+1i 0+1i + 1-2i * 3+4i +";
  int i, n = strlen(a), sign = 1.0;
  float im, re, m=0;
  S st;

  st = STACKinit(n/2);
  for (i = 0; i < n; i++)
    {
      if ( (a[i] == '+') && (a[i-1] == ' '))
  	STACKpush(st, COMPLEXadd(STACKpop(st), STACKpop(st)));
      if ( (a[i] == '*') && (a[i-1] == ' '))
  	STACKpush(st, COMPLEXmult(STACKpop(st), STACKpop(st)));
      if ((a[i] >= '0') && (a[i] <= '9'))
  	{
  	  while ((a[i] >= '0') && (a[i] <= '9'))
  	    m = 10 * m + (a[i++] - '0');
  	  if (a[i] == 'i')
  	    {
  	      im = sign * m;
  	      STACKpush(st, COMPLEXinit(re, im));
  	    }
  	  else
  	    re = sign * m;
  	  m = 0;
  	  sign = 1.0;
  	}
      if (a[i] == '-')
  	sign = -1.0;
    }
  COMPLEXprint(STACKpop(st));
  return 0;
}
