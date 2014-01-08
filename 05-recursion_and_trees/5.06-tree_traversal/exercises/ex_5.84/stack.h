#ifndef STACK_H
#define STACK_H

#include "link.h"

void STACKinit(int);
int STACKempty(void);
void STACKpush(link);
link STACKpop(void);
link STACKpeek(void);

#endif
