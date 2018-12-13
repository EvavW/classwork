#include<stdio.h>

void add(int n);
void add_by_ref(int *n_p);
void print_arr(char arr);

int main(){

  int n = 5;
  int *n_p = &n; //pointer n_p is the memory address

  printf("n = %d n_p = %d *n_p = %d\n", n, n_p, *n_p);
  // n_p prints the memory address. &n_p prints the int
  n = 10;
  printf("n = %d n_p = %d *n_p = %d\n", n, n_p, *n_p);
  *n_p = 15; // changes the value of n. becuse we assigned the memory address
             // of n to *n_p. 
  printf("n = %d n_p = %d *n_p = %d\n", n, n_p, *n_p);

  n = 5;
  add(n);
  printf("added n = %d\n", n);

  n = 5;
  add_by_ref(&n);
  printf("added n = %d\n", n);

  n = 5;
  add_by_ref(n_p);
  printf("added n = %d\n", n);

  // --------------------------------------

  char a[] = "Hello";

  print_arr(a);

  return 0;

  int i = 0;
  printf("do it");
  scanf("%d",&i);
}

// passing without reference will not premanently update the int

void add(int n){
  n++;
  printf("n in func = %d\n",n);

  return;

}

// pass by reference

void add_by_ref(int *n_p){
  (*n_p)++; // put () arround *n_p because it tries to iterate before
            // incrementing
  printf("n in func = %d\n", *n_p);
  return;

}

void print_arr(char arr){
  printf("arr = %s\n",arr);
  int i = 0;
  for(i =0; i<5; i++){
    printf("arr[i] = %d\n", arr[i]);
  }
    return;
}

void strlen(char *s){

  char *p = s;

  while(*p != '\0')
    p++;
  return p-s;
}
