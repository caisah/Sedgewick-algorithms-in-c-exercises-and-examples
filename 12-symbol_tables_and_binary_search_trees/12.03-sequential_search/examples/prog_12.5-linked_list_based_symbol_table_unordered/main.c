#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include "item.h"
#include "st.h"

#define S 4

int main(int argc, char *argv[]) 
{
  int N, i;
  Item item;
  Key key, searched_key;

  srand(time(NULL));
  if (argc != 2)
    printf("Insufficient args. Enter N > 4!");
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
	  if (i == S)
	    searched_key = key;
	  printf("%d ", item->value);
	  STinsert(item);
	}
      printf("\n");
      printf("The element with the key %d is: ", searched_key);
      ITEMshow(STsearch(searched_key));
    }
  return 0;
}
