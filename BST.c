#include "BST.h"


/* static helper method declarations */
static bool Insert(BSTNode** root, BSTNode* pNode,
	int (*compare)(const BSTNode* const pNodeA, const BSTNode* const pNodeB));

static BSTNode* Find(BSTNode* root, const BSTNode* const pKeyNode, 
	int (*compare)(const BSTNode* const keyA, const BSTNode* const keyB));

static void Pre_Order(BSTNode* node, void (*visit)(const BSTNode* const node));
static void In_Order(BSTNode* node, void (*visit)(const BSTNode* const node));
static void Post_Order(BSTNode* node, void (*visit)(const BSTNode* const node));


/* 
 * Initializes a new empty BST empty
 * 
 * PRE: bst points to an initialized BST struct
 * 
 * POST: BST bst is an empty with a NULL root node
*/
void BST_Init(BST* const bst) {

	assert(bst != NULL);

	bst->root  = NULL;
}


/* 
 * Initializes a new empty BSTNode:
 * 
 * PRE: bst points to an initialized BSTNode struct
 *  
 * POST: bstNode is an empty node with no child nodes
*/
void BSTNode_Init(BSTNode* node, const void* const key) {

	assert(node != NULL);

	node->key = key;
	node->left = NULL;
	node->right = NULL;
}

/* 
 * Returns a pointer to the node's left child node if it exists.
 * otherwise returns NULL
 * 
 * PRE: node points to a properly initialized BSTNode struct
 * 
 * POST: N/A
*/
BSTNode* BSTNode_Left(const BSTNode* const node) {

	assert(node != NULL);

	return node->left;
}


/* 
 * Returns a pointer to the node's right child node if it exists.
 * otherwise returns NULL
 * 
 * PRE: node points to a properly initialized BSTNode struct
 * 
 * POST: N/A
*/
BSTNode* BSTNode_Right(const BSTNode* const node) {

	assert(node != NULL);
	
	return node->right;
}


/* 
 * Returns a pointer to root node of bst.
 * If bst is empty, returns NULL
 *  
 * PRE: bst points to a properly initialized BST struct
 * 
 * POST: N/A
*/
BSTNode* BST_Root(const BST* const bst) {

	assert(bst != NULL);

	return bst->root;
}


/* 
 * Returns true if bst is empty,
 * otherwise returns false.
 * 
 * PRE: bst points to a properly initialized BST struct
 * 
 * POST: N/A
*/
bool BST_Is_Empty(const BST* const bst) {

	assert(bst != NULL);

	return bst->root == NULL;
}


/* 
 * Inserts node into bst;
 * Returns true of the node was properly inserted,
 * Otherwise returns false.
 * 
 * PRE: bst points to a properly initialized BST struct 
 * and node points to a properly initialized BSTNode struct
 * 
 * POST: If a node with the the key value of node already exists in bst, nothing changes.
 * Otherwise, node is inserted into the BST struct pointed to by bst
*/
bool BST_Insert(BST* const bst, BSTNode* pNode, 
	int (*compare)(const BSTNode* const pNodeA, const BSTNode* const pNodeB) ) {

	assert(bst != NULL);
	assert(pNode != NULL);

        return Insert(&(bst->root), pNode, compare);
}

/* Recursive insert function*/
static bool Insert(BSTNode** root, BSTNode* pNode, 
	int (*compare)(const BSTNode* const pNodeA, const BSTNode* const pNodeB)) {
	
	/* insert here */
	if (*root == NULL) {
		*root = pNode;
		return true;
	}

	/* insert in the left sub-tree */
	else if (compare(pNode, *root) < 0) {
	       return Insert(&((*root)->left), pNode, compare);
	}

	/* insert in the right sub-tree */
	else if (compare(pNode, *root) > 0) {
		return Insert(&((*root)->right), pNode, compare);
	}

	else {

		/* duplicate entry */
		return false;
	}
}


/* 
 * Removes node from bst if it exists and returns true,
 * otherwise, returns false
 * 
 * PRE: bst points to a properly initialized BST struct 
 * and node points to a properly initialized BSTNode struct
 * 
 * POST: If a node with the the key value of node does not exist in bst, nothing changes.
 * Otherwise, node is deleted from the BST struct pointed to by bst
*/
bool BST_Remove(BST* const bst, BSTNode* const node) {

	//TODO
	return false;
}



/* 
 * Clears all nodes from bst
 * 
 * PRE: bst points to a properly initialized BST struct
 * 
 * POST: bst points to an empty BST struct whose root BSTNode is NULL
*/
void BST_Clear(BST* const bst) {

	assert(bst != NULL);

	bst->root = NULL;
}


/* 
 * Returns a pointer to the BSTNode in bst that has a Key member equal to pKeyNode's key member
 * if it exists in bst, otherwise returns NULL
 * 
 * PRE: bst points to a properly initialized BST struct
 * 
 * POST: N/A
*/
BSTNode* BST_Find(const BST* const bst, const BSTNode* const pKeyNode,
	int (*compare)(const BSTNode* const pNodeA, const BSTNode* const pNodeB)) {

	assert(bst != NULL);

	return Find(bst->root, pKeyNode, compare);
}


/* 
 * Recursive find function for searching a BST struct for a node with 
 * a key member equal to the key member of pKeyNode
*/
static BSTNode* Find(BSTNode* pNode, const BSTNode* const pKeyNode,
	int (*compare)(const BSTNode* const pNodeA, const BSTNode* const pNodeB)) {

	/* the key is not in the BST */
	if (pNode == NULL) {
		return NULL;
	}

	/* the key is to the left */
	else if (compare(pKeyNode, pNode) < 0) {

		return Find(BSTNode_Left(pNode), pKeyNode, compare);
	}

	/* the key is to the right */
	else if (compare(pKeyNode, pNode) > 0) {
		return Find(BSTNode_Right(pNode), pKeyNode, compare);
	}

	/* the key at this node */
	else {

		return pNode;
	}
} 



/* 
 * Returns the number of nodes contained in bst
 * 
 * PRE: bst points to a properly initialized BST struct
 * 
 * POST: N/A
*/
int BST_Size(const BST* const bst) {

	assert(bst != NULL);

	//TODO
	/* run a traversal, sending in a function that counts up the nodes
	as they are visited */

	return -1;
}


/*
 * Performs a Pre-Order traversal of bst 
 * and executes the function paramater func at each node
 * 
 * PRE: bst points to a properly initialized BST struct
 * 
 * POST: N/A
*/
void BST_Pre_Order(const BST* const bst, void (*visit)(const BSTNode* const node)) {

        assert(bst != NULL);

	Pre_Order(bst->root, visit);
}

/*
 * Recursive traversal function for walking through the BST pre-order
 */
static void Pre_Order(BSTNode* node, void (*visit)(const BSTNode* const node)) {

       if (node == NULL) {
           return;
       }

       visit(node);
       Pre_Order(node->left, visit);
       Pre_Order(node->right, visit);
}


/*
 * Performs a In-Order traversal of bst 
 * and executes the function paramater func at each node
 *
 * PRE: bst points to a properly initialized BST struct
 * 
 * POST: N/A
*/
void BST_In_Order(const BST* const bst, void (*visit)(const BSTNode* const node)) {

	assert(bst != NULL);

	In_Order(bst->root, visit);
}

/*
 * Recursive traversal function for walking through the BST in-order
 */
static void In_Order(BSTNode* node, void (*visit)(const BSTNode* const node)) {

       if (node == NULL) {
           return;
       }

       In_Order(node->left, visit);
       visit(node);
       In_Order(node->right, visit);
}


/* 
 * Performs a Post-Order traversal of bst 
 * and executes the function paramater func at each node
 * 
 * PRE: bst points to a properly initialized BST struct
 * 
 * POST: N/A
*/
void BST_Post_Order(const BST* const bst, void (*visit)(const BSTNode* const node)) {

	assert(bst != NULL);

	Post_Order(bst->root, visit);
}

/*
 * Recursive traversal function for walking through the BST in-order
 */
static void Post_Order(BSTNode* node, void (*visit)(const BSTNode* const node)) {

       if (node == NULL) {
           return;
       }

       Post_Order(node->left, visit);
       Post_Order(node->right, visit);
       visit(node);
}
