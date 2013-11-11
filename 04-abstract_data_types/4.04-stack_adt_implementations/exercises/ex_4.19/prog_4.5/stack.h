#include "item.h"

typedef struct STACKnode *link;
struct STACKnode 
{
  Item item;
  link next;
};

void STACKinit(int);
int STACKempty(void);
int STACKcount(void);
void STACKpush(Item);
Item STACKpop(void);
