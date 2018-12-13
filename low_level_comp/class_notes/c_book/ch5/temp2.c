# include <stdio.h>

int main() {

  int a = 10;
  int b = 4;
  int c = 5;
  char s[] = "Hello";
  if(a > 11)
    if(b > 4)
      strcpy(s,"Aloha");
    else
      strcpy(s, "Bye");

  printf("%s\n", s);
  
}
