/* 
 * Author: Olga Seymour
 */
#ifndef  LIST_H
#define LIST_H
#include "node.h"

typedef struct {
   node_t* headPtr;
   node_t* tailPtr;
   int count;
} list_t;

void createList(list_t* listPtr);
void insertNode(list_t* listPtr, node_t* nPtr);
void traverseQueue(const list_t* listPtr);
void deleteList(list_t* listPtr);
void removeNode(list_t* listPtr, node_t* nPtr);
void traverseBestbyRemove(list_t* listPtr); 
void traverseWrite(const list_t* listPtr, char fileName[]);
void findNodeDelete(list_t* listPtr, node_t* nodePtr);

#endif
