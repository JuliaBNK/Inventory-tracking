/*
 * Lab2
 * Author: Olga Seymour
 * Date: 10/03/2020
 */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "node.h"
#include "date.h"
#include "groceryitem.h"
#include <time.h>
#include <string.h>

#define MAX_LENGTH 30     

int main(int argc, char* argv[]) {
   	list_t list;
   	node_t* nodePtr;
   	grocery_item_t i;    
    
	  FILE *in;

	  char filename[MAX_LENGTH];
   
		if(argc < 2){                    
		printf( "Usage: lab2 filename\n");
		
		return (0);
	  }
	  else{  
		  strcpy(filename, argv[1]);   
		  in = fopen(filename, "rb" );                    	      
    }
	  if(in == NULL){    
		  printf( "Input file %s doesn't exist. Please contact the administrator.\n", filename);
		  return (0);	
	  }
	
	 fseek(in, 0, SEEK_END);   
	 if(in){            
	    if(ftell(in) == 0){   //If file is empty: 				
			  printf( "Input file %s is empty. Please contact the administrator.\n", filename);
			  return (0);
      }	
	}
	 
	fseek(in, 0, SEEK_SET);   
	
	if(in != NULL){
		createList(&list);
		fread(&i, sizeof(grocery_item_t), 1, in);   
		while( !feof(in )){
			nodePtr = initNode(&i);                
			insertNode(&list, nodePtr);
			list.count++;
		fread(&i, sizeof(grocery_item_t), 1, in);
		}
	}
	fclose(in);
	        
     char choice;                

                printf("\nA Add to inventory \n");
                printf("D Delete itmes from inventory \n");
                printf("B Print expired items and remove from inventory \n");
                printf("P Print inventory \n");
                printf("Q Quit \n");   
		choice = getchar();                
		getchar();
    do{
        switch(choice){
                        
			    case 'A':
			    case 'a':					              
            printf("Bar code: ");
            scanf("%s", i.barcode);
					  getchar();              
            printf("Description: ");
				
				   fgets(i.name, MAX_NAME_SIZE, stdin);    
           i.name[strlen(i.name) - 1] = '\0'; 
				   printf("Quantity: ");
           scanf("%d", &i.quantity);
           printf("Best by date: ");
           scanf("%d%d%d", &i.bestBy.month, &i.bestBy.day, &i.bestBy.year);
           getchar();      
				   nodePtr = initNode(&i);
				
          //Add an item to the list:
          insertNode(&list, nodePtr);  
				  break;
			  case 'D':
			  case 'd':				
          printf("Bar code: ");
          scanf("%s", i.barcode);
          printf("Quantity: ");
				  scanf("%d", &i.quantity);
				  getchar();    
          nodePtr = initNode(&i);
				  
          //Deleting from inventory due to purchase:
          findNodeDelete(&list, nodePtr); 
				  break;
			  case 'B':
			  case 'b':                		
          //Deleting from inventory and printing
				  //expired items:
				  getTodayDate();
          traverseBestbyRemove(&list);
				  break;
			  case 'P':
			  case 'p':		          
          traverseQueue(&list);
				  break;
			  case 'Q':
			  case 'q':
				  break;
			  default:
        
        //Invalid menu option:
				printf("%c is invalid choice. Try again.\n", choice); 
				break; 
		}
    
		if(choice !='Q' && choice != 'q'){
			 printf("\nA Add to inventory \n");
                	 printf("D Delete itmes from inventory \n");
                	 printf("B Print expired items and remove from inventory \n");
                	 printf("P Print inventory \n");
                	 printf("Q Quit \n");
                	 choice = getchar();   
			 getchar();
     }	            
  }while(choice != 'Q' && choice != 'q');
		 		                                        				
  //Writes the updated inventory to the binary file: 	
	traverseWrite(&list, filename);

	deleteList(&list);  //deallocates resources	
       
   return 0;
}
