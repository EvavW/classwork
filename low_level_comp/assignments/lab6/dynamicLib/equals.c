#include </home/evavw/classes/low_level_comp/assignments/lab6/staticLib/array.h>

int equals(Vector v1, Vector v2){
  if(v1.count != v2.count){
    return 0;
  }
  int count = v1.count;
  for(int i = 0; i <count; i++){
    if(v1.vector[i] != v2.vector[i]){
      return 0;
    }
  }
  return 1;
}
