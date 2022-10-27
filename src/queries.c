#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "stacks.h"
#include "parser.h"
#include "queries.h"

struct tm localt (){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    return tm;
}

int getAge (struct tm hoje, struct tm birth){
    int res = hoje.tm_year - birth.tm_year;
    if (hoje.tm_mon == birth.tm_mon){
        if (hoje.tm_mday < birth.tm_mday){
            res = res - 1;
        }
    }
    else if (hoje.tm_mon < birth.tm_mon){
        res = res - 1;
    }
    return res;
}

//User Functions
User *getUser(User *users, char *username){
    User *result = users;

    while ( result != NULL ){
        if(strcmp(result->username, username)==0){
            break;;
        }
        result = result->next;
    }
    return result;
}

//Driver Functions
Driver *getDriver(Driver *drivers, char *id){
    Driver *result = drivers;

    while ( result != NULL ){
        if(strcmp(result->id, id)==0){
            break;;
        }
        result = result->next;
    }
    return result;
}

float getRideCost( Ride *ride, Driver *drivers){
    Driver *d = drivers;
    float result = 0;

    while ( d!=NULL ){
        if( strcmp( d->id, ride->driver ) == 0  ){
            float tripCost = 0;
            if( strcasecmp(d->classe, "Basic") == 0 ){
                tripCost = 3.25 + 0.62*ride->distance;
            }
            else if( strcasecmp(d->classe, "Green") == 0 ){
                tripCost = 4.00 + 0.79*ride->distance;
            }
            else if( strcasecmp(d->classe, "Premium") == 0 ){
                tripCost = 5.20 + 0.94*ride->distance;
            }
            result = ride->tip + tripCost;
            //
            break;
        }
        d = d->next;
    }
    return result;
}


// Don't forget to free the result after use
struct userQ1 *q1(char *username, User *users, Ride *rides, Driver *drivers){
    struct userQ1 *result = NULL;

    if (atoi(username) == 0){
        User *u = getUser( users, username);
        if( u != NULL){
            result = malloc(sizeof(struct userQ1));
            
            strncpy( result->username, u->username, MAX_SZ_NAME);
            strncpy( result->name, u->name, MAX_SZ_NAME);
            result->gender = u->gender;
            // age
            struct tm today = localt(); 
            result->age = getAge(today, u->birth);

            Ride *r = rides;
            int rideCount = 0;
            float rideCost = 0;
            float rideScore = 0;        
            
            while( r != NULL ){
                if( strcmp(r->user, username) == 0  ){
                    rideCount++;
                    rideScore +=r->sUser;
                    rideCost += getRideCost( r, drivers);
                }
                r = r->next;
            }
            result->avg_score = rideScore / rideCount;
            result->travel_count = rideCount;
            result->total_cost = rideCost;
        }
    }
    else{
        Driver *d = getDriver( drivers, username);
        if( d != NULL && strcasecmp(d->status,"active\n") == 0){
            result = malloc(sizeof(struct userQ1));
            
            strncpy( result->username, d->id, MAX_SZ_NAME);
            strncpy( result->name, d->name, MAX_SZ_NAME);
            result->gender = d->gender;
            // age
            struct tm today = localt(); 
            result->age = getAge(today, d->birth);

            Ride *r = rides;
            int rideCount = 0;
            float rideCost = 0;
            float rideScore = 0;        
            
            while( r != NULL ){
                if( strcmp(r->driver, username) == 0  ){
                    rideCount++;
                    rideScore +=r->sDriver;
                    rideCost += getRideCost( r, drivers);
                }
                r = r->next;
            }
            result->avg_score = rideScore / rideCount;
            result->travel_count = rideCount;
            result->total_cost = rideCost;  
        }
    }
    return result;

    // struct driverQ2 *q2(char *id, Ride *rides, Driver *drivers){
       // struct driverQ2 *result = NULL;
    
}
