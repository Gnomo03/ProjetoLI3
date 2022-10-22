#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "stacks.h"
#include "parser.h"
#include "queries.h"


int main( int argc, char *argv[] )  {
    if( argc <=1 ){
        printf("No arguments specified.\nUSAGE: <Query ID> [Args]");
    }
    else{
        User *u = read_user("Dataset_Fase1/users.csv");
        Driver *d = read_driver("Dataset_Fase1/drivers.csv");
        Ride *r = read_ride( "Dataset_Fase1/rides.csv" );

        struct userQ1 *result = NULL;
        int queryId = atoi(argv[1]); 
        switch ( queryId ) {
            case 1: 
                result = q1(argv[2], u, r, d);
                if( result != NULL ){
                    printf("%s;%c;%d;%0.3f;%d;%0.2f\n", 
                            result->name,
                            result->gender,
                            result->age,
                            result->avg_score,
                            result->travel_count,
                            result->total_cost );
                    free(result);
                }
                break;
            
            default:
                printf("%s: Not implemented\n", argv[1]);
                break;
        }
    } 

//int main(){

    /*
    while (u != NULL){
        printf("%s\t", u->username);
        printf("%s\t", u->name);
        printf("%c\t", u->gender);
        printf("%02d/%02d/%04d\t", u->birth.tm_mday, u->birth.tm_mon, u->birth.tm_year);
        printf("%02d/%02d/%04d\t", u->acount.tm_mday, u->acount.tm_mon, u->acount.tm_year);
        printf("%s", u->status);
        u = u->next;
    }
    
    while (d != NULL){
        printf("%s\t", d->id);
        printf("%s\t", d->name);
        printf("%02d/%02d/%04d\t", d->birth.tm_mday, d->birth.tm_mon, d->birth.tm_year);
        printf("%c\t", d->gender);
        printf("%s\t", d->classe);
        printf("%s\t", d->plate);
        printf("%s\t", d->city);
        printf("%02d/%02d/%04d\t", d->acount.tm_mday, d->acount.tm_mon, d->acount.tm_year);
        printf("%s\n", d->status);
        d = d->next;
    }
    
    while (r != NULL){
        printf("%s\t", r->id);
        printf("%02d/%02d/%04d\t", r->date.tm_mday, r->date.tm_mon, r->date.tm_year);
        printf("%s\t", r->driver);
        printf("%s\t", r->user); 
        printf("%s\t", r->city);
        printf("%d\t", r->distance);
        printf("%d\t", r->sUser);
        printf("%d\t", r->sDriver);
        printf("%03f\t", r->tip);
        printf("%s\n", r->comment);
        r = r->next;
    }
    */
    return 0;
}

