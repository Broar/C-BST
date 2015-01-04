#include "BST.h"
#include "StringDT.h"

/******************************* Commands *******************************/

/* Compilation: 
$ gcc -o driver -O0 -static -ggdb3 -std=c99 -Wall -m64 driver.c BST.c */

/* Valgrind: 
$ valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -v ./driver */


/* Test method declarations */
static void test_init();

/* BST Struct */
static BST bst;

/* Strings */
char* zero = "Zero";
char* one = "One";
char* two = "Two";
char* three = "Three";
char* four = "Four";
char* five = "Five";
char* six = "Six";