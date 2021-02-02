/* 
 * Author: Olga Seymour
 */
#include <stdio.h>
#include "list.h"
#include <stdlib.h>
#include "node.h"
#include "groceryitem.h"

/* createList: creates an empty doubly linked list
 * by setting count to 0 and the head and tail pointers 
 * to NULL.
 * Parameter listPtr pointer to structure
 * Returns nothing
 */
void createList(list_t* listPtr){
	if(listPtr != NULL){
                listPtr->headPtr = NULL;
                listPtr->tailPtr = NULL;
                listPtr->count  = 0;
	}
}
/* insertNode: inserts node at the head of the list.
 * Parameters
 *   listPtr point to the list structure
 *   nPtr points to the new node to insert in the list   
 * Pre-condition the node pointed to by nPtr has already
 * been allocated, has data in it, and has NULL next 
 * and previous pointers.
 * Returns nothing
 */
void insertNode(list_t* listPtr, node_t* nPtr){
	 if(listPtr != NULL){
                listPtr->count++;
                if(listPtr->headPtr == NULL){
                        listPtr->headPtr = nPtr;
                        listPtr->tailPtr = nPtr;                
		            }
                else{
                        nPtr->nextPtr = listPtr->headPtr;                        
			                  listPtr->headPtr->prevPtr = nPtr;
                       	listPtr->headPtr = nPtr;
    		        }	            
    }
}
/* traverseQueue: traverses and prints the data 
 * in the list from tail to head.
 * Parameter listPtr point to the list
 * Returns nothing
 */
void traverseQueue(const list_t* listPtr){
	node_t *curPtr;
        if (listPtr != NULL){
                curPtr = listPtr->tailPtr;
                while(curPtr != NULL){
			            printItem(curPtr->item);     
                  curPtr = curPtr->prevPtr;
                }
       }
}
/* deleteList: deletes entire list by deallocating all
 * of the memory for all of the nodes. It sets the head and tail
 * pointers to NULL to indicate an empty list.
 * Parameter listPtr pointer to the list
 * Returns nothing
 */
void deleteList(list_t* listPtr){
	node_t* curPtr;
        if(listPtr != NULL && listPtr->headPtr != NULL){
                curPtr = listPtr->headPtr;
                while(curPtr !=NULL){
                        listPtr->headPtr = curPtr->nextPtr;
                        free(curPtr);
                        curPtr = listPtr->headPtr;
                }
                listPtr->tailPtr = NULL;
        }
}
/* removeNode: removes node pointed to by nPtr
 * from the list and deallocates memory for it.
 * Parameters 
 *   listPtr pointer to the list
 *   nPtr points to the node to remove  
 * Returns nothing
 */
void removeNode(list_t* listPtr, node_t* nPtr){	
	if(listPtr->headPtr == nPtr){
		listPtr->headPtr = nPtr->nextPtr;
		if(listPtr->headPtr != NULL){
			listPtr->headPtr->prevPtr = NULL;
		}
		else
			listPtr->tailPtr = NULL;		
	  }
	  else if(nPtr == listPtr->tailPtr){
		listPtr->tailPtr = nPtr->prevPtr;
		listPtr->tailPtr->nextPtr = NULL;
	  }
	  else{
		nPtr->prevPtr->nextPtr = nPtr->nextPtr;
		nPtr->nextPtr->prevPtr = nPtr->prevPtr;
	  } 
	listPtr->count--;
	free(nPtr);      
 }
/*findNodeDelete: searches the list by bar
 * code, removes node calling removeNode 
 * Parameters 
 *   listPtr pointer to the list
 *   nodePtr points to the node to delete
 * Returns nothing
 */
void findNodeDelete(list_t* listPtr, node_t* nodePtr){
	node_t* curPtr;    //for item in the list  
	if(listPtr != NULL){   
		curPtr = listPtr->tailPtr;  
		while(curPtr != NULL){    
			
			//nodePtr for item input with bar code scanned; if found the scanned item:					
			if(strcmp(curPtr->item.barcode, nodePtr->item.barcode)== 0){  
      
				//Reducing the item quantity:
				curPtr->item.quantity = curPtr->item.quantity - nodePtr->item.quantity;

			  //Removing a node when its count reaches 0 (qty of item becomes 0):
        if(curPtr->item.quantity <= 0){   
				    removeNode(listPtr, curPtr);  //call function  				
				}
				return;
			}
			//if the bar code doesn't match, continue through one item at a time:
			curPtr = curPtr->prevPtr;    			
		}
	}
}	
/* traverseBestbyRemove: traverses, prints the data,
 * and removes nodes in the list from tail to head.   
 * Parameter listPtr points to the list
 * Returns nothing
 */
void traverseBestbyRemove(list_t* listPtr){
	node_t *curPtr;	
        	if (listPtr != NULL){             
                	curPtr = listPtr->tailPtr;
                	while(curPtr != NULL){
				            if(isExpired(curPtr->item)){
					            //Prints expired items pointed by curPtr:
					            printItem(curPtr->item);   
                      removeNode(listPtr, curPtr);
				            } 								
			            curPtr = curPtr->prevPtr; 
			            }                
		      }
}
/* traverseWrite: traverses and writes the data 
 * in the list from tail to head.
 * Parameter listPtr pointer to the list
 * Returns nothing
 */
void traverseWrite(const list_t* listPtr, char fileName[]){
    FILE* out;
	  //Open binary file for writing:
	  out = fopen(fileName, "wb");
	  node_t *curPtr;
        if (listPtr != NULL){
                curPtr = listPtr->tailPtr;
                while(curPtr != NULL){
		                fwrite(&curPtr->item, sizeof(curPtr->item), 1, out);					
                    curPtr = curPtr->prevPtr;
                }
		    fclose(out);
       }
}
