#include <stdio.h>
#include <math.h>

int main(void)
{
  float x, y, z;
  float angle = M_PI/4.0;
  int i,n, m;
  float t;
  float wavelen = 10;

  n = 10000;
  m = 10;

  for(t = 0; t < 2*M_PI ; t += 0.01){
    x = 0;
    y = 0;
    z = 0;
    for(i = 0; i < n; i++){
      y += 1.0/n *sin(i * 2*M_PI/n/wavelen * sin(angle) + t);
    }
    printf("%f, %f\n", t, y*y / t);
  }
  return 0;
}
