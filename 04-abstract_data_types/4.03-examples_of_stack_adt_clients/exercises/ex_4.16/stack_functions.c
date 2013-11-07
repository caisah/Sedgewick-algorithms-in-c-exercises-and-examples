#include <stdlib.h> 
#include <stdio.h> 
#include "stacks.h"

// char stack
static int N;

char *cSTACKinit(int maxn)
{
  N = 0;
  return malloc(maxn * sizeof(char));
}
int cSTACKempty(void)
{
  return N == 0;
}
void cSTACKpush(char *stack, char item)
{
  stack[++N] = item;
}
char cSTACKpop(char *stack)
{
  return stack[N--];
}

// int stack
static int M;

int *iSTACKinit(int maxn)
{
  M = 0;
  return malloc(maxn * sizeof(int));
}
int iSTACKempty(void)
{
  return M == 0;
}
void iSTACKpush(int *stack, int item)
{
  stack[++M] = item;
}
int iSTACKpop(int *stack)
{
  return stack[M--];
}

