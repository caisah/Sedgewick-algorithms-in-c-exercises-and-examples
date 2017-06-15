typedef struct node link;
struct node
{
  int item;
  link *next;
};

link *new_node(int);
link *new_list(void);
link *add_last(int, link*);
link *concat_lists(link*, link*);
void print_list(link*);
