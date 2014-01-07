#include <stdlib.h>
#include "list.h"
#include "stack.h"

static link *s;
static int N;

void STACKinit(int maxn)
{
  s = malloc(maxn * sizeof(link));
  N = 0;
}
int STACKempty(void)
{
  return N == 0;
}
void STACKpush(link item)
{
  s[++N] = item;
}
link STACKpop(void)
{
  return s[N--];
}
