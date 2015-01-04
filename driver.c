#include "BST.h"
#include "StringDT.h"
#include <stdio.h>

/******************************* Commands *******************************/

/* Compilation: 
$ gcc -o driver -O0 -static -ggdb3 -std=c99 -Wall -m64 driver.c BST.c */

/* Valgrind: 
$ valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -v ./driver */


/* Test method declarations */
static void Test_BST_Init();
static void Test_StringDT_Set();
static void StringDT_Set_Test();


/* BST Struct */
static BST bst;


/* Strings */
char* zero 	= 	"Zero";
char* one 	= 	"One";
char* two 	= 	"Two";
char* three = 	"Three";
char* four 	= 	"Four";
char* five 	= 	"Five";
char* six 	= 	"Six";
char* seven = 	"Seven";
char* eight = 	"Eight";
char* nine 	= 	"Nine";
char* ten 	= 	"Ten";


/* StringDT wrapper objects*/
StringDT zeroDT;
StringDT oneDT;
StringDT twoDT;
StringDT threeDT;
StringDT fourDT;
StringDT fiveDT;
StringDT sixDT;
StringDT sevenDT;
StringDT eightDT;
StringDT nineDT;
StringDT tenDT;


/*
*/
int main () {

	/* testing initialization of BST */
	Test_BST_Init();

	/* testing initialization of StringDT objects */	
	Test_StringDT_Set();

	return 0;
}


/*
*/
static void Test_BST_Init() {

	/* Initialize the BST struct bst*/
	printf("\nTesting initialization of BST structure.\n");
	printf("Initializing BST...\n");
	BST_Init(&bst);

	/* Test that the bst is empty */
	printf("BST is Empty: ");
	BST_Is_Empty(&bst) ? printf("OK\n") : printf("FAIL\n");

	/* Test that the root node of bst is NULL */
	printf("BST root node is NULL: ");
	BST_Root(&bst) == NULL ? printf("OK\n") : printf("FAIL\n");

	/* Test that find returns NULL when calling an empty tree */
	printf("Searching empty BST returns NULL: ");
	BST_Find(&bst, 100) == NULL ? printf("OK\n") : printf("FAIL\n");

	/* Test that the size of an empty BST is equal to zero */
	printf("Size of empty BST returns 0: ");
	BST_Size(&bst) == 0 ? printf("OK\n") : printf("FAIL\n");

	/* Test the Pre-Order Traversal of an empty BST*/
	printf("Pre-Order: \n");

	/* Test the In-Order Traversal of an empty BST*/
	printf("In-Order: \n");

	/* Test the Post-Order Traversal of an empty BST*/
	printf("In-Order: \n");
}

/*
*/
static void Test_StringDT_Set(){

	StringDT_Set_Test(&zeroDT, 	zero);
	StringDT_Set_Test(&oneDT, 	one);
	StringDT_Set_Test(&twoDT, 	two);
	StringDT_Set_Test(&threeDT, three);
	StringDT_Set_Test(&fourDT, 	four);
	StringDT_Set_Test(&fiveDT, 	five);
	StringDT_Set_Test(&sixDT, 	six);
	StringDT_Set_Test(&sevenDT, seven);
	StringDT_Set_Test(&eightDT,	eight);
	StringDT_Set_Test(&nineDT, 	nine);
	StringDT_Set_Test(&tenDT, 	ten);
}

static void StringDT_Set_Test(StringDT* pStringDT, char* str) {	

	printf("initializing StringDT: %s\t: ", str);
	StringDT_Set(pStringDT, str);
	pStringDT->payload == str && pStringDT->Node.left == NULL && pStringDT->Node.right == NULL
		? printf("OK\n") : printf("FAIL\n");
}