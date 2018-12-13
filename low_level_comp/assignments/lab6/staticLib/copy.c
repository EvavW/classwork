#include </home/evavw/classes/low_level_comp/assignments/lab6/staticLib/array.h>

Vector copy(Vector vec){
  int length = vec.length;
  Vector tmp_vec = create_vector(length);

  for (int i = 0; i < vec.length; i++){
    insert(&tmp_vec,vec.vector[i]);
  }
  tmp_vec.length = length;
  tmp_vec.count = vec.count;

  return tmp_vec;
}
