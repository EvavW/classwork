#include <stdio.h>

void print_int_bits(int n);

int main(){

  int n = 0;
  print_int_bits(n);

  short sh = -1;
  int x = 0;
  x = sh;
  printf("x = %d sh = %d\n", x, sh);


  // ?????????????????? //
  /// this is going to be on the exam???
  itn *ptr = &a;
  &a = 100;
  ptr ++;
  printf("%d\n", ptr);

}

void print_int_bits(int n){
  int i = 0;
  char s[33];
  for(i = 0; i <32; i++){
    if(n&1){
      s[31-i] = '1';
    }
    else{
      s[31-i] = '0';
    }
    n >>  1;
  }
  printf("%s bits = :%s\n",s);
  
}