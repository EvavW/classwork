#include </home/evavw/classes/low_level_comp/assignments/lab6/staticLib/array.h>

double dot(Vector v1, Vector v2){
  if(v1.count != v2.count){
    printf("Error: cannot perform dot product operation on vectors of different lenghts");
    return 0;
  }
  Vector tmp = mul(v1,v2);
  return sum(tmp);
}
