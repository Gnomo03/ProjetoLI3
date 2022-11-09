#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * stringcat( char *str1, char *str2 ){
    char *res = str1;
    int l1=0, l2=0;
    if( str1 ) l1 = strlen(str1);
    if( str2 ) l2 = strlen(str2);
    int lt = l1+l2;

    if( lt > 0){
        res = (char*)malloc(sizeof(char)*(lt+1));
        memset( res, 0, lt+1 );
        if( str1 ){
            strcpy(res, str1);
        }
        if( str2 ){
            strcat(res, str2);
        }
        if(str1) free(str1);
    }
    return res;
}


/// @brief Copy n chars from str2 to end of str1
/// @param str1 
/// @param str2 
/// @param len 
/// @return 
char * stringncat( char *str1, char *str2, int len ){
    char *res = str1;
    int l1=0, l2=0;
    if( str1 ) l1 = strlen(str1);
    if( str2 ) l2 = strlen(str2);
    if( l2 > len){
        l2 = len;
    }
    int lt = l1+l2;

    if( lt > 0){
        res = (char*)malloc(sizeof(char)*(lt+1));
        memset( res, 0, lt+1 );
        if( str1 ){
            strcpy(res, str1);
        }
        if( str2 ){
            strncat(res, str2, l2);
        }
        res[lt] = '\0';
        
        if(str1) free(str1);
    }
    return res;
}
