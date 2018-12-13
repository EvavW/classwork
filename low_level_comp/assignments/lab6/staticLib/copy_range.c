#include </home/evavw/classes/low_level_comp/assignments/lab6/staticLib/array.h>

Vector copy_range(Vector vec, int from, int to){
  if(from -1 < 0){
    from = 1;
  }
  if(to -1 > vec.count){
    to = vec.count;
  }
  int length = (to-from)+1;

  Vector tmp_vec = create_vector(length);
  for(int i = (from-1); i <=(to-1); i++){
    insert(&tmp_vec,vec.vector[i]);
  }
  return tmp_vec;
}
