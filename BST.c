#include "BST.h"


/* static helper method declarations */
static bool Insert(BSTNode** root, BSTNode* node);
static BSTNode* Remove(BSTNode** root, int key);
static BSTNode* GetMax(BSTNode* node);
static BSTNode* Find(BSTNode* node, const int key);
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
void BSTNode_Init(BSTNode* const node, const int* const key) {

	assert(node != NULL);

	node->key = *key;
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
bool BST_Insert(BST* const bst, BSTNode* const node) {

	assert(bst != NULL);
	assert(node != NULL);

        return Insert(&(bst->root), node);
}

/* Recursive insert function*/
static bool Insert(BSTNode** root, BSTNode* node) {
	
	/* insert here */
	if (*root == NULL) {
		*root = node;
		return true;
	}

	/* insert in the left sub-tree */
	else if (node->key < (*root)->key) {
	       return Insert(&((*root)->left), node);
	}

	/* insert in the right sub-tree */
	else if (node->key > (*root)->key) {
		return Insert(&((*root)->right), node);
	}

	else {

		/* duplicate entry */
		return false;
	}
}


/* 
 * Removes node from bst if it exists and returns the removed node.
 * Otherwise, returns NULL.
 * 
 * PRE: bst points to a properly initialized BST struct 
 * 
 * POST: If a node with the the key value of node does not exist in bst, nothing changes.
 * Otherwise, node is deleted from the BST struct pointed to by bst
*/
BSTNode* BST_Remove(BST* const bst, int key) {

	assert(bst != NULL);
        
        BSTNode* temp = BST_Find(bst, key);

        if (temp != NULL) {
            bst->root = Remove(&(bst->root), key);
        }

	return temp;
}

/*
 * Recurisvely remove the specified node from the subtree pointed to by root.
 * When removing a node with two children, the replacement node is the largest
 * node in the parent's left subtree.
 */
static BSTNode* Remove(BSTNode** root, int key) {
        
        /* The node to delete does not exist in the tree */
        if (*root == NULL) {
                return NULL;
        }

        /* The node to delete is in the left subtree */
        else if (key < (*root)->key) {
                (*root)->left = Remove(&((*root)->left), key);
        }

        /* The node to delete is in the right subtree */
        else if (key > (*root)->key) {
                (*root)->right = Remove(&((*root)->right), key);
        }

        /* The node to delete is here */
        else {

                /* Root has either one or no children */
                if ((*root)->left == NULL) {
                        return (*root)->right;
                }

                
                else if ((*root)->right == NULL) {
                        return (*root)->left;
                }

                /* Root has two children, so we must find a replacement */
                else {
                        BSTNode* temp = GetMax((*root)->left);
                        (*root)->left = Remove(&((*root)->left), temp->key);

                        temp->left = (*root)->left;
                        temp->right = (*root)->right;
                        *root = temp;
                }  
        }

        return *root;
}

/*
 * Return the largest node in the subtree pointed to by node
 */
static BSTNode* GetMax(BSTNode* node) {
        
       while (node->right != NULL) {
           node = node->right;
       }

       return node;
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
 * Returns a pointer to the BSTNode in bst that has a Key member equal to key
 * if it exists in bst, otherwise returns NULL
 * 
 * PRE: bst points to a properly initialized BST struct
 * 
 * POST: N/A
*/
BSTNode* BST_Find(const BST* const bst, int key) {

	assert(bst != NULL);

	return Find(bst->root, key);
}


/* 
 * Recursive find function for searching a BST struct for a node with 
 * a key member equal to 'key'
*/
static BSTNode* Find(BSTNode* node, int key) {

	/* the key is not in the BST */
	if (node == NULL) {
		return NULL;
	}

	/* the key is to the left */
	else if (key < node->key) {
		return Find(BSTNode_Left(node), key);
	}

	/* the key is to the right */
	else if (key > node->key) {
		return Find(BSTNode_Right(node), key);
	}

	/* the key at this node */
	else {

		return node;
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
