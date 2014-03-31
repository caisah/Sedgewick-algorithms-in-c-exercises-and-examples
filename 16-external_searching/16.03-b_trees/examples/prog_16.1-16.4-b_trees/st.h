#ifndef ST_H
#define ST_H

#include "item.h"

#define M 4

void STinit(int);
int STcount(void);
void STinsert(Item);
Item STsearch(Key);

#endif
