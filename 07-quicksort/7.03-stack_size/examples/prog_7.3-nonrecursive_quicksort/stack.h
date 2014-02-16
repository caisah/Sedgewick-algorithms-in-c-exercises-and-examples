#ifndef STACK_H
#define STACK_H

#include "item.h"

void STACKinit(int);
int STACKempty(void);
void STACKpush(Item);
Item STACKpop(void);
#endif
