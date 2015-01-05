#ifndef StringDT_H
#define StringDT_H
#include "BST.h"


/*  StringDT provides a "wrapper" to attach string type to a BST node. */
struct _StringDT {

	char* payload;	/* points to the "payload", 
  					a string supplied when StringDT_Set is called */

  	BSTNode  node;	/* BST node to provide bst structure */
};

typedef struct _StringDT StringDT;


/* StringDT_Set() initializes a new StringDT object.
 * 
 * PRE:pStringDT points to a SringDT object
 * pString points to a properly-initialized char* string
 * 
 * POST: pStringDT->payload == pString 
 * The child nodes in pStringDT->Node are NULL
 * 
 * RETURNS: false if the object could not be properly initialized; 
 * true otherwise
 * 
 * NOTE: Whether *pString was allocated dynamically or statically
 * is unknown. *pString is owned by the client who uses 
 * the BST implementation, and deallocation of it 
 * is the responsibility of that client.
*/
bool StringDT_Set(StringDT* const pStringDT, const int* const key, char* pString);

#endif