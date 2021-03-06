/**
 * BankCLI main.c
 * We attempt to make a banking system.
 * The system should be able to deposit, withdrawal, and check balance.
 * The banking system has a user system with a pin and user_id to do operations
 * That's it for now.
 *
 * This is just C language practice.
 * 
 * Update 1/25/2022 - I've learned a lot and this program's main functionality is done.
 * Continuing this project is difficult because I did not knew anything about C structutures.
 * If I had known better, I would have made a structure for a user, database, view-states.
 * If you're reading this code, don't see this as a reflection of poor OOP design.
 * Rather, a lack of understanding of structures in C.
 *
 * Author: Cosme Chavez
 * */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "./lib/fsdb.h"

// Authentication methods

int prompt_user_id(){
	int user_id;
	printf("Please enter your user id: ");
	scanf("%d", &user_id);
	
	return user_id;
}

int prompt_user_pin(){
	int pin;
	printf("Please enter your pin: ");
	scanf("%d", &pin);

	return pin;
}

int validate_input(int id, int pin){
	int valid_id, valid_pin;

	valid_id	= (id > 0);
	valid_pin	= (pin > 999);

	return (valid_id && valid_pin);

}

int sign_in(){
	int user_id, user_pin, valid_id, result;
	
	user_id		= prompt_user_id();
	user_pin	= prompt_user_pin();

	valid_id = validate_input(user_id, user_pin);

	return valid_id || 0;

}

int sign_up(){
	int new_id;

	new_id = rand() % 100 + 1;
	// create_user(new_id);

	return 0;
}

void prompt_continue(){
	int option;
	printf("\nWould you like to continue? \n");
	printf("1. Continue		2. Quit \n");
	scanf("%d", &option);

	if(option == 2){
		exit(0);
	}


}

int authentication(){
	int existing, user;
	printf("Are you an existing user?\n");
	printf("1. Yes		2. No");
	scanf("%d", &existing);

	if(existing == 1){
		user = sign_in();
		return user;
	}
	else{
		// user = sign_up();
		return 0;
	}

}

// View methods

void clear_screen(){
	system("clear");
}


// Banking methods

int view_balance(){

	char a[] = "./build/users/11/balance.txt";
    int balance = read_balance(a);
    
	printf("Your balance is: $%d\n",balance);

    return 0;

}

int deposit(){
	int dollars, balance;
	char a[] = "./build/users/11/balance.txt";

	printf("How much would you like to deposit? \n");
	printf("Enter ammount in dollars: ");
	scanf("%d", &dollars);

	balance = deposit_balance(a, dollars);

	return 0;
}

int withdrawal(){
	int dollars, balance;
	char a[] = "./build/users/11/balance.txt";

	printf("How much would you like to widthdrawal? \n");
	printf("Enter ammount in dollars: ");
	scanf("%d", &dollars);

	balance = withdrawal_balance(a, dollars);

	return 0;
}

// Main program methods

int action_loop(){

	while(1){
		int choose;
		clear_screen();
		printf("What would you like to do? \n");
		printf("1. View Balance		2. Deposit		3. Withdrawal \n");
		scanf("%d", &choose);
		clear_screen();

		switch(choose){
			case(1): view_balance();
				break;
			case(2): deposit();
				break;
			case(3): withdrawal();
				break;
			default: printf("You must choose between, 1,2, or 3.\n");
				break;
		}

		prompt_continue();

	}
}


int main(int argc[], char *argv[]){
	int user;
	
	clear_screen();
	printf("Welcome to BankCLI.\n");
	user = authentication();
	if (user > 0){
		printf("Welcome user, %d.\n", user);
		action_loop();
	}
	else{
		return 0;
	}
}

