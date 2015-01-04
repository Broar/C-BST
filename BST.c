#include "BST.h"



/* Initializes a new empty BST empty
PRE: bst points to an initialized BST struct
POST: BST bst is an empty with a NULL root node
*/
void BST_Init(BST* const bst) {

	assert(bst != NULL);

	bst->root  = NULL;
}


/* Initializes a new empty BSTNode:
PRE: bst points to an initialized BSTNode struct
POST: bstNode is an empty node with no child nodes
*/
void BSTNode_Init(BSTNode* const node) {

	assert(node != NULL);

	node->key = MIN_INT;
	node->left = NULL;
	node->right = NULL;
}

/* Returns a pointer to the node's left child node if it exists.
otherwise returns NULL
PRE: node points to a properly initialized BSTNode struct
POST: N/A
*/
BSTNode* BSTNode_Left(const BSTNode* const node) {

	assert(node != NULL);

	return node->left;
}


/* Returns a pointer to the node's right child node if it exists.
otherwise returns NULL
PRE: node points to a properly initialized BSTNode struct
POST: N/A
*/
BSTNode* BSTNode_Right(const BSTNode* const node) {

	assert(node != NULL);
	
	return node->right;
}


/* Returns a pointer to root node of bst.
If bst is empty, returns NULL
PRE: bst points to a properly initialized BST struct
POST: N/A
*/
BSTNode* BST_Root(const BST* const bst) {

	assert(bst != NULL);

	return bst->root;
}


/* Returns true if bst is empty,
otherwise returns false.
PRE: bst points to a properly initialized BST struct
POST: N/A
*/
bool BST_Is_Empty(const BST* const bst) {

	assert(bst != NULL);

	return bst->root == NULL;
}


/* Inserts node into bst;
Returns true of the node was properly inserted,
Otherwise returns false.
PRE: bst points to a properly initialized BST struct 
and node points to a properly initialized BSTNode struct
POST: If a node with the the key value of node already exists in bst, nothing changes.
Otherwise, node is inserted into the BST struct pointed to by bst
*/
bool BST_Insert(BST* const bst, BSTNode* const node);


/* Removes node from bst if it exists and returns true,
otherwise, returns false
PRE: bst points to a properly initialized BST struct 
and node points to a properly initialized BSTNode struct
POST: If a node with the the key value of node already exists in bst, nothing changes.
Otherwise, node is inserted into the BST struct pointed to by bst
*/
bool BST_Remove(BST* const bst, BSTNode* const node);



/* Clears all nodes from bst
PRE: bst points to a properly initialized BST struct
POST: bst points to an empty BST struct whose root BSTNode is NULL
*/
void BST_Clear(BST* const bst) {

	assert(bst != NULL);

	bst->root = NULL;
}


/* Returns a pointer to the BSTNode in bst that has a Key member equal to key
if it exists in bst, otherwise returns null
PRE: bst points to a properly initialized BST struct
POST: N/A
*/
BSTNode* BST_Find(const BST* const bst, int const key);


/* Returns the number of nodes contained in bst
PRE: bst points to a properly initialized BST struct
POST: N/A
*/
int BST_Size(const BST* const bst) {

	assert(bst != NULL);

	//TODO
	/* run a traversal, sending in a function that counts up the nodes
	as they are visited */

	return -1;
}


/* Performs a Pre-Order traversal of bst 
and executes the function paramater func at each node
PRE: bst points to a properly initialized BST struct
POST: N/A
*/
void BST_Pre_Order(const BST const *bst, void (*visit)(const BSTNode* const node));


/* Performs a In-Order traversal of bst 
and executes the function paramater func at each node
PRE: bst points to a properly initialized BST struct
POST: N/A
*/
void BST_In_Order(const BST* const bst, void (*visit)(const BSTNode* const node));


/* Performs a Post-Order traversal of bst 
and executes the function paramater func at each node
PRE: bst points to a properly initialized BST struct
POST: N/A
*/
void BST_Post_Order(const BST const *bst, void (*visit)(const BSTNode* const node));