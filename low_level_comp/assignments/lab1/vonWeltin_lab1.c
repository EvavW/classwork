#include<stdio.h>

/*
Lab 01 Eva von Weltin 20170909
Computer Systems and Low Level Programming
Fall 2017

this program demonstrates several functions that can be performed on strings
user is prompted to enter a string
all chars in the string are reversed
all lowercase chars in the string are made uppercase
results are printed

*/

// function prototypes
char* getString(char *str);
int length(char* str, int len);
int testCase(char letter);
char* reverseString(char *str);
char* switchCase(char *str, int len, int *uppered);
void printOutput(char *str, int len, int uppered);

int main() {
  char str[1000]; // define inital str called by reverseString
  int len = 0; // define initial int for length of the string
  int uppered = 0; // define initial int for number of chars made uppercase

  getString(str); // get user input
  len = length(str,len); // get length of the string
  char *newStr; // define new char for switchCase to 
  // call reverseString, and then call switchCase on the returned string
  newStr = switchCase(reverseString(str),len,&uppered); 
  printOutput(newStr,len,uppered); // call printoutput
  return 0;
  
} // end main

//--------------------------------------------------------------------------

char *getString(char *str){
  /*
This function gets prompts the user for input and stores it in str
  */
  
  printf("Enter a string: ");
  gets(str);
  
}// end getString

//--------------------------------------------------------------------------

int length(char* str, int len){
  /*
this function returns the length of the string str
  */

  // keep incremeting i until the end of the string is reached. iterate len
  for(int i = 0; str[i] != '\0'; i++){ 
    len ++;
   }
  return len;
}// end length

//--------------------------------------------------------------------------

int testCase(char letter){
  /*
this function tests to see if a given charcter is lowercase
return 1 = is lowercase
return 0 = is not lowercase
  */

  // all lowercase letters will either be an a or be bigger than a 
  if (letter >= 'a') {
    return 1;
  }
  else {
      return 0;
    }
}// end testCase

//--------------------------------------------------------------------------

char* reverseString(char *str){
  /*
this function takes string str and returns rev which is the reverse
  */

  static char rev[1000]; // define char array for the reversed string

  static int i = 0;
  if(*str) {
    reverseString(str+1); // call this function recursively 
    rev[i++] = *str; // add to rev
  }
  return rev;
}// end reverseString

//--------------------------------------------------------------------------

char* switchCase(char *str, int len, int *uppered){
  /* 
thsi function changes all lowercase letters in a string to uppercase.
calls testCase to check if the letter is lowercase
also increments the int uppered that counts the number of chars switched to 
uppercase.
  */

  static char newStr[1000]; // define char array for uppercase string
   
  // value of len is passed to the function from main
  for(int i = 0; i<len; i++){
    char tmp = str[i]; // tmp char array to add each switched element to newStr
    if(testCase(tmp)==1){ // call testCase
      tmp = str[i]-32; // switch to uppercase
      newStr[i] = tmp; // add to newStr
      *uppered = *uppered + 1; // increment uppered
    }
    else{
      newStr[i] = tmp; // add unchanged characters into newStr 
      }
  }
  return newStr; 
}// end switchCase

//--------------------------------------------------------------------------

void printOutput(char *str, int len, int uppered){
  /*
this function just prints the modified string newStr returned finally by 
switchCase.
chars are printed each on their own line
all reports the length of the string and the number of chars that were 
switched to uppercase
  */

  for (int i = 0; i < len; i++){
    printf("%c\n",str[i]); //print each char on its own line
  }
  printf("The string is %d chars and %d chars were capitalized.\n",len,uppered);
}// end printOutput
