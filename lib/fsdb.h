/**
 * Querying CSV files in C
 * A quick library for BankCLI
 *
*/

#ifndef fsdb_h
#define fsdb_h

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int check_user(char id[]){
    struct stat st = {0};

    char newdir[] = "./users/";
    strcat(newdir, id);

    if (stat(newdir, &st) == -1){
        return 1;
    }else{
        return 0;
    }
}

int read_int_from_file(char *path){
    int num = 0;

    FILE *file = fopen(path, "r");
    fscanf (file, "%d", &num);
    return num;
} 

int auth0(char id[], char pin[]){

    int user_exists = check_user(id);
    if(user_exists){
        FILE *fp;

        char newdir[] = "./users/";
        strcat(newdir, id);
        strcat(newdir, "password");
        
        fp = fopen(newdir, "r");
    }
}

int change_pw(){

}


int create_user(char id[]){
    int user_exists = check_user(id);
    
    if (user_exists == 0){
        char newdir[] = "./users/";
        strcat(newdir, id);
        
        mkdir(newdir, 0700);
        return 1;
    } else{
        printf("Fuck your id.");
        return 0;
    }

}

int read_balance(){

}

int write_balance(){

}

#endif