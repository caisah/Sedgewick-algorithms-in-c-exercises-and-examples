#include <stdio.h> 

int i = 0;
char *a = "((3 * 3) + (2 + 2))";

// clear_junk: skips spaces and )
void clear_junk()
{
  while ((a[i] == ' ') || (a[i] == ')'))
    i++;
}

// print_number: prints a number and clears junk before and after
void print_number()
{
  clear_junk();
  while ((a[i] >= '0') && (a[i] <= '9'))
    printf("%c", a[i++]);
  printf(" ");
  clear_junk();
}

/* print_elements: prints complex infix parenthesised expressions
                   in sufix mode */
void print_elements()
{
                                     // print first element
  if (a[i] == '(')                   // if it's complex expression
    {
      i++;
      print_elements();              // print complex expression
    }
  else                               // else
    print_number();                  // print first element of the pair

  if (a[i] == '+')                   // if sign is +
    {
      i++;
      clear_junk();
      if (a[i] == '(')               // if it's a complex expression
	{
	  i++;
	  print_elements();          // print complex expression
	}
      else
	print_number();              // print second element
      printf("+ ");                  // print + sign
    }

  if (a[i] == '*')                   // if sign is *
    {
      i++;
      clear_junk();
      if (a[i] == '(')               // if it's a complex expression
	{
	  i++;
	  print_elements();           // print complex expression
	}
      else
	print_number();              // print second element
      printf("* ");                  // print * sign
    }

}
  
int main(void) 
{
  print_elements();
  printf("\n");
  
  return 0;
}
