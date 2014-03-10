#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include "item.h"
#include "st.h"

int main(int argc, char *argv[]) 
{
  int N, maxN = atoi(argv[1]), sw = atoi(argv[2]);
  Item item;

  srand(time(NULL));
  
  STinit(maxN);
  for (N = 0; N < maxN; N++)
    {
      if (sw)
	item = ITEMrand(maxN);
      else if (ITEMscan(&item) == EOF)
	break;
      if (STsearch(item) != NULLitem)
	continue;
      printf("%d ", item);
      STinsert(item);
    }
  STsort(ITEMshow);
  printf("\n");
  printf("%d keys ", N);
  printf("%d distinct keys\n", STcount());

  return 0;
}
