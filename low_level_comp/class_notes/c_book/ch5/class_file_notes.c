// Includes functions in stdio or standard input/output
#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <string.h>
#include <stdarg.h>


// Prototypes
void menu();
double average(int num, ...);
void minprintf(char *fmt, ...);


int main(){

    // Menus
    /*
        Menus allow users to choose between a number of operations
        to be performed by the program.  Look at the menu function
        below to see an example of a menu.
    */
    menu();


    // Standard Input and Output
    /*
        When getting input from the keyboard or a file, or putting
        output to the screen or a file, data streams are used.  stdin
        is the standard or keyboard input data stream.  When the program
        waits for input on stdin, all the keys of the keyboard that are
        pressed are copied to an area in RAM.  When the keyboard operation
        is complete the data are copied to their destination (typically a
        variable).  stdout is the standard or screen output data stream.
        When the stdout data stream is used, the output are sent to a buffer
        and then to the screen.  Files will be discussed below.

        Using the < symbol, as in <infile, redirects stdin to read from a
        file.  All functions that use stdin will read from the file input
        instead of the keyboard.  Using the > symbol, as in >output, redirects
        all functions that use stdout to write to file output.
    */
    // Prompt user to enter a char
    printf("Enter a char: ");
    // Clear all data from input data stream
    fflush(stdin);
    // Get char c from stdin -> keyboard
    char c = getc(stdin);
    // Print message
    printf("You entered: ");
    // Put char c to stdout -> to screen
    putc(c, stdout);
    printf("\n\n");


    // Formatted Output – printf()
    /*
        The printf function is used to print formatted output to stdout.
        The first example shows printing the string literal "Print Something"
        and a newline to stdin.  The second example shows some declared and
        initialized data, and a call to printf to print the data.  The first
        part of the printf arguments, in quotes, is the pattern string.  It
        contains string literals, placeholders and escape sequences.  The %d
        is a placeholder for an integer value.  The %.1f is a placeholder for
        a double or float value that prints only 1 digit of precision.  %f alone
        will print with 6 digits of precision by default.  Putting .1 between
        the % and the f forces printf to only print 1.  The %c is a placeholder
        for a char and %s is a placeholder for a string of chars.  The \n is
        an escape sequence.  These are used to print characters or instructions
        that are not available as keyboard characters or are reserved symbols.
        \n advances the output to the next line.  Other usefil escape sequences
        are:
            \t moves to the next tab-stop
            \r moves to the beginning of a line
            \\ prints a \
            \' prints '
            \" prints "
            \? prints ?
            %% prints % (This ones different but needed to print %)
        The arguments after the pattern string are the data to be printed
        for each placeholder. they must match the order and data types of
        the placeholders in the pattern string or the output will not be
        correct.
    */
    // Example 1
    printf("Printing something\n");
    // Example 2
    int i = 102;
    double d = 34.56;
    c = 'A';  // Declared previously
    char s[] = "Hello World!";
    printf("i = %d d = %.1f c = %c s = %s\n\n", i, d, c, s);


    // Variable-length Argument Lists
    /*
        Notice that printf can accept a variable number of arguments.
        To write a function that accepts a variable number of arguments,
        use the ... operator as shown in the average() and minprintf()
        examples below.  Please read through the comments in the code
        for a step-by-step description.  I also modified the code so
        that it should run on the lab computers.  The #include <stdarg.h>
        in the preprocessor statements includes data and functions to
        include a variable number of arguments in functions.
    */
    // Call average() 3 times
    double a3 = average(3, 1.0, 2.0, 3.0);
    double a4 = average(4, 1.0, 2.0, 3.0, 4.0);
    double a5 = average(5, 1.0, 2.0, 3.0, 4.0, 5.0);
    // Print average() results
    printf("a3 = %.2f a4 = %.2f a5 = %.2f\n", a3, a4, a5);
    // Call minprintf() example from book
    minprintf("i = %d d = %f s = %s\n\n", i, d, s);


    // Formatted Input – scanf()
    /*
        Data from specific types can be read from the command line
        using scanf.  As with printf, scanf can accept a variable
        number of arguments.  It has a pattern string that should
        only contain placeholders to specify the input data types.
        The primitive data types must be references or addresses of
        that data variable to receive the data.  This is done by
        preceding each with the address of operator &.  Since strings
        are passed by reference, no & is necessary.
    */
    printf("Enter an int: ");
    scanf("%d", &i);
    printf("You entered %d\n", i);
    printf("Enter an int, a double, a char and a string: ");
    scanf("%d %lf %c %s", &i, &d, &c, s);
    printf("i = %d d = %.1f c = %c s = %s\n\n", i, d, c, s);


    // File Access
    /*
        C has data structures and functions to facilitate file
        reading and writing.  To read or write a file, a file pointer
        structure must be declared.
    */
    // Declare a file pointer
    FILE *fp;
    // Open a file for reading
    fp = fopen("message_file.txt", "r");
    // File read buffer
    char buffer[200];
    if(fp != NULL){
        // Use fscanf to read a file - only reads to a space, tab or newline
        fscanf(fp, "%s", buffer);
        printf("%s\n", buffer);
        // Read and print a line
        fgets(buffer, 200, fp);
        printf("%s\n", buffer);

        // Rewind to beginning of file
        rewind(fp);
        // Read file and write contents to screen
        printf("\n");
        while(fgets(buffer, 200, fp) != NULL){
            printf("%s\n", buffer);
        }

        // Rewind to beginning of file again
        rewind(fp);
        // Read file and write contents to screen removing newlines from buffer
        printf("\n");
        while(fgets(buffer, 200, fp) != NULL){
            buffer[strlen(buffer)-1] = '\0'; // Write \0 over \n
            printf("%s\n", buffer);
        }

        // Rewind to beginning of file again
        rewind(fp);
        // Can also read a whole file to a string
        int pos = 0; // To keep position in buffer
        // Loop until EOF read from file - copy chars read to buffer
        printf("\n");
        // Note the ; - no loop body - all work is done in condition to stop loop
        while((buffer[pos++] = getc(fp)) != EOF);
        buffer[pos] = '\0'; // Put a null at end of buffer
        printf("%s\n\n", buffer);

        // Close file when done reading
        fclose(fp);
    }
    // File not opened - error
    else{
        printf("File not opened.\n");
    }

    // Open a file for writing
    fp = fopen("output_file.txt", "w");
    // String to write to file
    char str[] = "This is a line.";
    // Int to write to file
    int n = 100;
    float f = 4.5;

    if(fp != NULL){
        // use fprintf to write data to file
        fprintf(fp, "This is an output file\n");
        fprintf(fp, "%s\n", str);
        fprintf(fp, "n = %d f = %1.2f\n", n, f);
        // Use putc to write char data to file
        int j = 0;
        while(str[j] != '\0'){
            putc(str[j++], fp);
            putc('\n', fp);
        }

        // Can also write a whole string to file like this
        fputs(str, fp);

        // Close file when done writing
        fclose(fp);
    }
    // File not opened - error
    else{
        printf("File not opened.\n");
    }


    // Error Handling – stderr and exit()
    /*
        The stderr data stream can be used to print error messages if an
        error occurs during a programs execution.  If a file open fails,
        a NULL pointer is returned.  An error message should be written and
        the program should exit if the error is likely to cause problems
        with subsequent code.  The exit() function ends a program.  exit(1)
        returns an error code 1.  When a program returns a 0, it usually
        means that it ran successfully.
    */
    // Declare file pointer
    FILE *fp1;
    // Try to open file that does not exist
    fp1 = fopen("message_file", "r");
    // Pointer will be NULL because open failed
    if(fp1 == NULL){
        // Print message to stderr stream
        fprintf(stderr, "Error: File not opened - fp1 is NULL.\n");
        // Exit with error number 1
        exit(1);
    }


    // Line Input and Output
    /*
        See File Access for fgets() and fputs() examples and comments.
    */



    // Miscellaneous Functions
    /*
        See the documentation (Google these libraries):
        string.h for string functions
        stdlib.h for memory management functions
        ctype.h for character test functions
        math.h for math functions

        See the sample code for Ch 5 for malloc() and free() examples

    */



    return 0;
}


// Menu function
void menu(){

    // int for user's choice
    int choice = 0;
    // Loop until choice == 4
    while(choice != 4){
        printf("Menu\n");
        printf("Press 1 for choice 1\n");
        printf("Press 2 for choice 2\n");
        printf("Press 3 for choice 3\n");
        printf("Press 4 to exit\n");
        // Prompt user for choice
        printf("Enter a choice: ");
        // Get choice from user
        scanf("%d", &choice);
        // Switch-case is a good structure for processing menu choices
        switch (choice){
            case 1: // choice is 1
                printf("You chose 1\n");
                printf("Performing operation 1...\n\n");
                break;
            case 2: // choice is 2
                printf("You chose 2\n");
                printf("Performing operation 2...\n\n");
                break;
            case 3: // choice is 3
                printf("You chose 3\n");
                printf("Performing operation 3...\n\n");
                break;
            case 4: // choice is 4
                printf("You chose 4\n");
                printf("Bye\n\n");
                break;
            default: // Invalid choice
                printf("Please enter a valid choice\n\n");
        }
    }
    return;
}


// Take the average of an unknown number of arguments
double average(int num, ...) {
    // Declare a list to contain arguments using va_list data type
    va_list args;
    // Declare and initialize sum to 0
    double sum = 0;
    // Initialize args to store all values after num
    va_start(args, num);
    // Iterator
    int x = 0;
    // Loop through args, accumulating sum for num args
    for (x = 0; x < num; x++){
        // Get an argument using macro va_arg and add to sum
        // specifying the argument type as double
        sum += va_arg(args, double);
    }
    // Cleans up the list with macro va_end
    va_end(args);
    // Return average of arguments
    return sum / num;
}


// minprintf:  minimal printf with variable argument list
void minprintf(char *fmt, ...){
    // Declare a list to contain arguments using va_list data type
    va_list ap;   // points to each unnamed arg in turn
    // Char pointers
    char *p;
    //
    char *sval;
    // An int to store an int argument
    int ival;
    // A double to store a double argument
    double dval;
    // Initialize args to store all values with %d %f or %s in format string fmt
    va_start(ap, fmt); // make ap point to 1st unnamed arg
    // Loop through fmt using pointer p
    for (p = fmt; *p; p++) {
        // If a % is NOT found
        if (*p != '%') {
            // Just put the char and continue from beginning of loop
            putc(*p,  stdout);
            continue;
        }
        // Switch on placeholder
        switch (*++p) {
            case 'd': // Print the int
                ival = va_arg(ap, int);
                printf("%d", ival);
                break;
            case 'f': // Print float or double
                dval = va_arg(ap, double);
                printf("%f", dval);
                break;
            case 's': // Loop to print all chars in string - stops when sval is \0
                for (sval = va_arg(ap, char *); *sval; sval++)
                    putchar(*sval);
                break;
            default: // If placeholder not defined - just print it
                putc(*p, stdout);
                break;
        }
    }
    // Clean up when done
    va_end(ap);
}
