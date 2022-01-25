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

int withdrawal_balance(char *path, int value){
    int current, sub;

    FILE *file = fopen(path, "r");
    fscanf(file, "%d", &current);
    freopen(path, "w", file);

    sub = current - value;
    sub = (sub >= 0) ? sub :  current;

    fprintf(file, "%d", sub);

    fclose(file);
     
    printf("Your new balance is: $%d", sub);
    return sub;

}