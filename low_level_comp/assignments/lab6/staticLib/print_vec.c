#include </home/evavw/classes/low_level_comp/assignments/lab6/staticLib/array.h>

void print_vec(Vector vec){
  printf("Vector: count: %d, length = %d, doubles: ",vec.count,vec.length);
  for(int i = 0; i <vec.count; i++){
    printf("%f, ",vec.vector[i]);
  }
  printf("\n");
}
