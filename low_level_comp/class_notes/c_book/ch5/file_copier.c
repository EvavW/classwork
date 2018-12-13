#include <stdio.h>
#include <stdlib.h>

#define EXIT_FILE_OPEN_FAILURE 1

int main(int argc, char **argv) {

  int c;
  char input_filename[]="instuff.txt";
  char output_filename[]="outstuff.txt";
  FILE *infp;
  FILE *outfp;

  if ((infp=fopen(input_filename, "r"))==NULL) {
    printf("error opening %s for reading. Quitting.\n", input_filename);
    return EXIT_FILE_OPEN_FAILURE;
  }

  if ((outfp=fopen(output_filename, "w"))==NULL) {
    printf("error opening %s for reading. Quitting.\n", output_filename);
    return EXIT_FILE_OPEN_FAILURE;
  }

  while ((c=fgetc(infp))!=EOF) {
    fputc(c, outfp);
  }

  printf("Done\n");
  fclose(infp);
  fclose(outfp);

  return EXIT_SUCCESS;
}
