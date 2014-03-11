#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include "item.h"
#include "st.h"

int main(int argc, char *argv[]) 
{
  int N, i;
  Item item;
  Key key;

  srand(time(NULL));
  if (argc != 2)
    printf("Insufficient args. Enter N!");
  else
    {
      N = atoi(argv[1]);
      STinit(N);
      for (i = 0; i < N; i++)
	{
	  key = ITEMrandkey();
	  if (STsearch(key) != NULLitem)
	    {
	      printf(" Duplicate key! ");
	      continue;
	    }
	  item = ITEMrand(key);
	  printf("%d ", item->value);
	  STinsert(item);
	}
      printf("\n");
      STsort (ITEMshow);
      printf ("\n");
    }

  return 0;
}
