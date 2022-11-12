#ifndef _parser_H_
#define _parser_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int strtotime( char *datetime, struct tm *tm );
User *read_user(char *);
Driver *read_driver(char *);
Ride *read_ride(char *);

#endif