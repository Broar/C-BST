#include "StringDT.h"

/* StringDT_Set() initializes a new StringDT object.

PRE:pStringDT points to a SringDT object
pString points to a properly-initialized char* string

POST: pStringDT->payload == pString 
The child nodes in pStringDT->Node are NULL

RETURNS: false if the object could not be properly initialized; 
true otherwise

NOTE: Whether *pString was allocated dynamically or statically
is unknown. *pString is owned by the client who uses 
the BST implementation, and deallocation of it 
is the responsibility of that client.
*/
bool StringDT_Set(StringDT* const pStringDT, const int* const key, char* pString) {

	assert(pStringDT != NULL);
	assert(pString != NULL);

	pStringDT->payload = pString;
	
	/* Intitialize the BSTNode 'Node' in this StingDT wrapper object */
	BSTNode_Init(&pStringDT->node, key);

	return true;
}