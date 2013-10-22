#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Nmax 100
#define Mmax 100


int compare(const void *i, const void *j)
{
  return strcmp(*(char **)i, *(char **)j);
}

int main(void) 
{
  int i=0, N;
  char *a[Mmax], w[Nmax];

  printf("Enter a new string: ");
  while (scanf("%s", w) != EOF)
    {
      a[i] = malloc(strlen(w) * sizeof(char));
      strcpy(a[i++], w);
      printf("Enter a new string or EOF: ");
    }
  N = i;

  qsort(a, N, sizeof(char*), compare);
  for (i = 0; i < N; i++)
    printf("\n%s\n", a[i]);
  return 0;
}
