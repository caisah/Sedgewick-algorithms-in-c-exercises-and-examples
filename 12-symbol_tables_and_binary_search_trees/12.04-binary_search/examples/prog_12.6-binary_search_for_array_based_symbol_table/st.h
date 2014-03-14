#ifndef ST_H
#define ST_H

#include "item.h"

void STinit(int);
int STcount(void);
void STinsert(Item);
Item STsearch(Key);
void STdelete(Item);
Item STselect(int);
void STsort(void (*visit) (Item));

#endif
