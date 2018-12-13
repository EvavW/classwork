#include </home/evavw/classes/low_level_comp/assignments/lab6/staticLib/array.h>
#include<stdio.h>

Vector get_from_con(){
  Vector ret = create_vector(INIT_SIZE);
  char str[50];
  int length = 1;
  while(str[0] != '\0'){
    gets(str);
    length = strlen(str);
    if(length != 0){
      double temp = strtod(str,NULL);
      double dtemp = atof(str);
      insert(&ret,dtemp);
    }
  }
  return ret;
}
