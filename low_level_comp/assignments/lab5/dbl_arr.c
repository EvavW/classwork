#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dbl(int *arr, int length);

int main(){
  
  int *arr = (int*)malloc(sizeof(int)*4);
  arr[0] = 0;
  arr[1] = 1;
  arr[2] = 2;
  arr[3] = 3;
  int length = 4;

  dbl(arr,length);

}

void dbl(int *arr, int length){

  for(int i = 0; i < length; i++){
    int tmp = arr[i];
    tmp = tmp*2;
    arr[i] = tmp;
  }
}  
