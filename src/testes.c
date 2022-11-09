#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "stacks.h"
#include "parser.h"
#include "queries.h"

/*
float tempo (struct tm final, struct tm inicial){
    float r;
    float fim = (final.tm_hour * 60 * 60) + (final.tm_min * 60) + final.tm_sec;
    float inicio = (inicial.tm_hour * 60 * 60) + (inicial.tm_min * 60) + inicial.tm_sec;
    r = fim - inicio;
    return r;
}

float testaQ1(char *argv[], User *u, Ride *r, Driver *d){
    float r = 0;
    time_t t = time(NULL);
    struct tm inic = *localtime(&t);
    q1(argv[2], u, r, d);
    struct tm final = *localtime(&t);
    r = tempo(final, inic);
    if (r < 10){
        printf("Querry 1 em tempo útil %f\n", r);
    }
    else{
        printf("Querry 1 em tempo não útil %f\n", r);
    }
    return r;
}
*/