/**
 * A quick library for BankCLI
 * We're using the file system as a database to store users, passwords, and balance
 *
*/

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

int read_balance(char *path){ // Remeber that for string you have to pass the pointer
    int num;

    FILE *file = fopen(path, "r");
    fscanf (file, "%d", &num);
    fclose(file);
    
    return num;
} 

int deposit_balance(char *path, int value){
    int current, sum;

    FILE *file = fopen(path, "r");
    fscanf(file, "%d", &current);
    freopen(path, "w", file); //Clear content

    sum = current + value;

    fprintf(file, "%d", sum);

    fclose(file);

    printf("Your new balance is: $%d", sum);
    return sum;
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
