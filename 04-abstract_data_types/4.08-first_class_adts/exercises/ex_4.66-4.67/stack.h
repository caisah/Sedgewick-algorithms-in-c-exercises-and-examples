#include "item.h"

typedef struct stack *S;

S STACKinit(int);
int STACKempty(S);
void STACKpush(S, Item);
Item STACKpop(S);
