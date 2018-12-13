#include </home/evavw/classes/low_level_comp/assignments/lab6/staticLib/array.h>

void zeros(Vector *vec){

  for(int i = 0; i < vec->length; i++){
    vec->vector[i] = 0.0;
  }
}
