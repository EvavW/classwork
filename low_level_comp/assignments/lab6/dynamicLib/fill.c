#include </home/evavw/classes/low_level_comp/assignments/lab6/staticLib/array.h>

void fill(Vector *vec, double dbl){
  for(int i = 0; i < vec->length; i++){
    vec->vector[i] = dbl;
  }
}
