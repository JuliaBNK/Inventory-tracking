/* 
 * File: date.c
 * Author: Olga Seymour
 */

#include "date.h"
#include <string.h>

/* getTodayDate: gets today's date 
 * Returns today's date
 */
date_t getTodayDate(){

	time_t t;     //declare argument for time
  
	//Variable to store return value of localtime():
	struct tm* ti;       
 
	time(&t);    //apply time
	ti = localtime(&t);
	date_t date;  //struct variable

	//Today's date:
	date.day = ti->tm_mday; //day of the month  
	date.month = ti->tm_mon + 1;
	date.year = ti->tm_year + 1900;

	return date;	
}
