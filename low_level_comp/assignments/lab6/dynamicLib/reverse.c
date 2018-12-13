#include </home/evavw/classes/low_level_comp/assignments/lab6/staticLib/array.h>

void reverse(Vector *vec){
  int i = 0;
  int count = vec->count-1;
  while(count >= i){
    swap(vec,i,count);
    i++;
    count --;
  }
}
