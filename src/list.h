/**
*Header File for list.c
*Used by list.c and main.c
**/

/**
*General boolean used throughout assignment
**/
typedef enum {FALSE,TRUE} BOOLEAN;

/**
*This adds a node by pointer to list
*it takes the int value given
*and then creates a new node in list
*with appropriate index and value
**/
void add(int);

/**
*Prints linked list in same format
*as given file with ints
**/
void prettyPrint();

/**
*Removes node with given int value
*if not found, then returns FALSE
**/
BOOLEAN delete(int);
