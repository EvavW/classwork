#include </home/evavw/classes/low_level_comp/assignments/lab6/staticLib/array.h>

void add_from_con(Vector *vec){
  //printf("test:\n");
  //print_vec(*vec);
  char str[100];
  int length = 1;
  while(str[0] != '\0'){
    gets(str);
    length = strlen(str);
    if(length != 0){
      //      double temp = strtod(str,NULL);
      double dtemp = atof(str);
      insert(vec,dtemp);
    }
  }
}
