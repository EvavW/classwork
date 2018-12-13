#include <stdio.h>

int main() {

  int n = 0;
  printf("There %s %d %s\n", (n==1) ? "is" : "are",
	 n, (n==1) ? "box" : "boxes");

}
