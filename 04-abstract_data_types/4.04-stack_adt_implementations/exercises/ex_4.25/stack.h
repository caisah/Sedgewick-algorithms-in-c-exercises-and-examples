#include "item.h"

// int stack
void iSTACKinit(int);
int iSTACKempty(void);
void iSTACKpush(int);
int iSTACKpop(void);

// double stack
void STACKinit(int);
int beginSTACKempty(void);
int endSTACKempty(void);
void beginSTACKpush(Item);
void endSTACKpush(Item);
Item beginSTACKpop(void);
Item endSTACKpop(void);
