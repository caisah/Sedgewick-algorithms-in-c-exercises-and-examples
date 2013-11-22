typedef struct Complex *complex;

complex COMPLEXinit(float, float);
float Re(complex);
float Im(complex);
complex COMPLEXmult(complex, complex);
complex COMPLEXadd(complex, complex);
