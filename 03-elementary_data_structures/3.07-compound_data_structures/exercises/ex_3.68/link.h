typedef struct node link;
struct node
{
  int val;
  link *next;
};

link **read_multi(int);
link *add_elem(link*, int);
link **multiply_matrices(link**, link**, int);
void print_list(link*);
void print_matrix(link**, int);
