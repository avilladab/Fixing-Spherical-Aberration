#include <math.h>
#include <stdio.h>
#define phi ((double)(0.2))
#define Pz  ((double)(0.25))
#define NA  ((double)(1.4))
#define n1  ((double)(1.515))
#define np  ((double)(1.4987))
#define ns  ((double)(1.4893))
#define km  ((long)(100))
int main(){
  long   k;
  double d,n2;
  n2=phi*np+(1.0-phi)*ns;
  printf("Sample packing fraction = %lf\n",phi);
  printf("Sample RI = %lf\n",n2);
  printf("Oil RI = %lf\n",n1);
  printf("Non corrected Z step: Dz_mech = %lf\n",Pz);
  d=n2/n1;
  printf("\nCarlsson's correction:\n");
  printf("Dz_real = %lf\n",Pz*d);
  printf("Correction factor = %lf\n",d);
  d=tan(asin(NA/n1))/tan(asin(NA/n2));
  printf("\nVisser's correction:\n");
  printf("Dz_real = %lf\n",Pz*d);
  printf("Correction factor = %lf\n",d);
  d=0.0;
  for(k=1;k<=km;k++){
    d+=tan(asin((double)k*NA/((double)km*n1)))/tan(asin((double)k*NA/((double)km*n2)));
  }
  d/=(double)km;
  printf("\nMean correction:\n");
  printf("Dz_real = %lf\n",Pz*d);
  printf("Correction factor = %lf\n",d);
  d=tan(asin(0.5*NA/n1))/tan(asin(0.5*NA/n2));
  printf("\nMedian correction:\n");
  printf("Dz_real = %lf\n",Pz*d);
  printf("Correction factor = %lf\n",d);
  return 0;
}
