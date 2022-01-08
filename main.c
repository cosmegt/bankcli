/**
 * BankCLI main.c
 * We attempt to make a banking system.
 * The system should be able to deposit, withdrawal, and check balance.
 * The banking system has a user system with a pin and user_id to do operations
 * That's it for now.
 *
 * This is just C language practice.
 *
 * Author: Cosme Chavez
 * */


#include <stdio.h>
#include <unistd.h>

#include "./lib/fsdb.h"

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

void clearScreen(){
	const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e2J]"; //Inserting an expression that takes inserts the whole screen.
	write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}

int sign_in(){
	int user_id, user_pin, valid_id;
	
	user_id		= prompt_user_id();
	user_pin	= prompt_user_pin();

	valid_id = validate_input(user_id, user_pin);

	if(valid_id){
		return user_id;
	}else {
		return 0;
	}
}

int view_balance(){
	
	printf("You chose to view balance: ");
	// printf("bitch before a");
	// char a[] = "./users/11/balance.txt";
	// printf("bitch after a");
	// read_int_from_file(a);

	return 0;

}

int deposit(){
	printf("You chose to deposit: ");
	return 0;
}

int withdrawal(){
	printf("You chose to withdrawal: ");
	return 0;
}

int action_loop(){

	while(1){
		int choose;
		printf("What would you like to do? \n");
		printf("1. View Balance		2. Deposit		3. Withdrawal \n");
		scanf("%d", &choose);

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
	}
}


int main(int argc[], char *argv[]){
	int user;
	
	printf("Welcome to BankCLI.\n");
	user = sign_in();
	if (user > 0){
		printf("Welcome user, %d.\n", user);
		action_loop();
	}
	else{
		return 0;
	}
}

