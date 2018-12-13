/*
  Eva von Weltin
  Computer systems and Low Level Programming
  10/21/2017

    Number converter

    Menu
    Convert between integer, binary, octal and hexadecimal

    This program should accept numeric values in hexadecimal,
    decimal, octal and binary formats as:

        Hex 0x0 to 0xFFFFFFFF
        Dec 0 to 4294967295
        Oct o0 to o37777777777
        Bin b0 to b11111111111111111111111111111111

    After a value is input the code in main will interpret the
    data types above and process the conversion to an unsigned
    int.  The unsigned int will be used to convert the input to
    strings containing hexadecimal, octal and binary strings.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h> 


//int input_to_decimal(char *input);
unsigned int bin_to_uint(char *input);
unsigned int oct_to_uint(char *input);
unsigned int hex_to_uint(char *input);
unsigned int dec_to_uint(char *input);
void uint_to_hex(unsigned int n, char *output);
void uint_to_oct(unsigned int n, char *output);
void uint_to_bin(unsigned int n, char *output);


int error = 0;


int main(){

    char input[50];
    unsigned int n = 0;
    char output[50];

    // Write code here to test your functions
    // Uncomment code below when done

    printf("Enter a binary, octal, decimal or hexadecimal number\n");
    printf("convert > ");
    gets(input);
    // Detect input data type
    // Hexadecimal
    if(input[0] == '0' && input[1] == 'x'){
        n = hex_to_uint(input);
    }
    // Decimal
    else if(input[0] >= '0' && input[0] <= '9'){
        n = dec_to_uint(input);
    }
     
    // Octal
    else if(input[0] == 'o'){
        n = oct_to_uint(input);
    }
    
    // Binary
    else if(input[0] == 'b'){
        n = bin_to_uint(input);
    }
    // Unknown
    else{
        printf("ERROR: Unknown data type: %s\n", input);
    }

    // Print results
    printf("The decimal value of %s is %u\n", input, n);
    uint_to_hex(n, output);
    printf("The hexadecimal value of %s is %s\n", input, output);
    uint_to_oct(n, output);
    printf("The octal value of %s is %s\n", input, output);
    uint_to_bin(n, output);
    printf("The binary value of %s is %s\n", input, output);

    return 0;
}

// Convert a hexadecimal char array to uint
unsigned int hex_to_uint(char *input){
    // Declare result and set to zero
    unsigned int res = 0;
    // Declare and set multiplier to 1
    int multi = 1;
    // Loop through value part of input string
    for(int i = 2; i<=(strlen(input)-1);i++){
      int val = input[i] - '0';
	
      if(i == (strlen(input)-1)){
	multi = 1;
      }
      else{
	multi = 1;
	for(int pos =1; pos <=((strlen(input)-1)-i); pos++){
	  multi = multi *16;
	}
      }
        // If between 0 and 9 add 0 to 9 to res with multiplier
      if(val >=0 && val <= 9){
	res = res + (val*multi);	
      }
      // If between A and F add 10 to 15 to res with multiplier
      else if(val >= 17 && val <= 22){
	val = val -7; // convert from letter representation
	res = res + (val*multi);
      }
        // Error - exit
      else{
	printf("Error: Hexadecimal numbers should be between 0 and F.\n");
	exit(0);
      }
    }
    return res;
}

// Convert a unsigned integer char array to uint
unsigned int dec_to_uint(char *input){
    // Declare result and set to zero
    unsigned int res = 0;
    // Declare and set multiplier to 1
    int multi = 1;
    // Loop through value part of input string
    for(int i = 0; i<=(strlen(input)-1);i++){
      int val = input[i] - '0';
	
      if(i == (strlen(input)-1)){
	multi = 1;
      }
      else{
	multi = 1;
	for(int pos =1; pos <=((strlen(input)-1)-i); pos++){
	  multi = multi *10;
	}
      }
        // If between 0 and 9 add 0 to 9 to res with multiplier
      if(val >=0 && val <= 9){
	res = res + (val*multi);
      }
      // Error - exit       
      else{
	printf("Error: Decimal numbers should be between 0 and 9\n");
	exit(0);
      }
    }
    return res;
}

// Convert a octal char array to uint
unsigned int oct_to_uint(char *input){
    // Declare result and set to zero
    unsigned int res = 0;
    // Declare and set multiplier to 1
    int multi = 1;
    // Loop through value part of input string
    for(int i = 1; i<=(strlen(input)-1);i++){
      int val = input[i] - '0';
	
      if(i == (strlen(input)-1)){
	multi = 1;
      }
      else{
	multi = 1;
	for(int pos =1; pos <=((strlen(input)-1)-i); pos++){
	  multi = multi *8;
	}
      }
        // If between 0 and 7 add 0 to 7 to res with multiplier
      if(val >=0 && val <= 7){
	res = res + (val*multi);
      }
        // Error - exit  
      else{
	printf("Error: octal values should be between 0 and 7\n");
	exit(0);
      }
    }
    return res;
    }

// Convert a binary char array to unsigned int
unsigned int bin_to_uint(char *input){
     // Declare result and set to zero
    unsigned int res = 0;
    // Declare and set multiplier to 1
    int multi = 1;
    // Loop through value part of input string
    for(int i = 1; i<=(strlen(input)-1);i++){
      int val = input[i] - '0';
	
      if(i == (strlen(input)-1)){
	multi = 1;
      }
      else{
	multi = 1;
	for(int pos =1; pos <=((strlen(input)-1)-i); pos++){
	  multi = multi *2;
	}
      }
        // If between 0 and 7 add 0 to 1 to res with multiplier
      if(val >=0 && val <= 1){
	res = res + (val*multi);
      }
        // Error - exit
      else{
	printf(" Error: binary numbers should be between 0 and 1\n");
	exit(0);
      }
    }
    return res;
}

// Convert a unsigned integer char array to hexadecimal
void uint_to_hex(unsigned int n, char *output){
    // Declare a uint for remainder
  unsigned int rem = 0;
   // Declare an int for division
  int den = 16;
   // Declare a char array buffer
  static char buffer[1000];
   // Use a loop to generate a hex string - string will be reverse
  int res;
  int i = 0;
  while(n >=1){
    res = n/den;
    rem = n%den;
    n = res;
    if(rem >= 10 ){
      rem = rem +7; // convert to letter representation
    }
    char c = rem + '0';
    buffer[i] = c;
    i++;
  }
    // Put null at end of buffer
  buffer[(strlen(buffer))] = '\0';
    // Copy 0x to output string
  output[0] = '0';
  output[1] = 'x';
  // Copy chars from buffer in reverse order to output string
  for(int i = 2; i <=(strlen(buffer)+2); i ++){
    output[i] = buffer[strlen(buffer)-(i-1)];
  }
    return;
}

// Convert a unsigned integer char array to octal
void uint_to_oct(unsigned int n, char *output){
   // Declare a uint for remainder
  unsigned int rem = 0;
   // Declare an int for division
  int den = 8;
   // Declare a char array buffer
  static char buffer[1000];
   // Use a loop to generate a hex string - string will be reverse
  int res;
  int i = 0;
  while(n >=1){
    res = n/den;
    rem = n%den;
    n = res;
    char c = rem + '0';
    buffer[i] = c;
    i++;
  }
    // Put null at end of buffer
  buffer[(strlen(buffer))] = '\0';
    // Copy 0x to output string
  output[0] = 'o';
  // Copy chars from buffer in reverse order to output string
  for(int i = 1; i <=(strlen(buffer)+1); i ++){
    output[i] = buffer[strlen(buffer)-i];
  }
    return;
}

// Convert a unsigned integer char array to binary
void uint_to_bin(unsigned int n, char *output){
   // Declare a uint for remainder
  unsigned int rem = 0;
   // Declare an int for division
  int den = 2;
   // Declare a char array buffer
  static char buffer[1000];
   // Use a loop to generate a binary string - string will be reverse
  int res;
  int i = 0;
  while(n >=1){
    res = n/den;
    rem = n%den;
    n = res;
    char c = rem + '0';
    buffer[i] = c;
    i++;
  }
    // Put null at end of buffer
  buffer[(strlen(buffer))] = '\0';
    // Copy b to output string
  output[0] = 'b';
  // Copy chars from buffer in reverse order to output string
  for(int i = 1; i <=(strlen(buffer)+1); i ++){
    output[i] = buffer[strlen(buffer)-i];
  }
    return;
}

