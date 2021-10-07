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

void welcome_message(){
	printf("Welcome to BankCLI.\n");

}

bool sign_in(){
	int user_id;
	printf("Please enter your user id: ");
	scanf("%d", &user_id);
	printf("\n ")
	return false;
}

void clearScreen(){
	const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e2J]";
	write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}


int main(int argc[], char *argv[]){
	bool signed_in;
	
	welcome_message();
	signed_in = sign_in();
}

