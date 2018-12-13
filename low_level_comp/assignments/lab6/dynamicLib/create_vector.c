#include </home/evavw/classes/low_level_comp/assignments/lab6/staticLib/array.h>

Vector create_vector(int length){
  Vector vec;
  vec.vector = (double*)malloc(sizeof(double)*length);
  if(vec.vector == NULL){
    vec.length = 0;
    vec.count = 0;
    return vec;
    //memory was not allocated
  }

  vec.count = 0;
  vec.length = length;
  return vec;
}
