// Includes functions in C libraries
#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// Defined constants
// For rect struct
#define XMAX 320
#define YMAX 200
// For colors array
#define NCOLORS 5
// For unions
#define INT 0
#define FLOAT 1
#define STRING 2
// For bit-fields
#define KEYWORD 1
#define EXTERNAL 2
#define STATIC 4

// Min and max macros
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))


// This is a basic struct
struct point{
    int x;
    int y;
};

// This is a nested struct
struct rect{
    struct point pt1;
    struct point pt2;
};

// This struct has a char array pointer and its length
struct string{
    int len;
    char *str;
};

// This struct has a fixed size char array
struct color{
    char name[20];
    int red;
    int green;
    int blue;
};

// Self referential struct - a node in a tree
struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

// Create a data type Length as an int
typedef int Length;

// Data type Tree_node - self referential struct - a node in a tree
typedef struct tnode1 {
    char *word;
    int count;
    struct tnode1 *left;
    struct tnode1 *right;
} Tree_node;

// Create a data type Tree_ptr to point to a tree root node
typedef struct tnode1 *Tree_ptr;

// Union
union u_tag{
    int ival;
    float fval;
    char *sval;
};


// Prototypes
struct point make_point(int x, int y);
struct point add_point(struct point p1, struct point p2);
int pt_in_rect(struct point p, struct rect r);
struct rect cannon_rect(struct rect r);
void rect_double(struct rect *r);
struct point* make_pt_array(int len);
void print_tree(struct tnode *node);


// Main
int main(){

    // Basics of Structures
    /*
        structs are a containers for data.  They can contain data
        of different types.
    */
    // Declares two basic structs
    struct point pt1;
    struct point pt2;
    // Populate pt1
    pt1.x = 1;
    pt1.y = 1;
    // Populate pt2
    pt2.x = 2;
    pt2.y = 2;
    // Print pt1 and pt2
    printf("pt1 x = %d y = %d\n", pt1.x, pt1.y);
    printf("pt2 x = %d y = %d\n\n", pt2.x, pt2.y);

    // Declare and initialize a point
    struct point maxpt = {320, 200};
    // Print maxpt
    printf("maxpt x = %d y = %d\n\n", maxpt.x, maxpt.y);

    // Calculate distance from origin
    double dist = sqrt((double)(pt1.x*pt1.x) + (double)(pt1.y*pt1.y));
    // Print dist
    printf("dist = %.2f\n\n", dist);

    // Declare a rect struct
    struct rect screen;
    // Configure a 3x2 rectangle from point (2,2)
    screen.pt1.x = 2;
    screen.pt1.y = 2;
    screen.pt2.x = 5;
    screen.pt2.y = 4;
    // Print rect
    printf("screen: (%d, %d) to (%d, %d)\n\n", screen.pt1.x,
           screen.pt1.y, screen.pt2.x, screen.pt2.y);


    // Structures and Functions
    /*
        structs can be passed to functions as arguments and returned
        from functions.  structs are passed by value, similar to
        primitive data types like int and char.  If you change the
        value stored in the members of a struct in the "called function",
        the data in the members of the struct in the "calling function"
        will not change.  structs can also be passed by reference, where
        the address of the struct data in RAM is passed to the called
        function.  This address fives the called function direct access
        to the data in RAM, hence changes in the called function will
        affect data in the calling function.  Please take note to the
        pointer notation (->) shown below for references.  This notation
        is generally preferred to dereferencing (*) because operator
        precedence requires the use of parenthesis resulting in code
        like (*pp).x to dereference pointer pp to get to the value of
        struct member x.  The . has precedence over the *.  pp->x is
        more concise and errors can occur if the parenthesis are
        omitted.  Some compilers will not consider *pp.x as bad syntax.
        and the program instruction is to dereference pp.x instead of
        pp.
    */
    // Call make_point()
    struct point pt3 = make_point(3, 3);
    // Print pt3
    printf("pt3 x = %d y = %d\n\n", pt3.x, pt3.y);

    // Declare a rect and a point
    struct rect screen1;
    struct point middle;
    // Populate rect and point
    screen1.pt1 = make_point(0,0);
    screen1.pt2 = make_point(XMAX, YMAX);
    middle = make_point((screen1.pt1.x + screen1.pt2.x)/2,
                        (screen1.pt1.y + screen1.pt2.y)/2);
    // Print rect and point
    printf("screen1: (%d, %d) to (%d, %d)\n", screen1.pt1.x,
           screen1.pt1.y, screen1.pt2.x, screen1.pt2.y);
    printf("middle x = %d y = %d\n\n", middle.x, middle.y);

    // Add two points
    struct point pt4 = add_point(pt1, pt2);
    printf("pt3 x = %d y = %d\n\n", pt3);

    // Is a point inside a rect?
    int i = pt_in_rect(middle, screen1);
    printf("middle in screen = %d\n\n", i);

    // Make a rect canonical form
    struct rect r1;
    r1.pt1 = make_point(10,10);
    r1.pt2 = make_point(0, 0);
    struct rect r2 = cannon_rect(r1);
    printf("r1: (%d, %d) to (%d, %d)\n", r1.pt1.x,
           r1.pt1.y, r1.pt2.x, r1.pt2.y);
    printf("r2: (%d, %d) to (%d, %d)\n\n", r2.pt1.x,
           r2.pt1.y, r2.pt2.x, r2.pt2.y);

    // Pointer to a struct
    struct point origin, *pp;
    // Populate origin
    origin =  make_point(0, 0);
    // Copy address of origin to pp
    pp = &origin;
    // Print from pointer
    printf("origin is (%d, %d)\n", (*pp).x, (*pp).y);
    // A better way to pass use a pointer
    printf("origin is (%d, %d)\n", pp->x, pp->y);

    // Example of how to use a struct to store an array
    struct string s;  // Declare a string
    s.len = 50;       // Set max length of char array to 50
    s.str = malloc(s.len);        // Allocate 50 bytes
    strcpy(s.str, "Hello World!");  // Copy to s
    struct string *p_s = &s;    // Declare pointer with address of str
    // Print using pointer notation
    printf("str string has %d bytes of storage\n", p_s->len);
    printf("str string is %s\n", p_s->str);
    printf("str sting length is %d\n\n", strlen(p_s->str));
    free(p_s->str); // Free allocated memory


    // Arrays of Structures
    /*
        structs can also be elements in arrays.  They are declared
        similar to arrays of primitive data types with [], with and
        an array size as shown below.  They are also indexed in like
        manner by placing the element number in the [].  The size of
        a struct can be calculated with the sizeof operator, which
        returns the size of the struct in bytes.
    */
    // Declare an array of structs
    struct color colors[NCOLORS];
    // Populate structs
    strcpy(colors[0].name, "Red");
    colors[0].red = 255;
    colors[0].green = 0;
    colors[0].blue = 0;
    strcpy(colors[1].name, "Green");
    colors[1].red = 0;
    colors[1].green = 255;
    colors[1].blue = 0;
    strcpy(colors[2].name, "Blue");
    colors[2].red = 0;
    colors[2].green = 0;
    colors[2].blue = 255;
    strcpy(colors[3].name, "White");
    colors[3].red = 255;
    colors[3].green = 255;
    colors[3].blue = 255;
    strcpy(colors[4].name, "Black");
    colors[4].red = 0;
    colors[4].green = 0;
    colors[4].blue = 0;
    // Print structs
    int iter = 0;
    for(iter=0; iter<NCOLORS; iter++)
        printf("%s RGB(%d, %d, %d)\n", colors[iter].name, colors[iter].red,
               colors[iter].green, colors[iter].blue);
    printf("\n");

    // How big are the structs declared at top of program
    printf("point is %d bytes\n", sizeof(struct point));
    printf("rect is %d bytes\n", sizeof(struct rect));
    printf("string is %d bytes\n", sizeof(struct string));
    printf("color is %d bytes\n\n", sizeof(struct color));


    // Pointers to Structures
    /*
        To pass a struct by reference, use the address of
        operator & and pass to a function that accepts a
        pointer.  The call rect_double(&r3), passes the
        address of r3 to function rect_double().  The function
        doubles the size of the sides of the rectangle.  The
        prototype for rect_double():

        void rect_double(struct rect *r)

        returns nothing, and accepts a pointer because the * is
        included.
    */
    // Declare a rect struct
    struct rect r3;
    // Configure a 3x2 rectangle from point (2,2)
    r3.pt1.x = 2;
    r3.pt1.y = 2;
    r3.pt2.x = 4;
    r3.pt2.y = 4;
    // Print rect
    printf("r3: (%d, %d) to (%d, %d)\n", r3.pt1.x,
           r3.pt1.y, r3.pt2.x, r3.pt2.y);
    // Pass a struct by reference
    rect_double(&r3);
    // Print rect
    printf("r3: (%d, %d) to (%d, %d)\n\n", r3.pt1.x,
           r3.pt1.y, r3.pt2.x, r3.pt2.y);

    // Function that returns an array of struct
    int len_pt_arr = 3;
    struct point* pt_arr =  make_pt_array(len_pt_arr);
    int iter1 = 0;
    for(iter1=0; iter1<len_pt_arr; iter1++){
        pt_arr[iter1] = make_point(iter1, iter1);
        printf("pt_arr[%d] x = %d y = %d\n\n", iter1, pt_arr[iter1].x, pt_arr[iter1].y);
    }


    // Self-referential Structures
    /*
        As shown with the rect struct, structs can contain other
        structs.  The tnode struct is coded to model a node in
        a binary tree, which is a type of graph model.  Each tnode
        points to addresses of two other child tnodes, one is left
        and one is right.  The tree coded below can be traversed
        using the print_tree() function, which is a recursive
        function that performs a depth first traversal of the tree.
    */
    // Declare some tree nodes
    struct tnode root;
    struct tnode node1;
    struct tnode node2;
    struct tnode node3;
    struct tnode node4;
    struct tnode node5;
    // Populate tree - root node
    root.word = "Root node";
    root.count = 1;
    root.left = &node1;
    root.right = &node2;
    // Node 1
    node1.word = "Node 1";
    node1.count = 2;
    node1.left = &node3;
    node1.right = &node4;
    // Node 2
    node2.word = "Node 2";
    node2.count = 3;
    node2.left = NULL;
    node2.right = NULL;
    // Node 3
    node3.word = "Node 3";
    node3.count = 4;
    node3.left = NULL;
    node3.right = NULL;
    // Node 2
    node4.word = "Node 4";
    node4.count = 5;
    node4.left = NULL;
    node4.right = &node5;
    // Node 3
    node5.word = "Node 5";
    node5.count = 6;
    node5.left = NULL;
    node5.right = NULL;
    // Print tree with recursive function
    print_tree(&root);
    printf("\n");


    // Table Lookup
    /*
        Skip this - this is 2168 material
    */
    //



    // Typedef
    /*
        The typedef keyword allows the definition and redefinition
        of data types.  Notice that:

        typedef int Length;

        redefines an int data type as Length.  The declaration
        below shows a declaration and initialization of a Length
        type x.

        The tree problem above can use typedef to create a tree
        pointer data type and a node data type.  The code:

            typedef struct tnode1 *Tree_ptr;

        defines a data type Tree_ptr, which points to a struct
        tnode1.  The code:

            typedef struct tnode1 {
                char *word;
                int count;
                struct tnode1 *left;
                struct tnode1 *right;
            } Tree_node;

        defines a struct tnode1 and makes it a Tree_node data
        type.
    */
    // Declare and initialize a Length data type variable
    Length x = 5;
    printf("x = %d\n", x);

    // Declare and initialize a Tree_ptr data type pointer
    Tree_ptr tree_;
    // Declare Tree_node data type structs
    Tree_node root_;
    // Declare Tree_node data type for tree
    Tree_node node1_;
    Tree_node node2_;
    Tree_node node3_;
    Tree_node node4_;
    Tree_node node5_;
    // Copy address of root to tree pointer
    tree_ = &root_;

    // Populate tree - root node
    root_.word = "Root node_";
    root_.count = 1;
    root_.left = &node1_;
    root_.right = &node2_;
    // Node 1
    node1_.word = "Node 1_";
    node1_.count = 2;
    node1_.left = &node3_;
    node1_.right = &node4_;
    // Node 2
    node2_.word = "Node 2_";
    node2_.count = 3;
    node2_.left = NULL;
    node2_.right = NULL;
    // Node 3
    node3_.word = "Node 3_";
    node3_.count = 4;
    node3_.left = NULL;
    node3_.right = NULL;
    // Node 2
    node4_.word = "Node 4_";
    node4_.count = 5;
    node4_.left = NULL;
    node4_.right = &node5_;
    // Node 3
    node5_.word = "Node 5_";
    node5_.count = 6;
    node5_.left = NULL;
    node5_.right = NULL;
    // Print tree with recursive function
    print_tree(tree_);
    printf("\n");


    // Unions
    /*
        Unions are structures that can contain one of a collection
        of data types.
    */
    //
    union u_tag ui;
    ui.ival = 10;
    //int ui_type[] = INT;
    union u_tag uf;
    uf.fval = 123.45;
    //int uf_type[] = FLOAT;
    union u_tag us;
    us.sval = "Hello World!";
    //int us_type[] = STRING;

    union u_tag *u_ptr;
    int type;

    //u_ptr = &ui;
    //type = INT;
    //u_ptr = &uf;
    //type = FLOAT;
    u_ptr = &us;
    type = STRING;

    if(type == INT)
        printf("The value is: %d\n", u_ptr->ival);
    else if(type == FLOAT)
        printf("The value is: %f\n", u_ptr->fval);
    else if(type == STRING)
        printf("The value is: %s\n", u_ptr->sval);
    else
        printf("Bad type\n");
    printf("\n");



    // Bit-fields
    /*
        The bits in some primitive data types can be used to
        store data about a yes/no or on/off type condition.
        These are referred to as bit fields.  Consider the
        unsigned char flag below.  The preprocessor statements
        above define three constants with values that are
        exactly a 2^n or power of 2 value.  The least
        significant bit in the char is the 1 bit.  The
        next-to-least is the 2 bit.  Then 4, 8, 16, 32, 64,
        and 128.  KEYWORD has a value of 1, EXTERNAL has a
        value of 2 and STATIC has a value of 4.  The flag
        is initially set to 0, which makes all bits 0.
        Bitwise operators can be used to manipulate and
        interpret the bit fields.  Notice that after the
        STATIC bit is set below, that the integer value
        of flag is 5 because the 1 bit was previously
        set.  You should use the | operator to check if
        a bit is set.  The == operator will not work.
    */
    // Set all flag bits to zero
    unsigned char flag = 0;
    // Set KEYWORD bit
    flag |= KEYWORD;
    printf("flag = %d\n", flag);
    // Set STATIC bit
    flag |= STATIC;
    printf("flag = %d\n", flag);
    // Check if STATIC bit is set
    if(flag | STATIC)
        printf("The STATIC bit is set.\n");
    else
        printf("The STATIC bit is NOT set.\n");
    // This won't work
    if(flag == STATIC)
        printf("The STATIC bit is set.\n");
    else
        printf("The STATIC bit is NOT set.\n");
    printf("\n");


    // Random numbers
    /*
        The code below shows the use of the srand() and
        rand() functions.
    */
    // Seed random generator
    srand(time(NULL));
    // Get a random
    int rand1 = rand();
    printf("rand1 = %d\n", rand1);
    // The random generator picks an int between 0 and RAND_MAX
    printf("RAND_MAX = %d\n", RAND_MAX);
    // Scale a random between 0 and 255
    int rand2 = rand() % 256;
    printf("rand2 = %d\n", rand2);



    return 0;
}


// Function makes and returns a point
struct point make_point(int x, int y){
    struct point temp;
    temp.x = x;
    temp.y = y;
    return temp;
};


// Function adds two points and returns their new point
struct point add_point(struct point p1, struct point p2){
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
};


// Function determines if a point is in a rectangle
int pt_in_rect(struct point p, struct rect r){
return p.x >= r.pt1.x && p.x <= r.pt2.x &&
        p.y >= r.pt1.y && p.y <= r.pt2.y;
}


// Function makes a rectangle into canonical form
struct rect cannon_rect(struct rect r){
    struct rect temp;
    temp.pt1.x = min(r.pt1.x, r.pt2.x);
    temp.pt1.y = min(r.pt1.y, r.pt2.y);
    temp.pt2.x = max(r.pt1.x, r.pt2.x);
    temp.pt2.y = max(r.pt1.y, r.pt2.y);
    return temp;
};


// Double the size of a rectangle - pass by reference
void rect_double(struct rect *r){
    r->pt2.x += r->pt2.x - r->pt1.x;
    r->pt2.y += r->pt2.y - r->pt1.y;
    return;
}


// Function returns an array of struct point
struct point* make_pt_array(int len){
    //
    struct point *pt_arr;
    // Allocate memory for the array
    pt_arr = (struct point*) malloc(sizeof(struct point) * len);
    if(pt_arr == NULL){
        printf("Memory allocation failed.\n");
    }
    return pt_arr;
}


// Print tree with recursive DFS type function
void print_tree(struct tnode *node){
    // Print this node
    printf("%s : %d\n", node->word, node->count);
    if(node->left)
        print_tree(node->left);
    if(node->right)
        print_tree(node->right);
    return;
}


