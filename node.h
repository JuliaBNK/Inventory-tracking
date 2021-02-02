/*
 * Author: Olga Seymour
 */
#ifndef NODE_H
#define NODE_H

#include "groceryitem.h"

typedef struct node_t{
   grocery_item_t item;
   struct node_t* nextPtr;
   struct node_t* prevPtr;
}node_t;

node_t* initNode(grocery_item_t* i);

#endif
