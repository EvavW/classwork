/*
Eva von Weltin
Computer Systems and Low Level Programming
11/8/2017
Program extracts sign, exponent, and mantissa from floating point numbers.
*/
#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <float.h>
#include <string.h>
#include <stdlib.h>

#define NORM 0
#define DNORM 1
#define SPEC 2
#define BIAS 127



/*
    Declare a "typedef struct {} flt;" to contain data for a float
    The data should include:
        An integer for the sign
            (1 for positive, -1 for negative)
        An integer for the exponent value
            (should be bit value to integer minus BIAS or -126 for denormalized)
        A float to contain the value of the mantissa
            (Actual float value extracted from the binary value)
        An integer to contain the mode using the defines above
            (NORM, DNORM and SPEC)
    Example after processing: -15.375 = 1 10000010 11101100000000000000000
        sign = -1
        exp = 3
        man = 0.9218750000
        mode = NORM
*/
typedef struct{
  int sign;
  int exp;
  float man;
  int mode;
}flt;



/*
    Write a function get_flt_bits_int to return an integer with the
    bits copied from a float.
    Example:
        for f = -15.375,
        the bits of int n = 11000001011101100000000000000000
    Look at the slides and code from the float lectures and use the
    indirection trick.  This can easily be done in one line of code.
    The function should accept a float and return an int.
*/
int get_flt_bits_int(float f){
  return *(int*)&f;
}

void print_bits(int n){

  char s[33];
  int i = 0;
  s[32] = '\0';
  for(int i = 0; i <32; i++){
    if(n&1){
      s[31-i] = '1';
    }
    else{
      s[31-i] = '0';
    }
    n = n >>1;
  }
  printf("Bits: %s\n", s);
}
/*
    Write a function that returns the sign of a float as a char.
    You should call get_flt_bits_int to get the bits in an int
    and return '1' if the sign is negative else return '0'.  The
    function should accept a float and return a string.
*/
char get_flt_sign_char(float f){
  
  int bits = get_flt_bits_int(f);
  
  int sign = bits >> 31;

  if(sign == 0){
    return '0';
  }
  else{
    return '1';
  }
}

/*
    Write a function that returns the sign of a float as an integer.
    You should call get_flt_bits_int to get the bits in an int
    and return -1 if the sign is negative else return 1.  The function
    should accept a float and return an int.
*/
int get_flt_sign_val(float f){

  int sign = get_flt_sign_char(f);

  if(sign == '0'){
    return 1;
  }

  else{
    return -1;
  }
}

/*
    Write a function to return a string containing the
    actual binary value of the exponent of a float in a
    char array.  You should call get_flt_bits_int to get
    the bits in an int and return the string.
    Example:
        for f = -15.375
            n = 11000001011101100000000000000000
            the exponent bits are "10000010"
    The function should accept a float and return a string.
*/
char* get_flt_exp_str(float f){

  unsigned int n = get_flt_bits_int(f);
  n = ((n >> 23) & 0xff);

  char *exp = (char*)malloc(9);
  exp[8] = '\0';
  // the other 8 characters a just garbage right now
  for(int i = 0; i <8; i++){
    if(n&1){
      exp[7-i] = '1';
    }
    else{
      exp[7-i] = '0';
    }
    n  = n >> 1;
  }
    return exp;
}

/*
    Write a function to return an integer containing the
    actual integer value of the exponent of a float.  You
    should call get_flt_bits_int to get the bits in an int
    and return the int with the exponent value.
    Example:
        for f = -15.375
            n = 11000001011101100000000000000000
            the exponent bits are 10000010
            the actual value of the exponent is 3
    The function should accept a float and return an int.
*/
int get_flt_exp_val(float f){
  int exp = get_flt_bits_int(f);
  
  return ((exp >>23) & 0xff) - BIAS;
}

/*
    Write a function to return an integer containing the
    mode of the exponent of a float.  You should call
    get_flt_exp_val to get the bits in an int and return
    the int with the mode value.
    Example:
        for f = -15.375
            n = 11000001011101100000000000000000
            the exponent bits are 10000010
            the mode is NORM
    The function should accept a float and return an int.
*/
int get_flt_exp_mode(float f){

  // is normal is exp is no all 1s or not all 0s

  char *exp = get_flt_exp_str(f);
  int all_1;
  int all_0;

  for(int i = 0; i <8; i++){
    if(exp[i] == 1){
      all_1 = 1;
    }
    else{
      all_1 = 0;
      break;
    }
  }
  for(int i = 0; i <8; i++){
    if(exp[i] == 0){
      all_0 = 1;
    }
    else{
      all_0 = 0;
      break;
    }
  }

  if(all_1 == 1 || all_0 == 1){
    return DNORM;
  }
  else{
    return NORM;
  }
 }

/*
    Write a function to return a string containing the
    actual binary value of the mantissa of a float in a
    char array.  You should call get_flt_bits_int to get
    the bits in an int and return the string.
    Example:
        for f = -15.375
            n = 11000001011101100000000000000000
            the mantissa bits are "11101100000000000000000"
    The function should accept a float and return a string.
*/
char* get_flt_man_str(float f){
  int n = get_flt_bits_int(f);

  n = n & ((1 << 23) -1);
  n = n << 1;

  char *man = (char*)malloc(24);
  man[24] = '\0';
  // the other 23 characters are just garbage right now
  for(int i = 0; i <24; i++){
    if(n&1){
      man[23-i] = '1';
    }
    else{
      man[23-i] = '0';
    }
    n  = n >> 1;
  }
  return man;
}

/*
    Write a function to return a float containing the
    actual float value of the mantissa of a float.  You
    should call get_flt_bits_int to get the bits in an int
    and return the int with the mantissa value.
    Example:
        for f = -15.375
            n = 11000001011101100000000000000000
            the mantissa bits are 11101100000000000000000
            the actual value of the mantissa is 0.9218750000
    The function should accept a float and return an int.
*/
float get_flt_man_val(float f){
  int man = get_flt_bits_int(f);
  float sum = 0.0;
  man <<= 9;
  int m = 2;
  for(int i = 0; i <23; i++){
    if(man & INT_MIN){
      sum += (float)1/m;
    }
    m *=2;
    man <<=1;
  }

 return sum;
}

/*
    Write a function to return a string containing the
    actual binary value of a float in a char array.  You
    should call get_flt_sign_char, get_flt_exp_str and
    get_flt_man_str to get the bits in an char and two
    strings and return the concatenated string.
    Example:
        for f = -15.375
            n = 11000001011101100000000000000000
            The sign is '1'
            the exponent is "10000010"
            and the mantissa bits are "11101100000000000000000"
            The string should be formatted as:
                "1 10000010 11101100000000000000000" to clearly
                separate the 3 parts.
    The function should accept a float and return a string.
*/
char* get_flt_bits_str(float f){
  static char bin_float[1000];

  char sign = get_flt_sign_char(f);
  
  char *exp = get_flt_exp_str(f);
  int exp_len = strlen(exp)-1;

  char *man = get_flt_man_str(f);
  int man_len = strlen(man)-1;

  bin_float[0] = sign;
  bin_float[1] = ' ';

  for(int i = 0; i <= exp_len; i++){
    bin_float[i+2] = exp[i];
  }
  bin_float[exp_len+3] = ' ';
  for(int i = 0; i <= man_len; i++){
    bin_float[i+exp_len+4] = man[i];
  }

  return bin_float;
  
}

/*
    Write a function to separate the parts of a float
    into a flt struct as described above.  You should
    call get_flt_sign_val, get_flt_exp_mode,
    get_flt_exp_val and get_flt_man_val.
    Hint:  make sure to set exponent to -126 for
    DNORM mode.
*/
void get_flt_val_flt(flt* ret, float f){
  int mode = get_flt_exp_mode(f);
  
  ret->sign = get_flt_sign_val(f);
  if(mode == 1){
    ret->exp = -126;
  }
  else{
    ret->exp = get_flt_exp_val(f);
  }
  ret->man = get_flt_man_val(f);
  ret->mode = get_flt_exp_mode(f);

}

/*
    Write a function to print a flt struct to screen.
    It should accept a flt struct and return nothing.
    Hint: Use if statement to print mode.
*/
void print_flt(flt ret){
  int mode = ret.mode;
  if(mode == 0){
     printf("sign: %d\nexp: %d\nman: %f\nmode: NORM\n",ret.sign,ret.exp,ret.man);
  }
  else{
    printf("sign: %d\nexp: %d\nman: %f\nmode: DNORM",ret.sign,ret.exp,ret.man);
  }
  
}

/*
    Write a function to get the actual float value back
    out of a flt struct.
    Hints:
        The float value produced will depend on the mode.
        To set a float to infinity use the math library constant INFINITY
        To set a float to not-a-number use the math library constant NAN
        Check the slides and text for conditions for NORN, DNORM and SPEC
        You need to return (sign) * M * 2^e
*/
float get_flt_bits_val(flt ret){
  int m = 1;
  for(int i = 1; i <=ret.exp; i++){
    m = m*2;
  }
  
  if(ret.mode == 0){
    return ret.sign * (1+ret.man) * m;
  }
  else if(ret.mode == 1){
    return ret.sign * ret.man * m;
  }
  else if(ret.man == 0 && ret.sign == -1){
    return 1 - INFINITY;
  }
  else if(ret.man == 0 && ret.sign == 1){
    return INFINITY;
  }
  else{
    return NAN;
  }
}

/*
    Write a main function that calls an prints results for
    each function when completed.

*/
int main(){
  float f = -15.375;
  printf("input flt value: %lf\n",f);
  flt ret;
  printf("sign char: %c\n",get_flt_sign_char(f));
  printf("sign val: %d\n",get_flt_sign_val(f));

  printf("exp str: %s\n",get_flt_exp_str(f));
  printf("exp val: %d\n",get_flt_exp_val(f));

  printf("man str: %s\n",get_flt_man_str(f));
  printf("man val: %f\n",get_flt_man_val(f));

  printf("float string: %s\n",get_flt_bits_str(f));

  get_flt_val_flt(&ret,f);
  print_flt(ret);
  printf("float value: %f\n",get_flt_bits_val(ret));

  return 0;
}
