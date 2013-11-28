#ifndef POLY_H
#define POLY_H

typedef struct poly *Poly;
void showPOLY(Poly);
Poly POLYterm(float, int);
Poly POLYadd(Poly, Poly);
Poly POLYmult(Poly, Poly);
Poly POLYdiff(Poly);
Poly POLYinteg(Poly);
float POLYeval(Poly, float);
Poly POLYcopy(Poly);
void POLYdestroy(Poly);

#endif
