#include <stdio.h>
#include <string.h>

int main() {
	char command[32];
	char arg1[32];
	char arg2[32];
	int selection;
	printf("Please enter one of the following DOS commands: cd, dir, type, del, ren, copy\n");

	while (1) {
		//zero-ize command
		for (int i = 0; i < 32; i++) {
			command[i] = 0;
		}
		//scan command from user input
		scanf("%s", command);
		//determine selection based on user input
		if (command[0] == 'c' && command[1] == 'd') {
			selection = 1;
		}
		else if (command[0] == 'd' && command[1] == 'i' && command[2] == 'r') {
			selection = 2;
		}
		else if (command[0] == 't' && command[1] == 'y' && command[2] == 'p' && command[3] == 'e') {
			selection = 3;
		}
		else if (command[0] == 'd' && command[1] == 'e' && command[2] == 'l') {
			selection = 4;
		}
		else if (command[0] == 'r' && command[1] == 'e' && command[2] == 'n') {
			selection = 5;
		}
		else if (command[0] == 'c' && command[1] == 'o' && command[2] == 'p' && command[3] == 'y') {
			selection = 6;
		}
		else if (command[0] == 'm' && command[1] == 'k' && command[2] == 'd' && command[3] == 'i' && command[4] == 'r') {
			selection = 7;
		}
		else { selection = 8; }
		//switch statement based on selection from user input
		switch (selection) {
		case 1: //cd
			strcat(command, " ");
			scanf("%s", arg1);
			strcat(command, arg1);
			system(command);
			printf("Current directory changed to %s.\n", arg1);
			break;

		case 2: //dir
			command[0] = '\0';
			strcat(command, "ls ");
			system(command);
			printf("Current directory listed.\n");
			break;

		case 3: //type
			command[0] = '\0';
			strcat(command, "cat ");
			scanf("%s", arg1);
			strcat(command, arg1);
			system(command);
			printf("File %s read.\n", arg1);
			break;

		case 4: //del
			command[0] = '\0';
			strcat(command, "rm ");
			scanf("%s", arg1);
			strcat(command, arg1);
			system(command);
			printf("File %s deleted.\n", arg1);
			break;

		case 5: //ren
			command[0] = '\0';
			strcat(command, "mv ");
			scanf("%s", arg1);
			strcat(command, arg1);
			strcat(command, " ");
			scanf("%s", arg2);
			strcat(command, arg2);
			system(command);
			printf("File %s renamed to %s.\n", arg1, arg2);
			break;

		case 6: //copy
			command[0] = '\0';
			strcat(command, "cp ");
			scanf("%s", arg1);
			strcat(command, arg1);
			strcat(command, " ");
			scanf("%s", arg2);
			strcat(command, arg2);
			system(command);
			printf("File %s copied to %s.\n", arg1, arg2);
			break;

		case 7: //mkdir
			strcat(command, " ");
			scanf("%s", arg1);
			strcat(command, arg1);
			system(command);
			printf("Created new directory named %s.\n", arg1);
			break;

		case 8: printf("Not a valid input.\nPlease enter one of the following DOS commands: cd, dir, type, del, ren, copy\n");
			break;

		}//end of switch

		//Ctrl+C to exit
		printf("Thank you for your selection. Please enter another command or use Ctrl+C to exit\n");
	}//end of while-loop
	return 0;
}//end of main
