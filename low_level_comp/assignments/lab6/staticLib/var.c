#include </home/evavw/classes/low_level_comp/assignments/lab6/staticLib/array.h>

double var(Vector vec){
  double mean = avg(vec);
  double sum_square = 0.0;
  for(int i = 0; i < vec.count; i++){
    sum_square = sum_square + ((vec.vector[i]-mean)*(vec.vector[i]-mean));
  }
  double variance = sum_square/(vec.count-1);
  return variance;
}
