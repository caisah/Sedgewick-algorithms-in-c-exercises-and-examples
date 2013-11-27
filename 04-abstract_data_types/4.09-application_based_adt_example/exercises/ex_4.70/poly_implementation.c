#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "poly.h"

// define link type
typedef struct node *link;
struct node
{
  int coef;
  int exp;
  link next;
  link prev;
};

// poly type
struct poly
{
  link head;
  link tail;
};

link new(link prev, link next, int coef, int exp)
{
  link t = malloc(sizeof(link));

  t->next = next;
  t->prev = prev;
  t->coef = coef;
  t->exp = exp;
  return t;
}

Poly POLYterm(int coef, int exp)
{ 
  link t = new(NULL, NULL, coef, exp);
  Poly p = malloc(sizeof(Poly));

  p->head = (p->tail = t);
  return p;
}

Poly POLYadd(Poly p, Poly q)
{
  Poly t;
  link hp = p->head, hq= q->head, term;

  // insert first element
  if (hp->exp == hq->exp)
    {
      t = POLYterm( (hp->coef+hq->coef), hp->exp);
      hp = hp->next;
      hq = hq->next;
    }
  else if (hp->exp > hq->exp)
    {
      t = POLYterm(hp->coef, hp->exp);
      hp = hp->next;
    }
  else
    {
      t = POLYterm(hq->coef, hq->exp);
      hq = hq->next;
    }
  term = t->head;
  // add the rest of the lists
  while ((hp != NULL) || (hq != NULL))
    {
      // if p gets to the end add the rest of the elements to t
      if (hp == NULL)
	{
	while (hq != NULL)
	  {
	    term->next = new(term, NULL, hq->coef, hq->exp);
	    term = term->next;
	    hq = hq->next;
	  }
	t->tail = term;
	return t;
	}
      // if q gets to the end add the rest of the elements to t 
      if (hq == NULL)
	{
	while(hp != NULL)
	  {
	    term->next = new(term, NULL, hp->coef, hp->exp);
	    term = term->next;
	    hp = hp->next;
	  }
	t->tail = term;
	return t;
	}
      // if they have the same exponent, add
      if (hp->exp == hq->exp)
	{
	  term->next = new(term, NULL, (hp->coef+hq->coef), hp->exp);
	  term = term->next;
	  hp = hp->next;
	  hq = hq->next;
	}
      // if p expoenent is greater, add
      else if (hp->exp > hq->exp)
	{
	  term->next = new(term, NULL, hp->coef, hp->exp);
	  term = term->next;
	  hp = hp->next;
	}
      // if q exponent is greater, add
      else
	{
	  term->next = new(term, NULL, hq->coef, hq->exp);
	  term = term->next;
	  hq = hq->next;
	}
    }
  t->tail = term;
  return t;
}

Poly POLYmult(Poly p, Poly q)
{
  int coef, exp;
  link hp = p->head, hq = q->head;
  Poly res = POLYterm(1, 0);
  
  while (hp != NULL)
    {
      while (hq != NULL)
	{
	  coef = hp->coef * hq->coef;
	  exp = hp->exp + hq->exp;
	  res = POLYadd(res, POLYterm(coef, exp));
	  hq = hq->next;
	}
      hp = hp->next;
      hq = q->head;
    }
  return POLYadd(res, POLYterm(-1, 0));
}

float POLYeval(Poly p, float x)
{
  link t = p->head;
  double res = 0.0;

  while (t != NULL)
    {
      res = res + t->coef * pow(x, t->exp);
      t = t->next;
    }
  return res;
}

void showPOLY(Poly p)
{
  link h = p->head;

  if (h->exp == 0)
    printf("%d", h->coef);
  else if (h->exp == 1)
    {
      if (h->coef == 1)
  	printf("x");
      else
      printf("%dx", h->coef);
    }
  else if (h->coef == 1)
    printf("x^%d", h->exp);
  else
    printf("%dx^%d", h->coef, h->exp);
  h = h->next;
  while (h != NULL)
    {
      if (h->coef < 0)
  	printf("%dx^%d",h->coef, h->exp);
      else if (h->exp == 1)
  	{
  	  if (h->coef == 1)
  	    printf("+x");
  	  else
  	    printf("+%dx", h->coef);
  	}
      else if (h->exp == 0)
  	printf("+%d", h->coef);
      else
  	printf("+%dx^%d", h->coef, h->exp);
      h = h->next;
    }
  printf("\n");
}
