#include<stdio.h>

void static_examples();

int main() {

  static int sta_var = 0;
  // static restricts the use of a variable to the file that it is declared in
  //LOOK UP HEADER FILES

  register int reg_int = 0;
  printf("reg_int = %d\n", reg_int());
  reg_int++;
  printf("reg_int = %d\n", reg_int());
  // register the int in the main? processeor so it doesnt have to be pulled from RAM. makes accessing the variable faster. 
	 
}

void static_example(){

  static int sta_var;

  sta_var++;

  // every time you call the function it will remember that the static variable was called
  // useful for recursion

}
