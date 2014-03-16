#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include "item.h"
#include "st.h"

#define K 4 // The K-th item is searched

int main(int argc, char *argv[]) 
{
  int N, i;
  Item item;
  Key key;

  srand(time(NULL));
  if (argc != 2)
    printf("Insufficient args. Enter N!\n");
  else
    {
      N = atoi(argv[1]);
      STinit();
      for (i = 0; i < N; i++)
      	{
      	  key = ITEMrandkey();
      	  item = ITEMrand(key);
      	  printf("%d ", item->value);
      	  STinsert(item);
      	}
      printf("\n");
      STsort(ITEMshow);
      printf("\n");
    }
  return 0;
}
