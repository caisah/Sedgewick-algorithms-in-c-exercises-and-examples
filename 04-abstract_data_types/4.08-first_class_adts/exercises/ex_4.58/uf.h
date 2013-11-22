typedef struct UF *uf;

uf UFinit(int);
int find(uf, int);
int UFfind(uf, int, int);
void UFunion(uf, int, int);
