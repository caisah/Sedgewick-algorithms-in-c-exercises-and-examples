#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h>
#include "queue.h"

int main(void) 
{
  char *expr = "E a s Y", *result = "a s Y e";
  char first, last, *s;
  int n, i = 0, j = 0, k = 0, m;
  
  n = strlen(expr) + 1;
  s = malloc(n * sizeof(char));
  QUEUEinit(2 * n);
  // loop until the end of expr
  while(i < n)
    {
      // add letters to queue and result
      if (islower(expr[i]))
	{
	  QUEUEput_end(expr[i]);
	  s[k++] = expr[i];
	}
      if (isupper(expr[i]))
	{
	  QUEUEput_begin(expr[i]);
	  s[k++] = expr[i];
	}
      // check for sign needed
      if ( !QUEUEempty())
	{
	if ( (last = QUEUEget_end()) == result[j])
	  {
	    s[k++] = '*';
	    j += 2;
	  }
	else
	  QUEUEput_end(last);
	}
      
      if ( !QUEUEempty())
	{
	if ( (first = QUEUEget_begin()) == result[j])
	  {
	    s[k++] = '+';
	    j += 2;
	  }
	else
	  QUEUEput_begin(first);
	}
      i += 2;
    }
  // add the last signs
  while (!QUEUEempty())
    {
      QUEUEget_begin();
      s[k++] = '*';
    }
  s[k] = '\0';
  m = k;
  // print result
  for (i = 0; i < m; i++)
    printf("%c ", s[i]);
  printf("\n");
  return 0;
}
