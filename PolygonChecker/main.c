#include <stdio.h>
#include <stdbool.h>

#include "main.h"

int side = 0;

void main() {
	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 1:
			printf("Triangle selected.\n");
			break;
		case 0:
			continueProgram = false;
			break;
		default:
			printf("Invalid value entered.\n");
			break;
		}
	}
}

void printWelcome() {
	printf(" **********************\n");
	printf("**     Welcome to     **\n");
	printf("**   Polygon Checker  **\n");
	printf(" **********************\n");
}

int printShapeMenu() {
	printf("1. Triangle\n");
	printf("0. Exit\n");

	int shapeChoice;

	printf("Enter number: ");
	scanf_s("%1o", &shapeChoice);

	return shapeChoice;
}