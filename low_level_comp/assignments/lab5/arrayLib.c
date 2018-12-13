/*
Eva von Weltin 11/29/2017
Computer Systems and Low Level Programming Assignment 5
This program contains functions for managing double precision data vectors
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <string.h>

#define INIT_SIZE 4
#define EPSILON 0.01

/*
    This lab requires you to write functions that manage
    and process double precision data vectors.  The includes,
    defines, Vector struct, function prototypes, skeleton
    functions and test code in main have been included to
    get you started.

    I suggest writing the functions in order
    of appearance below because some functions, either directly
    or indirectly depend on others.  You have to create a vector
    and insert elements before printing a vector.  The sum function
    can be used in avg, avg can be used in var and var in stdv.  The
    dbl_equals function should be used to compare doubles within a
    threshold to account for arithmetic precision errors on doubles.

    Make sure that you check that file open and memory allocation
    is successful before using the file or memory.  Points will be
    deducted if you code can crash in any way.  So be sure to
    consider and handle all possible threats that may crash your
    application.

    This code will be used in your final project to create static
    and dynamic libraries.

    Good luck!
*/


/*
    Struct for a vector of double.  It contains a pointer
    to a vector of double, an integer for allocated length
    of the vector and and integer for the count of double
    inserted.
*/
typedef struct{
  double *vector;
  int count;
  int length;
}Vector;


// Prototypes
Vector create_vector(int length);
Vector empty_vector();
int insert(Vector *vec, double dbl);
void print_vec(Vector vec);
void delete_vector(Vector *vec);
Vector copy(Vector vec);
Vector copy_range(Vector vec, int from, int to);
void clear_vector(Vector *vec);
void zeros(Vector *vec);
void fill(Vector *vec, double dbl);
Vector read_from_file(char *filename);
int write_to_file(Vector vec, char *filename);
Vector get_from_con();
void add_from_con(Vector *vec);
void swap(Vector *vec, int i, int j);
void sort(Vector *vec);
void reverse(Vector *vec);
int dbl_equals(double d1, double d2);
int search(Vector vec, double dbl);
double sum(Vector vec);
double avg(Vector vec);
double var(Vector vec);
double stdv(Vector vec);
Vector add(Vector v1, Vector v2);
Vector sub(Vector v1, Vector v2);
Vector mul(Vector v1, Vector v2);
Vector divv(Vector v1, Vector v2);
double dot(Vector v1, Vector v2);
int equals(Vector v1, Vector v2);


// Main
int main(){

  // Test create, insert and print
    printf("Test create, insert and print\n");
    Vector v1 = create_vector(INIT_SIZE);
    insert(&v1, 1.0);
    insert(&v1, 2.0);
    insert(&v1, 3.0);
    insert(&v1, 4.0);
    insert(&v1, 5.0);
    print_vec(v1);
    printf("\n");
    
    // Test copy and copy range
    printf("Test copy and copy range\n");
    Vector v2 = copy(v1);
    print_vec(v2);
    Vector v3 = copy_range(v1, 1, 3);
    print_vec(v3);
    printf("\n");
    
    // Test zeros and fill
    printf("Test zer3os and fill\n");
    zeros(&v3);
    print_vec(v3);
    fill(&v2, 1.0);
    print_vec(v2);
    printf("\n");
    
    // Test read and write
    printf("Test read and write\n");
    Vector v4 = read_from_file("array_in.txt");
    print_vec(v4);
    write_to_file(v1, "array_out.txt");
    printf("\n");
    
    // Test get from con and add from con
    Vector v5 = get_from_con();
    print_vec(v5);
    add_from_con(&v5);
    print_vec(v5);
    printf("\n");
    
    // Test swap, sort, reverse and search
    printf("Test swap, sort, reverse and search\n");
    swap(&v1, 0, 4);
    swap(&v1, 1, 3);
    print_vec(v1);
    sort(&v1);
    print_vec(v1);
    reverse(&v4);
    print_vec(v4);
    int i = search(v4, 6.0);
    printf("Found at %d\n\n", i);
    
    // Test sum, avg, var and stdv
    printf("Test sum, avg, var and stdv\n");
    printf("Sum = %f\n", sum(v4));
    printf("Avg = %f\n", avg(v4));
    printf("Var = %f\n", var(v4));
    printf("Stdv = %f\n\n", stdv(v4));
   
    // Test add, sub, mul, divv, dot and equals
    printf("Test add, sub, mul, divv, dot and equals\n");
    Vector v6 = add(v1, v4);
    print_vec(v6);
    Vector v7 = sub(v6, v4);
    print_vec(v7);
    Vector v8 = mul(v1, v4);
    print_vec(v8);
    Vector v9 = divv(v8, v4);
    print_vec(v9);
    double dbl = dot(v1, v4);
    printf("Dot = %f\n", dbl);
    i = equals(v1, v4);
    printf("Equals = %d\n", i);
    i = equals(v1, v1);
    printf("Equals = %d\n", i);

    // Free memory
    delete_vector(&v1);
    delete_vector(&v2);
    delete_vector(&v3);
    delete_vector(&v4);
    delete_vector(&v5);
    delete_vector(&v6);
    delete_vector(&v7);
    delete_vector(&v8);
    delete_vector(&v9);

  return 0;
}


/*
    Single vector functions
*/


/*
    Function to create a vector of double.  It accepts the
    integer length of the vector to be created and returns
    a Vector struct containing the length of the allocated
    vector, the count (initialized to zero) of doubles
    inserted, and the allocated vector.
*/
Vector create_vector(int length){
  Vector vec;
  vec.vector = (double*)malloc(sizeof(double)*length);
  if(vec.vector == NULL){
    vec.length = 0;
    vec.count = 0;
    return vec;
    //memory was not allocated
  }

  vec.count = 0;
  vec.length = length;
  return vec;
}

/*
    Create an empty vector with vector pointer set to NULL,
    length set to zero and count set to zero.  This is used
    when something fails during the creation of a Vector or
    other functions that return a Vector.
*/
Vector empty_vector(){
  Vector vec;
  vec.vector = NULL;
  vec.count = 0;
  vec.length = 0;
}

/*
    Inserts a double into a vector of double.  If the
    vector is full (i.e. count == length), the length of
    the vector should be doubled and the data from the old
    vector should be copied and the old vector freed.  If
    the length is zero, use the defined initial size.
    You can use malloc, which requires you to manually copy
    and free the old vector or try realloc.
*/
int insert(Vector *vec, double dbl){
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

/*
    Prints the count, length and elements of a vector to
    screen.
*/
void print_vec(Vector vec){
  printf("Vector: count: %d, length = %d, doubles: ",vec.count,vec.length);
  for(int i = 0; i <vec.count; i++){
    printf("%f, ",vec.vector[i]);
  }
  printf("\n");
}

/*
    Frees the memory allocated for the vector, and sets
    the count and length to zero.  Make sure not the free
    an empty (NULL) vector.
*/
void delete_vector(Vector *vec){
  if (vec->vector != NULL){
    free(vec->vector);
  }
  vec->count = 0;
  vec->length = 0;
}

/*
    Creates a new vector with equal count, length and
    elements and returns the vector.
*/
Vector copy(Vector vec){
  int length = vec.length;
  Vector tmp_vec = create_vector(length);

  for (int i = 0; i < vec.length; i++){
    insert(&tmp_vec,vec.vector[i]);
  }
  tmp_vec.length = length;
  tmp_vec.count = vec.count;

  return tmp_vec; 
}

/*
    Copies a range from a vector to a new vector and
    returns the new vector.  The count and length should
    be equal to the number of elements copied.  Remember
    to check for invalid operations:
        to less than from
        to less than zero
        from greater than or equal to count
*/
Vector copy_range(Vector vec, int from, int to){
  if(from -1 < 0){
    from = 1;
  }
  if(to -1 > vec.count){
    to = vec.count;
  }
  int length = (to-from)+1;
 
  Vector tmp_vec = create_vector(length);
  for(int i = (from-1); i <=(to-1); i++){
    insert(&tmp_vec,vec.vector[i]);
  }
  return tmp_vec; 
}

/*
    Writes zeros to the elements of a vector and sets
    the count to zero.
*/
void clear_vector(Vector *vec){

  for(int i = 0; i < vec->length; i++){
    vec->vector[i] = 0.0;
  }
  vec->count = 0;
}

/*
    Writes zeros to a vector's elements.
*/
void zeros(Vector *vec){

  for(int i = 0; i < vec->length; i++){
    vec->vector[i] = 0.0;
  }
}

/*
    Fills a vector's elements with the value in dbl.
*/
void fill(Vector *vec, double dbl){
  for(int i = 0; i < vec->length; i++){
    vec->vector[i] = dbl;
  }
}

/*
    Reads a vector from a file with one double on
    each line in the file and returns the vector.
    Remember that scanf returns a -1 after reading
    the last element in a file.
*/
Vector read_from_file(char *filename){
  
  FILE *fp = fopen(filename,"r");
  if(fp == NULL){ // if file does not exist...
    printf("ERROR: file not opened.\n");
    exit(1); // exit program with exit code 1
  }
  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  /* get the number of lines in a file */
  int lines = 0;
  int ch = 0;
  while(!feof(fp)){
    ch = fgetc(fp);
    if(ch == '\n'){
      lines++;
    }
  }
  
  rewind(fp); // go back to the beginning

  Vector ret = create_vector(lines);

  /* iterate through each line in the file and parse each line for a double */
  int i = 0;
  while((read = getline(&line,&len,fp)) != -1){
    double temp = strtod(line,NULL);
    double dtemp = atof(line);
    ret.vector[i] = dtemp;
    i++;
  }
  ret.length = lines;
  ret.count = lines;
  
  free(line);
  fclose(fp);

  return ret;
}

/*
    Writes a vector's elements to a file.
*/
int write_to_file(Vector vec, char *filename){
  FILE *fp = fopen(filename, "w");

  if(fp == NULL){// if file does not exist...
    printf("ERROR: file not opened.\n");
    exit(1); // exit program with exit code 1
  }

  for (int i = 0; i < vec.count; i++){
    putc(vec.vector[i]+'0',fp);
    putc('\n',fp);
  }
}

/*
    Creates a new vector and gets the elements from
    keyboard input.  Accepts and inserts doubles into
    the vector until Enter is pressed (without any other
    chars).  Remember that scanf will not work unless a
    required data type is entered.  You should use gets
    and check for '\0', when Enter only is pressed.
*/
Vector get_from_con(){
  Vector ret = create_vector(INIT_SIZE);
  char str[50];
  int length = 1;
  while(str[0] != '\0'){
    gets(str);
    length = strlen(str);
    if(length != 0){
      double temp = strtod(str,NULL);
      double dtemp = atof(str);
      insert(&ret,dtemp);
    }
  }
  return ret;
}

/*
    Adds elements to a vector and gets the elements from
    keyboard input.  Accepts and inserts doubles into
    the vector until Enter is pressed (without any other
    chars).  Remember that scanf will not work unless a
    required data type is entered.  You should use gets
    and check for '\0', when Enter only is pressed.
*/
void add_from_con(Vector *vec){
  //printf("test:\n");
  //print_vec(*vec);
  char str[100];
  int length = 1;
  while(str[0] != '\0'){
    gets(str);
    length = strlen(str);
    if(length != 0){
      double temp = strtod(str,NULL);
      double dtemp = atof(str);
      insert(vec,dtemp);
    }
  }
}

/*
    Swaps two elements in a vector.
*/
void swap(Vector *vec, int i, int j){
  double temp = vec->vector[i];
  vec->vector[i] = vec->vector[j];
  vec->vector[j] = temp;
}

/*
    Sorts a vector.  Can use selection or bubble
    sort.
*/
void sort(Vector *vec){
  double top = 0.0;
  for(int i = 0; i <vec->count; i++){
    for(int j = 0; j < vec->count; j++){
      if(i != j && vec->vector[j] > vec->vector[i]){
	swap(vec,i,j);
      }
    }
  }
}

/*
    Reverses the elements of a vector.
*/
void reverse(Vector *vec){
  int i = 0;
  int count = vec->count-1;
  while(count >= i){
    swap(vec,i,count);
    i++;
    count --;
  }
}

/*
    Checks if two doubles are equal given the defined
    EPSILON.  Remember that there should be a threshold
    for which two do floating point values are considered
    equal due to computation of arithmetic operations.
*/
int dbl_equals(double d1, double d2){
  if(d1-d2 < EPSILON){
    return 1;
  }
  else{
    return 0;
  }
}

/*
    Perform a binary search on a sorted vector and return
    the index of the element if found and -1 if not found.
*/
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

/*
    Calculate and return the sum of the elements in
    a vector.
*/
double sum(Vector vec){
  double sum = 0.0;
  for(int i= 0; i <vec.count; i++){
    sum = sum + vec.vector[i];
  }
  return sum;
}

/*
    Calculate and return the average of the elements in
    a vector.
*/
double avg(Vector vec){
  double total = sum(vec);
  return total/vec.count;
}

/*
    Calculate and return the variance of the elements in
    a vector.
*/
double var(Vector vec){
  double mean = avg(vec);
  double sum_square = 0.0;
  for(int i = 0; i < vec.count; i++){
    sum_square = sum_square + ((vec.vector[i]-mean)*(vec.vector[i]-mean));
  }
  double variance = sum_square/(vec.count-1);
  return variance;
}

/*
    Calculate and return the standard deviation of the
    elements in a vector.
*/
double stdv(Vector vec){
  double variance = var(vec);
  return sqrt(variance);
}


/*
    Multiple vector functions
*/


/*
    Perform an element by element addition of two vectors,
    where v3[i] = v1[i] + v2[i] and return the resulting
    vector.
*/
Vector add(Vector v1, Vector v2){
  if(v1.count != v2.count){
    return empty_vector();
  }
  int count = v1.count;
  Vector ret = create_vector(count);
  for(int i = 0; i <count; i++){
    insert(&ret,(v1.vector[i]+v2.vector[i]));
  }
  return ret;
}

/*
    Perform an element by element subtraction of one vector from
    another, where v3[i] = v1[i] - v2[i] and return the resulting
    vector.
*/
Vector sub(Vector v1, Vector v2){
  if(v1.count != v2.count){
    return empty_vector();
  }
  int count = v1.count;
  Vector ret = create_vector(count);
  for(int i = 0; i <count; i++){
    insert(&ret,(v1.vector[i]-v2.vector[i]));
  }
  return ret;
}

/*
    Perform an element by element multiplication of two vectors,
    where v3[i] = v1[i] * v2[i] and return the resulting
    vector.
*/
Vector mul(Vector v1, Vector v2){
  if(v1.count != v2.count){
    return empty_vector();
  }
  int count = v1.count;
  Vector ret = create_vector(count);
  for(int i = 0; i <count; i++){
    insert(&ret,(v1.vector[i]*v2.vector[i]));
  }
  return ret;
}

/*
    Perform an element by element division of two vectors,
    where v3[i] = v1[i] / v2[i] and return the resulting
    vector.
*/
Vector divv(Vector v1, Vector v2){
  if(v1.count != v2.count){
    return empty_vector();
  }
  int count = v1.count;
  Vector ret = create_vector(count);
  for(int i = 0; i <count; i++){
    insert(&ret,(v1.vector[i]/v2.vector[i]));
  }
  return ret;
}

/*
    Perform the calculation of the dot product of two vectors,
    where dbl += v1[i] * v2[i] and return the resulting
    double.
*/
double dot(Vector v1, Vector v2){
  if(v1.count != v2.count){
    printf("Error: cannot perform dot product operation on vectors of different lenghts");
    return 0;
  }
  Vector tmp = mul(v1,v2);
  return sum(tmp);
}

/*
    Perform an element by element comparison of two vectors.
    If for every i, v1[i] == v2[i], and the count is equal
    return 1, otherwise zero.
*/
int equals(Vector v1, Vector v2){
  if(v1.count != v2.count){
    return 0;
  }
  int count = v1.count;
  for(int i = 0; i <count; i++){
    if(v1.vector[i] != v2.vector[i]){
      return 0;
    }
  }
  return 1;
}
