#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include "item.h"

Item ITEMrand(Key key)
{
  Item item = malloc(sizeof(Item));

  item->keyVal = malloc(sizeof(key));
  strcpy(item->keyVal, key);
  item->value = (rand() % maxN);
  return item;
}

void ITEMshow(Item item)
{
  if (item != NULLitem)
    printf("key: %s, value: %d\n", item->keyVal, item->value);
  else
    printf("NULLitem \n");
}

Key key(Item item)
{
  return (item == NULLitem) ? '\0' : item->keyVal;
}
