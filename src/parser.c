#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "stacks.h"

#define MAX_SZ_LINE 1024
#define DELIM ";"


int strtotime( char *datetime, struct tm *tm ){
    int dd, mm, yy;

    sscanf(datetime, "%d/%d/%d", &dd, &mm, &yy);
    //memset( &tm, 0, sizeof(struct tm) );
    tm->tm_mday=dd;
    tm->tm_year=yy - 1900;
    tm->tm_mon=mm;
    
    //time_t t = mktime(&tm);  // t is now your desired time_t

    return 1;
}


User *read_user(char *usersfile){
    User *u = NULL;
    User *prev = NULL;
    User *first = NULL;

    char *line = (char*) malloc(sizeof(char) * MAX_SZ_LINE);
    size_t lineSz = MAX_SZ_LINE;
    int i = 0;

    FILE* fp = fopen(usersfile,"r");
    if (fp != NULL){
        int lineNum=0;
        while ( getline(&line, &lineSz, fp )!=-1 ){
            lineNum++;
            if( lineNum>1 ){
                u = (User*)malloc(sizeof(User));
                u->next = NULL;

                char *token =  strtok( line, DELIM );
                
                int fieldId = 0;
                while ( token != NULL){
                    switch (fieldId)
                    {
                    case 0:
                        strncpy(u->username, token, MAX_SZ_ID);
                        break;
                    case 1:
                        strncpy(u->name, token, MAX_SZ_NAME);
                        break;
                    case 2:
                        u->gender = *token;
                        break;
                    case 3:
                        strtotime(token,&(u->birth));
                        break;
                    case 4:
                        strtotime(token,&(u->acount));
                        break;
                    case 5:
                        strncpy(u->pay, token, MAX_SZ_ID);
                        break;
                    case 6:
                        strncpy(u->status, token, MAX_SZ_ID);
                        break;
                    default:
                        break;
                    }
                    //printf("%s\t", token);
                    token =  strtok( NULL, DELIM );
                    fieldId++;
                    //strtotime( token );
                }
                if( prev != NULL ){
                    prev->next = u;
                }
                else{
                    first = u;
                }
                prev = u;
            }
        }
        fclose(fp);
    }
    free(line);

    return first;
}











Driver *read_driver(char *driversfile){
    Driver *d = NULL;
    Driver *prev = NULL;
    Driver *first = NULL;

    char *line = (char*) malloc(sizeof(char) * MAX_SZ_LINE);
    size_t lineSz = MAX_SZ_LINE;
    int i = 0;

    FILE* fp = fopen(driversfile,"r");
    if (fp != NULL){
        int lineNum = 0;
        while ( getline(&line, &lineSz, fp )!=-1){
            lineNum++;
            if (lineNum > 1){
                d = (Driver*)malloc(sizeof(Driver));
                d->next = NULL;

                char *token =  strtok( line, DELIM );
                
                int fieldId = 0;
                while ( token != NULL){
                    switch (fieldId)
                    {
                    case 0:
                        strncpy(d->id, token, MAX_SZ_ID);
                        break;
                    case 1:
                        strncpy(d->name, token, MAX_SZ_NAME);
                        break;
                    case 2:
                        strtotime(token,&(d->birth));
                        break;
                    case 3:
                        d->gender = *token;
                        break;
                    case 4:
                        strncpy(d->classe, token, MAX_SZ_ID);
                        break;
                    case 5:
                        strncpy(d->plate, token, MAX_SZ_ID);
                        break;
                    case 6:
                        strncpy(d->city, token, MAX_SZ_ID);
                        break;               
                    case 7:
                        strtotime(token,&(d->acount));
                        break;
                    case 8:
                        strncpy(d->status, token, MAX_SZ_ID);
                        break;
                    default:
                        break;
                    }
                    //printf("%s\t", token);
                    token =  strtok( NULL, DELIM );
                    fieldId++;
                    //strtotime( token );
                }
                if( prev != NULL ){
                    prev->next = d;
                }
                else{
                    first = d;
                }
                prev = d;
            }
        }
        fclose(fp);
    }
    free(line);

    return first;
}











Ride *read_ride( char * ridesFile ){
    Ride *r = NULL;
    Ride *prev = NULL;
    Ride *first = NULL;

    char *line = (char*) malloc(sizeof(char) * MAX_SZ_LINE);
    size_t lineSz = MAX_SZ_LINE;
    int i = 0;

    FILE* fp = fopen( ridesFile,"r");
    if (fp != NULL){
        int lineNum = 0;
        while ( getline(&line, &lineSz, fp )!=-1){
            lineNum++;
            if (lineNum > 1){
                r = (Ride*)malloc(sizeof(Ride));
                r->next = NULL;

                char *token =  strtok( line, DELIM );
                
                int fieldId = 0;
                while ( token != NULL){
                    switch (fieldId)
                    {
                    case 0:
                        strncpy(r->id, token, MAX_SZ_ID);
                        break;
                    case 1:
                        strtotime(token,&(r->date));
                        break;
                    case 2:
                        strncpy(r->driver, token, MAX_SZ_NAME);
                        break;
                    case 3:
                        strncpy(r->user, token, MAX_SZ_NAME);
                        break;
                    case 4:
                        strncpy(r->city, token, MAX_SZ_ID);
                        break;
                    case 5:
                        r->distance = atoi(token);
                        break;
                    case 6:
                        r->sUser = atoi(token);
                        break;               
                    case 7:
                        r->sDriver = atoi(token);
                        break;
                    case 8:
                        r->tip = atof(token);
                        break;
                    case 9:
                        strncpy(r->comment, token, MAX_SZ_NAME);
                    default:
                        break;
                    }
                    //printf("%s\t", token);
                    token =  strtok( NULL, DELIM );
                    fieldId++;
                    //strtotime( token );
                }
                if( prev != NULL ){
                    prev->next = r;
                }
                else{
                    first = r;
                }
                prev = r;
            }
        }
        fclose(fp);
    }
    free(line);

    return first;
}