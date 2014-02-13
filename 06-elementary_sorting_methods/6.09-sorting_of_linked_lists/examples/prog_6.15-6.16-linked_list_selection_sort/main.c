#include <stdio.h> 
#include <stdlib.h>
#include "list.h"

int main(int argc, char *argv[]) 
{
  link h, s;
  
  if (argc < 2)
    printf("N arg missing: \n");
  else
    {
      h = init(atoi(argv[1]));
      printf("Initial list: \n");
      show(h);
      printf("Final list: \n");
      s = sort(h);
      show(s);
    }
  return 0;
}
