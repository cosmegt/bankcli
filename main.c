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

	valid_id	= (id > 0) ? 1 : 0;
	valid_pin	= (pin > 999) ? 1 : 0;

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

int action_loop(){
	while(1){

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

