#include "item.h"

typedef struct STACKnode *link;
struct STACKnode 
{
  Item item;
  link next;
  link prev;
};

void STACKinit(int);
int STACKempty(void);
void STACKpush(Item);
Item STACKpop(void);
