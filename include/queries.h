#ifndef _queries_H_
#define _queries_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "stacks.h"

struct userQ1{
    char username [MAX_SZ_ID];
    char name[MAX_SZ_NAME];
    char gender;
    int age;
    float avg_score;
    int travel_count;
    float total_cost;
};

struct userQ1 *q1(char *username, User *users, Ride *rides, Driver *drivers);

#endif