#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "item.h"
#include "st.h"

#define S 3

int main(int argc, char *argv[]) 
{
  int N, i;
  Item item, itm;
  Key searched_key = malloc(2 * sizeof(char)),
      key = malloc(2 * sizeof(char));
  char init = 'a';

  srand(time(NULL));
  if (argc != 2)
    printf("Insufficient args. Enter N > 4!");
  else
    {
      N = atoi(argv[1]);
      if (N > 30)
	{
	  printf("Enter 4 < value < 30\n");
	  return 0;
	}
      STinit(N);
      for (i = 0; i < N; i++)
	{
	  key[0] = init + i;
	  key[1] = '\0';
	  item = ITEMrand(key);
	  ITEMshow(item);
	  if (i == S)
	    strcpy(searched_key, key);
	  STinsert(item);
	}
      printf("\n");
      printf("Searching for element with key \'%s\'! ", searched_key);
      itm = STsearch(searched_key);
      ITEMshow(itm);
      
      printf("Deleting item!\n");
      STdelete(itm);
      printf("Searching for element with key \'%s\'! ", searched_key);
      ITEMshow(STsearch(searched_key));
    }
  return 0;
}
