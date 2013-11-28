#ifndef POLY_H
#define POLY_H

typedef struct poly *Poly;
void showPOLY(Poly);
Poly POLYterm(int, int);
Poly POLYadd(Poly, Poly);
Poly POLYmult(Poly, Poly);
float POLYeval(Poly, float);
Poly POLYcpy(Poly);

#endif
