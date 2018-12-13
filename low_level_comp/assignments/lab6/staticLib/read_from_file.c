#include </home/evavw/classes/low_level_comp/assignments/lab6/staticLib/array.h>

Vector read_from_file(char *filename){

  FILE *fp = fopen(filename,"r");
  if(fp == NULL){ // if file does not exist...
    printf("ERROR: file not opened.\n");
    exit(1); // exit program with exit code 1
  }
  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  /* get the number of lines in a file */
  int lines = 0;
  int ch = 0;
  while(!feof(fp)){
    ch = fgetc(fp);
    if(ch == '\n'){
      lines++;
    }
  }

  rewind(fp); // go back to the beginning

  Vector ret = create_vector(lines);

  /* iterate through each line in the file and parse each line for a double */
  int i = 0;
  while((read = getline(&line,&len,fp)) != -1){
    double temp = strtod(line,NULL);
    double dtemp = atof(line);
    ret.vector[i] = dtemp;
    i++;
  }
  ret.length = lines;
  ret.count = lines;

  free(line);
  fclose(fp);

  return ret;
}
