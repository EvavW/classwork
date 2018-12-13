#include <stdio.h>
#include <stdlib.h>

char *read_file(char *input_file);
void write_file(char *output_file, char *output);

int main() {

  char *input = read_file("input_file.txt");
  printf("input: \n%s\n", input);
  write_file("output_file.txt", input);

  // release input string
  free(input);
  input = NULL;

  return 0;
}// end main

char *read_file(char *input_file){

  FILE *fp = fopen(input_file, "r"); // open file for reding
  
  if(fp == NULL){ // if file does not exist...
    printf("ERROR: file not opened.\n");
    exit(1); // exit program with exit code 1
  }// end if

  // get the length of the file
  int len = 0;
  while(getc(fp) != EOF){
    len++;
  }// end while
  rewind(fp); // go back the beginning of the file

  // create space for the string in the stack. +1 for null character
  char *input = (char*) malloc(len+1); 
  if(input == NULL){
    printf("ERROR: file memory not allocateed.\n");
    exit(2); // exit program with exit code 2
  }// end if

  //populate input with the input of the file
  int i = 0;
  for(i = 0; i<len; i++){
    input[i] = getc(fp);
  }// end for
  input[i-1] = '\0'; // add null character before the last character so that the $ is excluded

  fclose(fp); // close the file

  return input;
  
}// end read_file

void write_file(char *output_file, char *output){

  FILE *fp = fopen(output_file, "w"); // open file for writing
  
  if(fp == NULL){// if file does not exist...
    printf("ERROR: file not opened.\n");
    exit(1); // exit program with exit code 1
  }// end if

  int j = 0;
  while(output[j] != '\0'){
    putc(output[j++], fp);
    }// end while

  fclose(fp);// close the file

  return;

}// end write_file
