#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "triangleSolver.h"
#include "SquareSolver.h"

int side = 0;

int main() {
	bool continueProgram = true; // for while loop
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 1: // user selected a triangle


			printf_s("Triangle selected.\n");
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides); // get triangle sides from user
			//printf_s("! %d\n", triangleSidesPtr[0]);
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]); // what kind of triangle
			double* angles = insideAngles(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]); // store angles of given sides
			printf_s("\n%s\nThe angles are : %f, %f, %f", result, angles[0],angles[1],angles[2]);
			break;
		case 2: // user selects rectangle
			printf_s("Square selected.\n");
			
			COORDINATE SquareSides = { .x = {0,0,0,0},.y = {0,0,0,0} };
			SquareSides = getSquareSides(SquareSides); // get Square coordinates from user
			if (isRectangle) {
				int perimiter = 0;
				perimiter = getPerimiter(SquareSides);
				int area = 0;
				area = getArea(SquareSides);
				printf_s("The perimiter is %d\nThe Area is : %d\n",perimiter,area);
			}
			else {
				printf_s("This is not a rectangle...");
			}
			break;
		
		case 0: // user selected exit
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
	printf_s("2. Square\n");
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