/* 
 * File: date.h
 * Author: Olga Seymour
 */
#ifndef DATE_H
#define DATE_H
#include <time.h>

typedef struct {
   int month, day, year;
} date_t;

date_t getTodayDate();

#endif
