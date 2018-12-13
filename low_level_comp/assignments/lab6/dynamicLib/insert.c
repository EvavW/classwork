#include </home/evavw/classes/low_level_comp/assignments/lab6/staticLib/array.h>

void insert(Vector *vec, double dbl){
  int length = 0;
  if(vec->length == 0){
    length = 4;
  }
  else{
    length = vec->length;
  }

  if (vec->count == vec->length){
    // vector is full and the length should be doubled
    double *temp = (double*)malloc(sizeof(double)*(length*2));

    if(temp == NULL){
      printf("Error: Memory not allocateed");
      return -1;
    }
    for(int i = 0; i < vec->length; i++){
      temp[i] = vec->vector[i];
    }
    vec->vector = temp;
    vec->length = length*2;
  }

  vec->vector[vec->count] = dbl;
  vec->count = vec->count+1;
}
