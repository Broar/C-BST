#ifndef BST_H
#define BST_H
#include <stddef.h>
#include <stdbool.h>



/* BST: */
struct _BST {

	struct _BSTNode* root;		/* root BSTNode */
};
typedef struct _BST BST;


/* BST node: */
struct _BSTNode {

	int key;					/* key for this node */
	struct _BSTNode* left;		/* left child node */
	struct _BSTNode* right;		/* right child node */
};
typedef struct _BSTNode BSTNode;


/* Converts pointer to a BSTNode NODE into a pointer to the
structure that DNode is embedded inside.
Supply the name of the outer structure STRUCT and the
member name MEMBER of the DNode.
*/
#define BST_Entry(NODE, STRUCT, MEMBER)	\
  ((STRUCT *) ((uint8_t *) (NODE) - offsetof (STRUCT, MEMBER))) \


/* Initializes a new empty BST empty
*/
void BST_Init(BST* bst);


/* Initialize a new BSTNode struct 
*/
void BSTNode_Init(BSTNode* node);


/* Returns a pointer to root node of bst.
If bst is empty, returns NULL
*/
BSTNode* BST_Root(BST* bst);


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

