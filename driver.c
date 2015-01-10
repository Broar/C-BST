#include "BST.h"
#include "StringDT.h"
#include <stdio.h>

/********* 
* Commands 
**********/

/* Compilation: 
$ gcc -o driver -O0 -static -ggdb3 -std=c99 -Wall -m64 driver.c BST.c StringDT.c */

/* Valgrind:
$ valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -v ./driver */


/************************
 Test method declarations
*************************/
static void BST_Init_Tests();

static void StringDT_Set_Tests();
static void Test_StringDT_Set(StringDT* pStringDT, const int* const key, char* pStr);

static void BST_Insert_Tests();
static void Test_BST_Insert(BSTNode* pNode, char* pStr);

static void BST_Remove_Tests();
static void Test_BST_Remove(BSTNode* pNode);

static void BST_Pre_Order_Tests();
static void BST_In_Order_Tests();
static void BST_Post_Order_Tests();
static void Print_StringDT(const BSTNode* const pNode);

static int KeyComparator(const BSTNode* const keyA, const BSTNode* const keyB);


/* BST Struct */
static BST bst;


/* Strings */
char* sZero 	= "Zero";
char* sOne 		= "One";
char* sTwo 		= "Two";
char* sThree 	= "Three";
char* sFour 	= "Four";
char* sFive 	= "Five";
char* sSix 		= "Six";
char* sSeven 	= "Seven";
char* sEight 	= "Eight";
char* sNine 	= "Nine";
char* sTen 		= "Ten";

/* integer keys */
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

    /* testing preorder traversal of BST */
    BST_Pre_Order_Tests();

    /* testing inorder traversal of BST */
    BST_In_Order_Tests();

    /* testing postorder traversal of BST */
    BST_Post_Order_Tests();

    /* testing removal of nodes from BST */
    BST_Remove_Tests();

    return 0;
}


/*
*/
static void BST_Init_Tests() {

	/* Initialize the BST struct bst*/
	printf("\nTesting initialization of BST structure...\n");
	printf("********************************************\n");
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
	BST_Find(&bst, &oneDT.node, &KeyComparator) == NULL ? printf("OK\n") : printf("FAIL\n");

	/* Test that the size of an empty BST is equal to zero */
	printf("Size of empty BST returns 0: ");
	BST_Size(&bst) == 0 ? printf("OK\n") : printf("FAIL\n");

    /* Test that removal of a node in an empty tree returns NULL */

    printf("Deletion of non-existent node in empty BST returns NULL: ");
    BST_Remove(&bst, &zeroDT.node, &KeyComparator ) == NULL ? printf("OK\n") : printf("FAIL\n");

	/* Test the Pre-Order Traversal of an empty BST*/
	printf("Pre-Order: \n");
	BST_Pre_Order(&bst, &Print_StringDT);

	/* Test the In-Order Traversal of an empty BST*/
	printf("In-Order: \n");
	BST_In_Order(&bst, &Print_StringDT);

	/* Test the Post-Order Traversal of an empty BST*/
	printf("Post-Order: \n");
	BST_Post_Order(&bst, &Print_StringDT);
}

/*
*/
static void StringDT_Set_Tests() {

	printf("\nTesting Initialization of StringDT Wrappers...\n");
	printf("************************************************\n");
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
static void BST_Insert_Tests() {

	printf("\nInserting nodes into BST...\n");
	printf("*****************************\n");
	
	Test_BST_Insert(&fiveDT.node, 	sFive);
	Test_BST_Insert(&threeDT.node, 	sThree);
	Test_BST_Insert(&eightDT.node, 	sEight);
	Test_BST_Insert(&sevenDT.node, 	sSeven);
	Test_BST_Insert(&tenDT.node, 	sTen);

	/* Test that the size of an empty BST is equal to zero */
	printf("\nTest the Size of BST returns 5");
	int size = BST_Size(&bst);
	size == 5 ? printf("\t: OK\n") : printf("\t:FAIL; size == %d\n", size);

	Test_BST_Insert(&fourDT.node, 	sFour);
	Test_BST_Insert(&oneDT.node, 	sOne);
	Test_BST_Insert(&zeroDT.node, 	sZero);
	Test_BST_Insert(&twoDT.node, 	sTwo);
	Test_BST_Insert(&sixDT.node, 	sSix);
	Test_BST_Insert(&nineDT.node, 	sNine);

	/* Test that the size of an empty BST is equal to zero */
	printf("\nTest the Size of BST returns 11: ");
	size = BST_Size(&bst);
	size == 11 ? printf("OK\n") : printf("FAIL; size == %d\n", size);

	printf("inserting duplicate node < %d, %s > : ", 5, "Five");
	!BST_Insert(&bst, &fiveDT.node, &KeyComparator) ? printf("OK\n") : printf("FAIL\n");

	printf("\nBST is NOT empty: ");
	!BST_Is_Empty(&bst) ? printf("OK\n") : printf("FAIL\n");
}


/*
*/
static void Test_BST_Insert(BSTNode* pNode, char* pStr) {

	printf("inserting node < %d, %s > \t: ", *(int*)pNode->key, pStr);
	BST_Insert(&bst, pNode, &KeyComparator) ? printf("OK\n") : printf("FAIL\n");
}



/*
 * Test removing all of the nodes from the BST.
 */
static void BST_Remove_Tests() {

        printf("\nRemoving all nodes from BST...\n");
        printf("*****************************\n");
        
        Test_BST_Remove(&zeroDT.node);
        Test_BST_Remove(&oneDT.node);
        Test_BST_Remove(&fiveDT.node);
        Test_BST_Remove(&eightDT.node);
        Test_BST_Remove(&nineDT.node);
        Test_BST_Remove(&sevenDT.node);

        printf("\nTesting that the Size is now 5: ");
        int size = BST_Size(&bst);
        size == 5 ? printf("OK\n") : printf("Fail; size = %d", size);

        printf("\nPerforming in-order traversal of half-empty BST...\n");
        BST_In_Order(&bst, &Print_StringDT);
        printf("\n");

        Test_BST_Remove(&tenDT.node);
        Test_BST_Remove(&twoDT.node);
        Test_BST_Remove(&sixDT.node);
        Test_BST_Remove(&fourDT.node);
        Test_BST_Remove(&threeDT.node);

        printf("BST is empty: ");
        BST_Is_Empty(&bst) ? printf("OK\n") : printf("FAIL\n");
}



/*
 * A helper function for removing a node from the BST and verifying the
 * results of the removal.
 */
static void Test_BST_Remove(BSTNode* pNode) {
        
        printf("removing node: key= %d\t: ", *((int*)pNode->key));
        BSTNode* temp = BST_Remove(&bst, pNode, &KeyComparator);
        *((int*)(temp->key)) == *((int*)(pNode->key)) ? printf("OK\n") : printf("FAIL\n");
}


/*
 * Test the pre-order traversal of the BST by printing the payload of
 * each StringDT located in the tree
 */
static void BST_Pre_Order_Tests() {
        
        printf("\nPerforming pre-order traversal of BST...\n");
        BST_Pre_Order(&bst, &Print_StringDT);
        printf("\n");
}

/*
 * Test the in-order traversal of the BST by printing the payload of
 * each StringDT located in the tree
 */
static void BST_In_Order_Tests() {
        
        printf("\nPerforming in-order traversal of BST...\n");
        BST_In_Order(&bst, &Print_StringDT);
        printf("\n");
}

/*
 * Test the post-order traversal of the BST by printing the payload of
 * each StringDT located in the tree
 */
static void BST_Post_Order_Tests() {

        printf("\nPerforming post-order traversal of BST...\n");
        BST_Post_Order(&bst, &Print_StringDT);
        printf("\n");
}

/*
 * Print the payload of the StringDT wrapped with the specified BSTNode.
 * This is a helper function for testing the traversals of a BST.
 */
static void Print_StringDT(const BSTNode* const pNode) {

        StringDT *dt = BST_Entry(pNode, StringDT, node);
        printf("%s\n", dt->payload);
}

static int KeyComparator(const BSTNode* const pNodeA, const BSTNode* const pNodeB) {
	
	return *((int*)(pNodeA->key)) - *((int*)(pNodeB->key));
}
