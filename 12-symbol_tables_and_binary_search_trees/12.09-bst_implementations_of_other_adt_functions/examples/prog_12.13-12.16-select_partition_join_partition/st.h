#ifndef ST_H
#define ST_H

#include "item.h"

void STinit();
int STcount(void);
void STinsert(Item);
Item STsearch(Key);
Item STselect(int);
void STdelete(Key);

#endif
