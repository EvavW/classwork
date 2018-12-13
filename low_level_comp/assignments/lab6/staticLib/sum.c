#include </home/evavw/classes/low_level_comp/assignments/lab6/staticLib/array.h>

double sum(Vector vec){
  double sum = 0.0;
  for(int i= 0; i <vec.count; i++){
    sum = sum + vec.vector[i];
  }
  return sum;
}
