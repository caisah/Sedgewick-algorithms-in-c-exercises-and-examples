#include <stdio.h>

#define N 96

int main(int argc, char *argv[]) 
{
  int i;
  char *s = argv[1], t[N], space = ' ';

  for (i = 0; i < N; i++)
    t[i] = 0;
  for (i = 0; s[i] != '\0'; i++)
    t[s[i] - space]++;
  for (i = 0; i < N; i++)
    if (t[i])
      printf("%c - %d\n", i + space, t[i]);
}
