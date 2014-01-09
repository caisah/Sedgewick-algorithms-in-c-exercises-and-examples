#include <stdio.h> 
#include "item.h"

void print_item(Item x)
{
  printf("%c ", x);
}

int eq(Item x, Item y)
{
  return (x == y);
}
