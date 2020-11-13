#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "triangleSolver.h"

int side = 0;

int main() {
	bool continueProgram = true; // for while loop
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 1:
			printf_s("Triangle selected.\n");
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			//printf_s("! %d\n", triangleSidesPtr[0]);
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf_s("\n%s\n", result);
			break;
		case 0:
			continueProgram = false;
			break;
		default:
			printf_s("Invalid value entered.\n");
			break;
		}
	} // while
	return 0;
}

void printWelcome() { // prints welcome to screen
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}

int printShapeMenu() { // print options to screen returns users choice
	printf_s("1. Triangle\n");
	printf_s("0. Exit\n");

	int shapeChoice;
	scanf_s("%d", &shapeChoice);

	return shapeChoice;

	}


int* getTriangleSides(int* triangleSides) { // get sides of triangle from user
	printf_s("Enter the three sides of the triangle: \n");
	for (int i = 0; i < 3; i++)
	{
		printf_s("\nEnter the %d sides of the triangle: ", (i+1));
		scanf_s("%d", &triangleSides[i]); // very poor UI | Fixed
	}
	return triangleSides;
}