#include </home/evavw/classes/low_level_comp/assignments/lab6/staticLib/array.h>

void write_to_file(Vector vec, char *filename){
  FILE *fp = fopen(filename, "w");

  if(fp == NULL){// if file does not exist...
    printf("ERROR: file not opened.\n");
    exit(1); // exit program with exit code 1
  }

  for (int i = 0; i < vec.count; i++){
    putc(vec.vector[i]+'0',fp);
    putc('\n',fp);
  }
}
