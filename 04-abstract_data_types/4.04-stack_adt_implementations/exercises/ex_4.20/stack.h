#include "item.h"

void STACKinit(int);
int STACKempty(void);
int STACKcount(void);
void STACKpush(Item);
Item STACKpop(void);
void STACKerror(const char*);
