#include<stdio.h>

const double pi = 3.14159; /* define a global varibale */ /* const makes it a constant variable */
/* local variables will always have preference over global versions */
void printSomething(); /*tells the compiler to expect this function somewhere */
/* callsed a function prototype */
int add(int n, int m); /* another prototype */
void add2(int n, int m, int *x);

int main() {

  double pi = 3.142;
  printf("pi = %f\n", pi); /* to demostate the scope of a variable */

  printSomething(); /* evoke printSomething function */

  int n = 2;
  printf("add = %d m = %d\n", add(n,3), n); /* evoke add function */
  n = add(4,5);
  printf("n = %d\n", n);

  add2(3, 4, &n); /* pass the address of n by using &n */
  printf("n = %d\m", n);
  
}
/*-------------------------------------*/
void printSomething() { /* void means that you don't wan't to return anything? */

  printf("Something\n");

}
/*---------------------------------------*/
int add(int n, int m) {
  n=1;
  return n + m;

    }
/*----------------------------------------*/
void add2(int n, int m, int *x){ /* expect to recieve a pointer to an integer (called passing by reference) */

  *x = n + m; /* pass by address function */
  return;

}
