/*
 * Author: Olga Seymour
 */
#include "node.h"
#include <stdlib.h>

/* initNode: dynamically allocates a node
 * and initializes i, the nextPtr, and the
 * prevPtr of a this new node that
 * isn't yet in a list.
 * Parameter i data
 * Returns pointer to newly created node
 */
node_t* initNode(grocery_item_t* i){
        node_t* nodePtr = (node_t*)malloc(sizeof(node_t));        
	nodePtr->item = *i;
        nodePtr->nextPtr = NULL;
        nodePtr->prevPtr = NULL;
        return nodePtr;
}
