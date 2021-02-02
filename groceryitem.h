/* 
 * Author: Olga Seymour
 */
#ifndef  GROCERY_ITEM_H
#define GROCERY_ITEM_H 
#include <string.h>
#include "date.h"

#define MAX_BARCODE_SIZE 15
#define MAX_NAME_SIZE 256

typedef struct {
   char barcode[MAX_BARCODE_SIZE];
   char name[MAX_NAME_SIZE];
   int quantity;
   date_t bestBy;
} grocery_item_t;

void printItem(const grocery_item_t i);

int isExpired(grocery_item_t i);

#endif
