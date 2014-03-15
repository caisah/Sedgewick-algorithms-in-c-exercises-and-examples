#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include "item.h"
#include "st.h"

#define K 4 // The K-th item is searched

int main(int argc, char *argv[]) 
{
  int N, i;
  Item item, sitem;
  Key key, skey;

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
      	  /* if (STsearch(key) != NULLitem) */
      	  /*   { */
      	  /*     printf(" Duplicate key! "); */
      	  /*     continue; */
      	  /*   } */
      	  item = ITEMrand(key);
      	  printf("%d ", item->value);
      	  STinsert(item);
      	  if (i == K-1)
      	    skey = key;
      	}
      sitem = STsearch(skey);
      printf("\nThe %d-th item: %d, key: %d\n", K, sitem->value, sitem->keyVal);
    }

  return 0;
}
