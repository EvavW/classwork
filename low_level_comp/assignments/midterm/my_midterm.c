#include <stdio.h>
#include <stdlib.h>

char *read_file(char *input_file, int *len);
//void write_file(char *output_file, char *output);
//int testCase(char letter);
//char *switch_case(char *str, int len);
//char *fix_special(char *switched, int len);

int main(){

  int len = 0;
  char *input = read_file("DecIndCaps.txt", len);
  /*
  printf("%s\n",input);
  char *switched = switch_case(input, len);
  char *fixed = fix_special(switched, len);
  
  write_file("output_file.txt", fixed);
  */
  free(input);
  input = NULL;
  return 0;
}
char *read_file(char *input_file, int *len){
  printf("hello");

  //open the file for reading
  FILE *fp = fopen(input_file, "r");
  if(fp==NULL){
    printf("ERROR: file not opened");
    exit(1);
  }
  //get length
  while(getc(fp) != EOF){
    *len++;
  }
  // go back to the beginning
  rewind(fp);

  //create space for string in the stack
  char *input = (char*)malloc(*len+1); // +1 for null character in linux
  if(input==NULL){
    printf("ERROR: file memory not allocated.\n");
    exit(2);
  }
  //populate input variable
  int i = 0;
  for(i = 0; i <*len; i++){
    input[i] = getc(fp);
  }
  input[i-1] = '\0'; // -1 for linux null character

  fclose(fp);
  return input;
  
}// end read_file
/*
void write_file(char *output_file, char *output){
  FILE *fp = fopen(output_file, "w");

  if(fp == NULL){
    printf("ERROR file not opened.\n");
    exit(1);
  }
  int j = 0;
  while(output[j] != '\0'){
    putc(output[j++],fp);
  }
}// end write_file

int testCase(char letter){
  if(letter >='a'){
    return 1; // is uppercase
  }
  else{
    return 0; // is lowercase
  }
}// end testCase

char *switch_case(char *str, int len){

  static char newStr[1000];
  for(int i = 0; i <len; i++){
    char tmp = str[i];
    if(testCase(tmp)==1){
      tmp = str[i]+32;// switch to lowercase
      newStr[i]=tmp;
    }
    else{
      newStr[i] = tmp;
    }
  }
  return newStr;
}// end switchcase

char *fix_special(char *switched, int len){
  int i = 0;
  static char fixed[1000];
  for (i = 0; i < len; i++){
    char tmp = switched[i];
    if(i == 0){
      tmp = switched[i]-32;
      fixed[i] = tmp;
    }/*
    else if(tmp == "."){
      tmp = switched[i]-32;
      fixed[i] = tmp;
    }
    else if(tmp == "\n"){
      tmp = switched[i]-32;
      fixed[i] = tmp;
      }*/
/*
    else{
      fixed[i] = tmp;
    }
  }
}
*/    
    
  
