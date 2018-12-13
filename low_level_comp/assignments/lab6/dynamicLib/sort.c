#include </home/evavw/classes/low_level_comp/assignments/lab6/staticLib/array.h>

void sort(Vector *vec){
  for(int i = 0; i <vec->count; i++){
    for(int j = 0; j < vec->count; j++){
      if(i != j && vec->vector[j] > vec->vector[i]){
        swap(vec,i,j);
      }
    }
  }
}
