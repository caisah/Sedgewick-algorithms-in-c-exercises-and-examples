#ifndef ST_H
#define ST_H

#include "item.h"

void STinit();
int STcount(void);
void STinsert(Item);
Item STsearch(Key);
void STsort(void (*visit)(Item));

#endif
