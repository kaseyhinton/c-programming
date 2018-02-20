#include <stdio.h>
#include <stdlib.h>

void printMenu(){
	printf("Grab A Drink!!\n");	
	printf("Here are your choices..\n");	
	printf("coffee: 0\n");	
	printf("soda: 1\n");
	printf("tea: 2\n");	
	printf("water: 3\n");	
}

int main(int argc, char **argv)
{
	printMenu();
	printf("What type of drink would you like?\n");
	
	enum Drink {Coffee, Tea, Soda, Water};
	enum Drink drink;
	
	int i;
	char buffer[255];
	fgets(buffer, 255, stdin);
	i = atoi(buffer);
	
	if (i == 0) drink = Coffee;
	if (i == 1) drink = Tea;
	if (i == 2) drink = Soda;
	if (i == 3) drink = Water;
	
	switch(drink) {
		case 0:
		case 1:
			printf("Your Total Is $3.75.\n");
			break;
		case 2:
			printf("Your Total Is $2.50.\n");
			break;
		case 3:
			printf("No Charge.\n");
			break;
		default:
			printf("Please Select From The Menu.\n");
			printf("Valid choices are (0, 1, 2, 3)\n");
			break;
	}
	
	return 0;
}

