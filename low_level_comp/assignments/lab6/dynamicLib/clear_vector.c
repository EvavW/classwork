#include </home/evavw/classes/low_level_comp/assignments/lab6/staticLib/array.h>

void clear_vector(Vector *vec){

  for(int i = 0; i < vec->length; i++){
    vec->vector[i] = 0.0;
  }
  vec->count = 0;
}
