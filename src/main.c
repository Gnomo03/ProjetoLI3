#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "stacks.h"
#include "parser.h"
#include "queries.h"

#define MAX_FILE_NAME_SZ    1024
#define MAX_LINE_SZ         1024
#define MAX_ARGS            10

#define ERR_OK 0
#define ERR_NOT_ENOUGH_ARGS 1
#define ERR_CANT_OPEN_RESULTS_FILE 2
#define ERR_QUERY_NOT_IMPLEMENTED 3

char *errors[] = {
    "OK",
    "No arguments specified.\nUSAGE: <Query ID> [Args]",
    "Cannot open results file",
    "Query not implemented"
 };

int saveResult(char *resultFileName, char *resultLine){
    int resultCode = ERR_OK;

    FILE *fresult = fopen( resultFileName, "w+" );
    if(fresult){
        if( resultLine != NULL ){
            fprintf(fresult, "%s\n", resultLine );
        }
        fclose(fresult);
    }
    else{
        resultCode = ERR_CANT_OPEN_RESULTS_FILE;
    }    
}

int parseCommand( int argc, char *argv[], User *u, Ride *r, Driver *d, char *resultFileName ){
    int resultCode = ERR_OK;
    struct userQ1 *resultQ1 = NULL;

    if( argc < 3 ){
        return ERR_NOT_ENOUGH_ARGS;
        //printf("No arguments specified.\nUSAGE: <Query ID> [Args]");
    }
    else{
        int queryId = atoi(argv[1]);
        switch ( queryId ) {
            case 1:
                resultQ1 = q1(argv[2], u, r, d);
                if( resultQ1 != NULL ){
                    char resultLine[ MAX_LINE_SZ ];
                    sprintf( resultLine, "%s;%c;%d;%0.3f;%d;%0.2f\n", 
                            resultQ1->name,
                            resultQ1->gender,
                            resultQ1->age,
                            resultQ1->avg_score,
                            resultQ1->travel_count,
                            resultQ1->total_cost );
                    free(resultQ1);
                    //
                    if( resultFileName == NULL ){
                        printf("%s\n", resultLine);
                    }
                    else{
                        saveResult(resultFileName, resultLine);
                    }
                }
                else{
                    saveResult(resultFileName, NULL );
                }
                break;
            
            default:
                resultCode = ERR_QUERY_NOT_IMPLEMENTED;
                //printf("%s: Not implemented\n", argv[1]);
                break;
        }
        return resultCode;
    }
}

int processCommandFile (FILE *file, User* u, Ride *r, Driver *d ){
    char *args[MAX_ARGS];
    char line[MAX_LINE_SZ];
    int lineNumber = 0;
    
    if( file ){
        while (fgets(line, sizeof(line), file)) {
            lineNumber++;
            char *tok = strtok( line, " " );
            int i = 0;
            args[i++] = NULL; // just to keep compatiblity with command line
            while (tok != NULL ){
                int strsz=strlen(tok);
                args[i] = malloc(sizeof(char)*strsz + 1);
                int ii=0;
                char c = tok[ii];
                while( c !='\0' && c != '\n' ){
                    args[i][ii] = c;
                    c = tok[++ii];
                }
                args[i++][ii] = '\0';
                tok = strtok( NULL, " " );
            }
            char resultFileName[ MAX_FILE_NAME_SZ ];
            sprintf(resultFileName,"results/command%d_output.txt", lineNumber);
            // i=number os elements read
            int parseResult = parseCommand(i, args, u, r, d, resultFileName);
            // Frees args
            for( int ii=0; ii<i; ii++ ){
                if( args[ii]){
                    free(args[ii]);
                    args[ii]=NULL;
                }
            };
            if( parseResult ){
                printf("Line %d: %s\n", lineNumber, errors[parseResult]);
            }
        }
    }
    return lineNumber;
}


int main( int argc, char *argv[] )  {
    // Batch mode
    // argv[1] --> Input file folder
    // argv[2] --> command file
    //
    // Single mode --> Menu

    if( argc < 3 ){
        printf("No arguments specified.\nUSAGE: <Input files folder> <Command file>");
    }
    else{
        char *inputFolder = argv[1];
        char *commandFile = argv[2];
        
        char filename[MAX_FILE_NAME_SZ];
        sprintf( filename, "%s/users.csv", inputFolder );
        User *u = read_user(filename);
        sprintf( filename, "%s/drivers.csv", inputFolder );
        Driver *d = read_driver(filename);
        sprintf( filename, "%s/rides.csv", inputFolder );
        Ride *r = read_ride( filename );

        //User *u = read_user("Dataset_Fase1/users.csv");
        //Driver *d = read_driver("Dataset_Fase1/drivers.csv");
        //Ride *r = read_ride( "Dataset_Fase1/rides.csv" );

        // Read command file and parse + execute
        FILE *fp = fopen(commandFile, "r");
        if( fp != NULL ){
            processCommandFile( fp, u, r, d );
            fclose(fp);
        }
        else{
            printf("Cannot open command file: %s\n", commandFile);
        }
    }


    /*
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
    */
    return 0;
}

