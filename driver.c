#include "BST.h"
#include "StringDT.h"
#include <stdio.h>

/******************************* Commands *******************************/

/* Compilation: 
$ gcc -o driver -O0 -static -ggdb3 -std=c99 -Wall -m64 driver.c BST.c StringDT.c */

/* Valgrind: 
$ valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -v ./driver */


/* Test method declarations */
static void BST_Init_Tests();

static void StringDT_Set_Tests();
static void Test_StringDT_Set(StringDT* pStringDT, const int* const key, char* pStr);

static void BST_Insert_Tests();
static void Test_BST_Insert(BSTNode* pNode, char* pStr);


/* BST Struct */
static BST bst;


/* Strings */
char* sZero 	= "Zero";
char* sOne 	= "One";
char* sTwo 	= "Two";
char* sThree 	= "Three";
char* sFour 	= "Four";
char* sFive 	= "Five";
char* sSix 	= "Six";
char* sSeven 	= "Seven";
char* sEight 	= "Eight";
char* sNine 	= "Nine";
char* sTen 	= "Ten";

const int intZero 	= 0;
const int intOne 	= 1;
const int intTwo 	= 2;
const int intThree 	= 3;
const int intFour 	= 4;
const int intFive 	= 5;
const int intSix 	= 6;
const int intSeven 	= 7;
const int intEight 	= 8;
const int intNine 	= 9;
const int intTen 	= 10;


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
	BST_Init_Tests();

	/* testing initialization of StringDT objects */	
	StringDT_Set_Tests();

	/* testing insertion on the BST */
	BST_Insert_Tests();

	return 0;
}


/*
*/
static void BST_Init_Tests() {

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
static void StringDT_Set_Tests(){

	printf("\nTesting Initialization of StringDT Wrappers...\n");
	Test_StringDT_Set(&zeroDT, 	&intZero, 	sZero);
	Test_StringDT_Set(&oneDT, 	&intOne, 	sOne);
	Test_StringDT_Set(&twoDT, 	&intTwo, 	sTwo);
	Test_StringDT_Set(&threeDT, &intThree, 	sThree);
	Test_StringDT_Set(&fourDT, 	&intFour,	sFour);
	Test_StringDT_Set(&fiveDT, 	&intFive, 	sFive);
	Test_StringDT_Set(&sixDT, 	&intSix, 	sSix);
	Test_StringDT_Set(&sevenDT, &intSeven, 	sSeven);
	Test_StringDT_Set(&eightDT, &intEight, 	sEight);
	Test_StringDT_Set(&nineDT, 	&intNine, 	sNine);
	Test_StringDT_Set(&tenDT, 	&intTen, 	sTen);
}


/*
*/
static void Test_StringDT_Set(StringDT* pStringDT, const int* const pKey, char* pStr) {	

	printf("initializing StringDT: %s\t: ", pStr);
	StringDT_Set(pStringDT, pKey, pStr);
	pStringDT->payload == pStr && pStringDT->node.left == NULL && pStringDT->node.right == NULL
		? printf("OK\n") : printf("FAIL\n");
}


/*
*/
static void BST_Insert_Tests(){

	printf("\nInserting nodes into BST...\n");
	
	Test_BST_Insert(&fiveDT.node, sFive);
	Test_BST_Insert(&threeDT.node, sThree);
	Test_BST_Insert(&eightDT.node, sEight);
	Test_BST_Insert(&sevenDT.node, sSeven);
	Test_BST_Insert(&tenDT.node, sTen);
	Test_BST_Insert(&fourDT.node, sFour);
	Test_BST_Insert(&oneDT.node, sOne);
	Test_BST_Insert(&zeroDT.node, sZero);
	Test_BST_Insert(&twoDT.node, sTwo);
	Test_BST_Insert(&sixDT.node, sSix);
	Test_BST_Insert(&nineDT.node, sNine);

	printf("inserting duplicate node < %d, %s > : ", 5, "Five");
	!BST_Insert(&bst, &fiveDT.node) ? printf("OK\n") : printf("FAIL\n");

	printf("BST is NOT empty: ");
	!BST_Is_Empty(&bst) ? printf("OK\n") : printf("FAIL\n");
}


/*
*/
static void Test_BST_Insert(BSTNode* pNode, char* pStr) {

	printf("inserting node < %d, %s > \t: ", pNode->key, pStr);
	BST_Insert(&bst, pNode) ? printf("OK\n") : printf("FAIL\n");
}