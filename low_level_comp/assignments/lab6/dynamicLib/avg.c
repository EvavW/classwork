#include </home/evavw/classes/low_level_comp/assignments/lab6/staticLib/array.h>

double avg(Vector vec){
  double total = sum(vec);
  return total/vec.count;
}
