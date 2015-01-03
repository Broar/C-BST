#include "BST.h"


/* Function declarations */
void BST_Init(BST* bst);
void BSTNode_Init(BSTNode* node);

BSTNode* BSTNode_Left(BSTNode* node);
BSTNode* BSTNode_Right(BSTNode* node);

BSTNode* BST_Root(BST* bst);
bool BST_Is_Empty(BST* bst);
bool BST_Insert(BST* bst, BSTNode* node);
bool BST_Remove(BST* bst, BSTNode* node);
void BST_Clear(BST* bst);
BSTNode* BST_Find(BST* bst, int key);
int BST_Size(BST* bst);
void BST_Pre_Order(BST *bst, void (func*)(BSTNode* node) );
void BST_In_Order(BST* bst, void (func*)(BSTNode* node) );
void BST_Post_Order(BST *bst, void (func*)(BSTNode* node) );

/*****************************************************************************/

/* Initializes a new empty BST empty
*/
void BST_Init(BST* bst) {

	(assert bst != NULL);

	bst->root  = NULL;
}


/* Initializes a new empty BST:
pre: bst points to an initialized BST
post: bst contains a root node pointer == NULL
*/
void BSTNode_Init(BSTNode* node) {

	assert(node != NULL);

	node->key = MIN_INT;
	node->left = NULL;
	node->right = NULL;
}

/* Returns a pointer to the node's left child node if it exists.
otherwise returns NULL
*/
BSTNode* BSTNode_Left(BSTNode* node){

	assert(node != NULL);

	return node->left;
}


/* Returns a pointer to the node's right child node if it exists.
otherwise returns NULL
*/
BSTNode* BSTNode_Right(BSTNode* node) {

	assert(node != NULL);
	
	return node->right;
}


/* Returns a pointer to root node of bst.
If bst is empty, returns NULL
*/
BSTNode* BST_Root(BST* bst) {

	assert(bst != NULL);

	return bst->root;
}


/* Returns true if bst is empty,
otherwise returns false 
*/
bool BST_Is_Empty(BST* bst);


/* Inserts node into bst;
Returns true of the node was properly inserted,
Otherwise returns false.
*/
bool BST_Insert(BST* bst, BSTNode* node);


/* Removes node from bst if it exists and returns true,
otherwise, returns false
*/
bool BST_Remove(BST* bst, BSTNode* node);


/* Clears all nodes from bst 
*/
void BST_Clear(BST* bst);


/* Returns a pointer to the BSTNode in bst that has a Key member equal to key
if it exists in bst, otherwise returns null
*/
BSTNode* BST_Find(BST* bst, int key);


/* Returns the number of nodes contained in bst
*/
int BST_Size(BST* bst);


/* Performs a Pre-Order traversal of bst 
and executes the function paramater func at each node
*/
void BST_Pre_Order(BST *bst, void (func*)(BSTNode* node) );


/* Performs a In-Order traversal of bst 
and executes the function paramater func at each node
*/
void BST_In_Order(BST* bst, void (func*)(BSTNode* node) );


/* Performs a Post-Order traversal of bst 
and executes the function paramater func at each node
*/
void BST_Post_Order(BST *bst, void (func*)(BSTNode* node) );