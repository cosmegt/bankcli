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

int create_user(char id[]){
    struct stat st = {0};

    char newdir[] = "./users/";
    strcat(newdir, id);

    if (stat(newdir, &st)  == -1){
        mkdir(newdir, 0700);
        return 1;
    } else{
        printf("Fuck your id.");
        return 0;
    }

}

int check_user(){

}

int auth0(){

}

int read_balance(){

}

int write_balance(){

}

#endif