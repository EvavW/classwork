# include <stdio.h>

int main() {

  int i = 0;
  double dbl = 15.5;
  do{
    if((int)dbl <= 15)
      break;
    dbl *= 2.0;
  }while(i < 3);
  printf("%.1f\n", dbl);
}
