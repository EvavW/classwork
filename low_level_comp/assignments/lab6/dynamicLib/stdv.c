#include </home/evavw/classes/low_level_comp/assignments/lab6/staticLib/array.h>

double stdv(Vector vec){
  double variance = var(vec);
  return sqrt(variance);
}
