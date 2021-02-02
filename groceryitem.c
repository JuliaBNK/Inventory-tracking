/* 
 * Author: Olga Seymour
 */
#include <stdio.h>
#include "groceryitem.h"
#include <stdlib.h>
#include "date.h"

/* printItem: prints a grocery item
 * Parameter i grocery item
 * Returns nothing
 */       
void printItem(const grocery_item_t i){
	printf("%s %s %d %d %d %d\n", i.barcode, i.name, i.quantity, 
	i.bestBy.month, i.bestBy.day, i.bestBy.year);
}
/* isExpired: returns true for expired item                         
 * Parameter i grocery item              
 * Returns true if items is expired
 */
int isExpired(grocery_item_t i){
 
        date_t date = getTodayDate(); //call today's date
        if(i.bestBy.year < date.year){
        	return (1);
}
        if(i.bestBy.year > date.year){
                return (0);
        }
        if(i.bestBy.month < date.month){
                return (1);
        }
        if(i.bestBy.month > date.month){
                return (0);
	      }
        if(i.bestBy.day < date.day){
                return (1);
        }
        else {		   //if(i.bestBy.day > date.day)
        return (0);	
        }
}
