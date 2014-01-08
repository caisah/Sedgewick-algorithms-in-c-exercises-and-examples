#include <stdlib.h>
#include <stdio.h> 
#include "item.h"
#include "list.h"

char a[] = "*+a**bc+def";
/*
                E
              /   \
	     /     \
            D       H
           / \     / \
          B       F
         / \     / \
        A   C       G
       / \ / \     / \

*/

void printnode(char c, int h)
{
  int i;

  for (i = 0; i < h; i++)
    printf("    ");
  printf("%c\n", c);
}

void show(link x, int h)
{
  if (x == NULL)
    {
      printnode(' ', h);
      return;
    }
  show(x->r, h+1);
  printnode(x->token, h);
  show(x->l, h+1);
}

int main(void) 
{
  link root;
  
  root = parse();
  show(root, 1);
  return 0;
}
