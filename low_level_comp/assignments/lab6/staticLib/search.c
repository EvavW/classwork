#include </home/evavw/classes/low_level_comp/assignments/lab6/staticLib/array.h>

int search(Vector vec, double dbl){
  sort(&vec);
  int start =0;
  int end = vec.count-1;
  int center = vec.count/2;
  if(dbl < vec.vector[start]){
    return -1;
  }
  if(dbl > vec.vector[end]){
    return -1;
  }
  while(center>start){
    if(dbl < vec.vector[center]){
      end = center;
      center = end/2;
    }
    else if(dbl > vec.vector[center]){
      start = center;
      center = start  + (end-start)/2;
    }
    else{
      return center;
    }
    if(dbl == vec.vector[start]){
      return start;
    }
    if(dbl == vec.vector[end]){
      return end;
    }
  }
  return -1;
}
