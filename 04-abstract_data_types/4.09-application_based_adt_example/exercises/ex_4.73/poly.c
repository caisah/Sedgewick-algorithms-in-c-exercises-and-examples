#include <stdlib.h>
#include <stdio.h> 
#include "poly.h"

struct poly
{
  int N;
  float *a;
};

Poly POLYterm(float coeff, int exp)
{
  int i;
  Poly t = malloc(sizeof *t);

  t->a = malloc( (exp+1)*sizeof(int));
  t->N = exp+1;
  t->a[exp] = coeff;
  for (i = 0; i < exp; i++)
    t->a[i] = 0;
  return t;
}

Poly POLYadd(Poly p, Poly q)
{
  int i;
  Poly t;

  if (p->N >= q->N)
    {
      t = POLYcopy(p);
      for (i = 0; i < q->N; i++)
	t->a[i] += q->a[i];
    }
  else
    {
      t = POLYcopy(p);
      for (i = 0; i < p->N; i++)
	t->a[i] += p->a[i];
    }
  POLYdestroy(p);
  POLYdestroy(q);  
  return t;
}

Poly POLYmult(Poly p, Poly q)
{
  int i, j;
  Poly t = POLYterm(0, (p->N-1)+(q->N-1));

  for (i = 0; i < p->N; i++)
    for (j = 0; j < q->N; j++)
      t->a[i+j] += p->a[i]*q->a[j];
  POLYdestroy(p);
  POLYdestroy(q);  
  return t;
}

float POLYeval(Poly p, float x)
{
  int i;
  double t = 0.0;

  for(i = p->N-1; i >= 0; i--)
    t = t*x + p->a[i];
  return t;
}

void POLYdestroy(Poly p)
{
  free(p->a);
  free(p);
}

Poly POLYdiff(Poly p)
{
  int i;
  Poly t = POLYcopy(p);

  for (i = 0; i < (t->N-1); i++)
    t->a[i] = t->a[i+1] * (i+1);
  t->a[t->N] = 0;
  t->N--;
  return t;
}

Poly POLYinteg(Poly p)
{
  int i;
  Poly t;

  t = malloc(sizeof(Poly));
  t->N = p->N+1;
  t->a = malloc(t->N*sizeof(int));
  for (i = 0; i < p->N; i++)
    t->a[i+1] = p->a[i] / (i+1);
  t->a[0] = 0.0;
  return t;
}

Poly POLYcopy(Poly p)
{
  Poly t;
  int i;

  t = malloc(sizeof(Poly));
  t->N = p->N;
  t->a = malloc( (t->N) * sizeof(int));
  for (i = 0; i < t->N; i++)
    t->a[i] = p->a[i];
  return t;
}

void showPOLY(Poly p)
{
  int i;
  float term;

  for (i = p->N-1; i >= 0; i--)
    if ( (term = p->a[i]) != 0)
      {
	if (i == 0)
	  {
	    if (term < 0)
	      printf("%.2f", term);
	    else if (p->N-1 == 0)
	      printf("%.2f", term);
	    else
	      printf("+%.2f", term);
	    printf("\n");
	  }
	else if (i == 1)
	  {
	    if (term < 0)
	      printf("%.2fx", term);
	    else
	      printf("+%.2fx", term);
	  }
	else if (i < (p->N-1))
	  {
	    if (term < 0)
	      printf("%.2fx^%d", term, i);
	    else
	      printf("+%.2fx^%d", term, i);
	  }
	else if (term != 1)
	  {
	    if (term < 0)
	      printf("%.2fx^%d", term, i);
	    else
	      printf("%.2fx^%d", term, i);
	  }
	else
	  {
	    if (term < 0)
	      printf("x^%d", i);
	    else
	      printf("x^%d", i);
	  }	
      }
}
