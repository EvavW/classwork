#include<stdio.h>

int main(int argc, char *argv[]) {

  char name[50];
  int age = 0;

  // Print Hello World!
  printf("Hello World!\n");

  // get user input
  printf("Enter your name:\n");
  scanf("%s",name);
  printf("Enter your age:\n");
  scanf("%d", &age);

  printf("Hello %s your age is %d\n", name, age);

  return 0;

}
