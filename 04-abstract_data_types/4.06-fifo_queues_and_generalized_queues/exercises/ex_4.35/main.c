#include <stdio.h>
#include <string.h> 
#include <ctype.h>
#include "queue.h"

int main(void) 
{
  char *a = "E * a s * + Y *";  // E s a Y
  /* char *a = "E a * s Y + * *";  // a Y s E */
  /* char *a = "E a * s * Y + *";  // a s Y e */
  int n, i = 0;
  
  n = strlen(a);
  QUEUEinit(n);
  for (i = 0; i < n; i++)
    {
      if (isupper(a[i]))
      	QUEUEput_begin(a[i]);
      if (islower(a[i]))
      	QUEUEput_end(a[i]);
      if (a[i] == '+')
      	printf("%c ", QUEUEget_begin());
      if (a[i] == '*')
      	printf("%c ",QUEUEget_end());
    }
  printf("\n");
  return 0;
}
