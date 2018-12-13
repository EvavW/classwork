
/*
Eva von Weltin
Lab2 part 2
Computer System and Low Level Programming Fall 2017
This program preforms one time pad encryption.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RAND_MAX 255
int len = 0;
// prototypes
char *read_file(int *len, char *input_file); // len is passed as a pointer to read_file
void write_file(int len, char *output_file, char *output);
void make_rand_key(int len, char *new_key); // len is passed as an integer to make_rand_key
void encrypt(char *clear_file, char *key_file, char *cipher_file);
void decrypt(char *key_file, char *cipher_file, char *clear_file);

int main() {

  // declare variables local to main for the menu.
  int choice = 0; // store user menu selection
  // strings for user inputed file names
  char clear_file[1000];
  char key_file[1000];
  char cipher_file[1000];
  char message_file[1000];

  //menu
  while (choice != 3){
    //prompt user
    printf("Menu: \n Encrypt a file: 1\n Decrpt a file: 2\n Exit: 3\n");
    scanf("%d",&choice);
    if (choice == 1){
      //get the names of the files
      printf("Enter the name of the clear text file\n");
      scanf("%s",clear_file);
      printf("Enter the name of the key file\n");
      scanf("%s",key_file);
      printf("Enter the name of the cipher file\n");
      scanf("%s",cipher_file);
      // encrpyt the clear text file
      encrypt(clear_file,key_file,cipher_file);
    }// end if
    else if (choice == 2){
      // get the name of the message file
      printf("Enter the name of the message file\n");
      scanf("%s",message_file);
      // decrpyt the clear text file into the message file
      decrypt(key_file,cipher_file,message_file);
    }// end if
  }// end while
  printf("Bye\n");

  return 0;
}// end main

char *read_file(int *len, char *input_file){
  
  FILE *fp = fopen(input_file, "r"); // open file for reding
  
  if(fp == NULL){ // if file does not exist...
    printf("ERROR: file not opened.\n");
    exit(1); // exit program with exit code 1
  }// end if

  if ( *len == 0){
    // get the length of the file
    while(getc(fp) != EOF){
      *len = *len + 1;
    }// end while
    rewind(fp); // go back the beginning of the file
  }// end if 

  // create space for the string in the stack. +1 for null character
  char *input = (char*) malloc(*len+1); 
  if(input == NULL){
    printf("ERROR: file memory not allocateed.\n");
    exit(2); // exit program with exit code 2
  }// end if
  //populate input with the input of the file
  int i = 0;
  for(i = 0; i<*len; i++){
    input[i] = getc(fp);
  }// end for
  input[i-1] = '\0'; // add null character before the last character so that the $ is excluded

  fclose(fp); // close the file

  return input;
  
}// end read_file

void write_file(int len, char *output_file, char *output){

  FILE *fp = fopen(output_file, "w"); // open file for writing
  
  if(fp == NULL){// if file does not exist...
    printf("ERROR: file not opened.\n");
    exit(1); // exit program with exit code 1
  }// end if

  if (len == 0){
    int j = 0;
    while(output[j] != '\0'){
      putc(output[j++], fp);
    }// end while
  }// end if
  else {
    for (int i = 0; i <len; i++){
      putc(output[i], fp);
    }// end while
  }// end if
  fclose(fp);// close the file

  return;

}// end write_file

void make_rand_key(int len, char *new_key){

 srand(time(NULL)); // seed the rand function

  for (int i = 0; i <len; i++){
    int r = rand() % RAND_MAX;
    if (r == 0){
      r = r+1;
    }// end if
    new_key[i] = (char) r;
  }// end for
  int temp = 0;
  int j = 0;
  for(int j = 0; new_key[j] != '\0'; j++){
    temp++;
  }// end for

  return;

}// end make_rand

void encrypt(char *clear_file, char *key_file, char *cipher_file){
  
  // read_file wil return the content of the clear text file and will update len
  char *input = read_file(&len,"clear_file.txt");
  
  char key[len]; // create char array for the key of length len
  make_rand_key(len,key); // populate key with random chars
  write_file(len,key_file,key); // write key to key_file

  char cipher[len]; //  create char array for the cipher of length len
  for(int i = 0; i < len; i++){
    // perform exclusive or operation to create the cipher key
    cipher[i] = input[i]^key[i];
  }
  write_file(len,cipher_file,cipher); // write the ciper to cipher_file

  // housekeeping
  free(input);
  input = NULL;

  return;
 
}// end encrypt

void decrypt(char *key_file, char *cipher_file, char *message_file){

  
  char *key = read_file(&len,"key_file.txt"); // read the random key into key
  char *cipher = read_file(&len,"cipher_file.txt"); // read the cipher text into cipher
  
  
  char message[len]; // create char array for the message of length len
  for(int j = 0; j < len; j++){
    // perform exclusive or operation to create decrpt the message
    message[j] = cipher[j]^key[j];
  }
  write_file(len,message_file,message); // write the message to message_file

  return;

}// end decrypt
