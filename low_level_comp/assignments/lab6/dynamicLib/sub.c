#include </home/evavw/classes/low_level_comp/assignments/lab6/staticLib/array.h>

Vector sub(Vector v1, Vector v2){
  if(v1.count != v2.count){
    return empty_vector();
  }
  int count = v1.count;
  Vector ret = create_vector(count);
  for(int i = 0; i <count; i++){
    insert(&ret,(v1.vector[i]-v2.vector[i]));
  }
  return ret;
}
