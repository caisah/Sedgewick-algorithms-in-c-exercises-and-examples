typedef struct iSTACKnode *i_link;
struct iSTACKnode 
{
  char item;
  i_link next;
};

typedef struct cSTACKnode *c_link;
struct cSTACKnode 
{
  int item;
  c_link next;
};

void cSTACKinit();
int cSTACKempty(void);
void cSTACKpush(char);
char cSTACKpop(void);

void iSTACKinit();
int iSTACKempty(void);
void iSTACKpush(int);
int iSTACKpop(void);
