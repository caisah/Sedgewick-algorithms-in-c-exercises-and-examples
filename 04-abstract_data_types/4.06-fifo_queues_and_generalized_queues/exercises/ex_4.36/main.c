#include <stdio.h>
#include <string.h> 
#include <ctype.h>
#include "queue.h"

int skip_spaces(char *, int);

int main(void) 
{
  
  char *res = "E + a s * * Y *";
  char *first = "E a s Y";
  char *second = "E s a Y";
  int n;
  /* char *a = "E a * s Y + * *";  // a Y s E */
  /* char *a = "E a * s * Y + *";  // a s Y e */
  
  n = strlen(a);
  QUEUEinit(2 * n);
  while(i < n)
    {
      i = skip_spaces(first, i);
      j = skip_spaces(second, j);

      if (!QUEUEempty())
	{
	  verify_queue(second[j]);
	  if (first[i] == second[j])
	    {
	      printf("%c * ", first[i]);
	      j++;
	    }
	  else
	    {
	      if (islower(first[i]))
		QUEUEput_end(first[i]);
	      if (isupper(first[i]))
		QUEUEput_begin(first[i]);
	    }
	  i++;
	}
    }
}
/* skip_spaces: returns next nonspace position */
int skip_spaces(char *expr, int i)
{
  while(expr[i] == ' ')
    i++;
  return i;
}
