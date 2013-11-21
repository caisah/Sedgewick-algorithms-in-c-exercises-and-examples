typedef struct
{
  float Re;
  float Im;
} complex;

complex COMPLEXinit(float, float);
float Re(complex);
float Im(complex);
complex COMPLEXmult(complex, complex);
