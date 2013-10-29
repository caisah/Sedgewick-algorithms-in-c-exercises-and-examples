#include <stdio.h>
#include <stdlib.h>
<<<<<<< HEAD
#include <string.h>
=======
>>>>>>> 985a012b5d2f64fad5b2637870866911a5ed1bba
#include "link.h"

/* read_multi: reads a matrix in form of a multi-list */
link **read_multi(int n)
{
  int i, j, val;
  link **t;

  printf("Enter the elements & EOF to end: ");
  t = malloc(n * sizeof(link*));
  if (t != NULL)
    {
      for (i = 0; i < n; i++)
	t[i] = NULL;
      for (i = 0, j = -1; i < n*n && (scanf("%d ", &val) != EOF); i++)
	{
	  if (((i + n) % n) == 0)
	    j++;
	  t[j] = add_elem(t[j], val);
	}
    }
  printf("\n");
  return t;
}

/* add_elem: adds element to the end of a linked list & returns the list */
link *add_elem(link *t, int val)
{
  link *new, *head = t;

  new = malloc(sizeof(link));
  if (new != NULL)
    {
      new->next = NULL;
      new->val = val;
    }
  if (t == NULL)
    return new;
  else
    {
      while(t->next != NULL)
	t = t->next;
      t->next = new;
    }
  return head;
}

/* multiply_matrices: returns the product of 2 multi-list matrixes of dimension n */
link **multiply_matrices(link **m1, link **m2, int n)
{
<<<<<<< HEAD
  int i, j=0, k, s;
  link **m, **col, *line;

  m = malloc(n * sizeof(link*));
  col = malloc(n * sizeof(link*));
=======
  int i, j, s;
  link **m, **col, *line;

  m = malloc(n * sizeof(link*));
>>>>>>> 985a012b5d2f64fad5b2637870866911a5ed1bba
  for (i = 0; i < n; i++)
    m[i] = NULL;
  for (i = 0; i < n; i++)
    {
<<<<<<< HEAD
      for (k = 0; k < n; k++)
	col[k] = m2[k];
      while (col[j] != NULL)
      	{
      	  line = m1[i];
      	  s = 0;
      	  while (line != NULL)
      	    {
      	      s += (line->val * col[j]->val);
      	      line = line->next;
      	      col[j] = col[j]->next;
      	      j++;
      	    }
      	  m[i] = add_elem(m[i], s);
      	  j = 0;
      	}
=======
      col = m2;
      while (col[j] != NULL)
	{
	  line = m1[i];
	  s = 0;
	  while (line != NULL)
	    {
	      s += (line->val * col[j]->val);
	      line = line->next;
	      col[j] = col[j]->next;
	      j++;
	    }
	  m[i] = add_elem(m[i], s);
	  j = 0;
	}
>>>>>>> 985a012b5d2f64fad5b2637870866911a5ed1bba
    }
  return m;
}

/* print_list: prints a linked list */
void print_list(link *t)
{
  while (t != NULL)
    {
      printf("%d ", t->val);
      t = t->next;
    }
  printf("\n");
}

void print_matrix(link **m, int n)
{
  int i;
  
  for (i = 0; i < n; i++)
    print_list(m[i]);
  printf("\n");
}
