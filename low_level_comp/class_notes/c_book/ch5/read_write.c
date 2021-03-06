#include <stdio.h>
#include <stdlib.h>

char *read(int len, char *file_name);
void write(int len, char *file_name, char *output);

int main() {

  char *input = read(0, "message_file.txt");
  printf("input = \n|%s|\n", input); // | is to handle trailing characters?
  write(0, "output_file.txt", input);

  free(input);
  input = NULL;

  return 0;
  

}

char *read(int len, char *file_name) {
FILE *fp = fopen(file_name, "r");

  if(fp == NULL) {// \0 is the null character this is the null something else?
    printf("ERROR: file not opened.\n");
    exit(1);
  }

  if(len == 0){
    while(getc(fp) != EOF){
      len++;
    }
    rewind(fp);  
    printf("len = %d\n", len);
  
  }

  char *input = (char*) malloc(len+1); // send from stack to the heap need +1 for the null

  if(input == NULL){
    printf("ERROR: file Memory not allocated.\n");
    exit(2);
  }

  int j = 0;
  for(j=0; j<len; j++){
    input[j] = getc(fp);
  }
  input[j] = '\0'; // add null character
   
  fclose(fp);

  return input;
}

void write(int len, char *file_name, char *output) {

  FILE *fp  = fopen(file_name, "w");

  if(fp == NULL){
    printf("ERROR:File not opened,\n");
    exit(1);
  }
  
  int j = 0;
  if(len == 0){
    while(output[j] != '\0'){
      putc(output[j++], fp);
    }
  }
  else {
    for(j = 0; j<len; j++){
      putc(output[j], fp);
    }
    fclose(fp);
  return;
  }
}
