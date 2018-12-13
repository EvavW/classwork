/*
    In main function
    1. Read the contents of the file into a string.
    2. Convert all chars in string to lower case.
    3. Capitalize the first char in the string and
        the first non-space char after every period
        and newline.
    4. Write the processed string to a new file.

    Necessary functions
    1. Function to read a file and return an allocated string
    to main.
    2. Function to convert a string to lower case. (Hint: chars
    between A and Z)
    3. Function to convert the first char in every sentence to
    upper case. (Hint: use an int to keep track of when to
    convert the next lower case to upper case. Once at the
    beginning and after every period and after every newline.)
    4. Function to write the string to file.

    Read the pseudo-code below for more hints.
*/

// Includes and prototypes



// Main function

    // Declare string pointer and call read

    // Print string to screen to test program so far

    // Convert string to all lower case

    // Print string to screen to test program so far

    // Convert string to have a capital letter at
    // the beginning of every sentence.

    // Print string to screen to test program so far

    // Print string to file



// read_file function :Read a string from file

    // Declare iterator

    // Declare length of file int

    // Declare input data pointer

    // Open file to read

    // Check that file is open

    // Get length of file

    // Allocate memory for read string in input string

    // Check for memory allocation success

    // Rewind file to beginning

    // Loop to read all bytes from file

        // Get 1 char at a time

    // Put null at end of input string

    // Close file

    // Return input to calling function



// to_lower function: Accepts a string and converts
// all chars between A and Z to lower case

    // Declare iterator

    // Loop through string

        // If char is between A and Z

            // Convert to lower case



// to_sent_cap function: Accepts a string and converts the first char in
// each sentence to upper case

    // Int to keep track of when to convert the next int and set to 1

    // Declare iterator

    // Loop through string

        // If this char is a . or newline set period int to 1

        // If char is between a and z and last char was a . or newline

            // Convert to upper case

            // Set period/newline int to 0



// write_file function: Write a string to file

    // Declare iterator

    // Declare length and get length of string

    // Open file to write

    // Check that file is open

    // Loop to write all bytes to file

        // Write 1 char at a time

    // Close file



