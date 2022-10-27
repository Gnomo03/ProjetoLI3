#ifndef _stacks_H_
#define _stacks_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SZ_NAME 250
#define MAX_SZ_ID 250

typedef struct user{
    char username[MAX_SZ_ID];                   //username do usuário
    char name[MAX_SZ_NAME];                    //nome real do usuário
    char gender;                              //genero do usuário
    struct tm birth;                          //data de aniversario do usuário
    struct tm acount;                        //date da criação de conta do usuário
    char pay[MAX_SZ_ID];                     //metodo de pagamento do usuário
    char status[MAX_SZ_ID];                 //estatos da conta do usuário (ativa ou não ativa)
    struct user *next;
} User;


typedef struct driver{
    char id[MAX_SZ_ID];                     //id do usuário
    char name[MAX_SZ_NAME];                 //nome real do usuário
    struct tm birth;                        //data de aniversario do usuário
    char gender;                            //genero do usuário
    char classe[MAX_SZ_ID];                //classe do carro do usuário
    char plate[MAX_SZ_ID];                 //matricula do carro do usuário
    char city[MAX_SZ_ID];                 //cidade do usuário
    struct tm acount;                     //date da criação de conta do usuário
    char status[MAX_SZ_ID];                    //estatos da conta do usuário (ativa ou não ativa)
    struct driver *next;
} Driver;


typedef struct ride{
    char id[MAX_SZ_ID];                     //id do usuário
    struct tm date;                         //data da viagem
    char driver[MAX_SZ_NAME];               //id do usuário
    char user[MAX_SZ_NAME];                 //username do usuário
    char city[MAX_SZ_ID];                   //cidade do usuário
    int distance;                           //distância precorrida em km
    int sUser;                              //avaliação dos clientes ao usuário (1-5)
    int sDriver;                            //avaliação do usuário (1-5)
    float tip;                              //grojeta dada ao usuário
    char comment[MAX_SZ_NAME];              //comentário dado ao usuário
    struct ride *next;
} Ride;

#endif