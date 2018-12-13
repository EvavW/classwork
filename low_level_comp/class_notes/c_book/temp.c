#include <stdio.h>

int main(){
int a = 10;
int b = 8;
int c = 5;
char s[] = "Aloha";
if(a > 11)
  if(b > 4)
    strcpy(s,"Hello");
  else if(b > 7)
    strcpy(s, "Hola");
  else
    strcpy(s, "Bye");

printf("%s\n", s);
}
