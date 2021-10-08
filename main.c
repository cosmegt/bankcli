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

int sign_in(){
	int user_id;
	int user_pin;
	
	user_id 	= prompt_user_id();
	user_pin 	= prompt_user_pin();

	return 0;
}

int prompt_user_id(){
	int user_id;
	printf("Please enter your user id: ");
	scanf("%d", &user_id);
	printf("\n");
	
	return user_id;
}

int prompt_user_pin(){
	int pin;
	printf("Please enter your pin: ");
	scanf("%d", &pin);
	printf("\n");

	return pin;
}

void clearScreen(){
	const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e2J]"; //Inserting an expression that takes inserts the whole screen.
	write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}


int main(int argc[], char *argv[]){
	int signed_in;
	
	printf("Welcome to BankCLI.\n");
	signed_in = sign_in();
}

