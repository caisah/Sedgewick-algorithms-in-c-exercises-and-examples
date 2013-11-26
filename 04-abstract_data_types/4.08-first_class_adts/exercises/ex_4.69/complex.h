#ifndef COMPLEX_H
#define COMPLEX_H

typedef struct Complex *complex;

typedef complex Item;
complex COMPLEXinit(float, float);
float Re(complex);
float Im(complex);
complex COMPLEXmult(complex, complex);
complex COMPLEXadd(complex, complex);
void COMPLEXprint(complex);

#endif
