#include </home/evavw/classes/low_level_comp/assignments/lab6/staticLib/array.h>

int dbl_equals(double d1, double d2){
  if(d1-d2 < EPSILON){
    return 1;
  }
  else{
    return 0;
  }
}
