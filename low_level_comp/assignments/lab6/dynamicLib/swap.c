#include </home/evavw/classes/low_level_comp/assignments/lab6/staticLib/array.h>

void swap(Vector *vec, int i, int j){
  double temp = vec->vector[i];
  vec->vector[i] = vec->vector[j];
  vec->vector[j] = temp;
}
