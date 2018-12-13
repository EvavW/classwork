#include </home/evavw/classes/low_level_comp/assignments/lab6/staticLib/array.h>

void delete_vector(Vector *vec){
  if (vec->vector != NULL){
    free(vec->vector);
  }
  vec->count = 0;
  vec->length = 0;
}
