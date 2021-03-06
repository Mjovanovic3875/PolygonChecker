/*
Week 14 Program 1 Assignment : Polygon Checker Group Assignment
Danny A. Smith, Emil Harvey, Milan Jovanovic
PROG71985- Fall 2020
December 2020

Revision History

1.0	NOVEMBER	 Files Created
1.1	NOVEMBER	 Triangle solver updated
1.2	NOVEMBER	 Inside angles functions completed
1.3	DECEMBER	 Tests written and triangle solver refactored
1.4	DECEMBER	 Get points from user function completed
1.5	December	 Get sides from points function completed
1.6	DECEMBER	 Refactored rectangle Checker
1.7	DECEMBER	 Refactored function names
1.8	DECEMBER	 Tests broken down into classes

Program Description :
	This program is designed to check shapes. It can currently take in triangle lines and determin the type of triangle and angles. It can also
	take in rectangle coordinates and decide if it is a rectangle or not. Future upgradability extends to checking other polygons.
*/

#include <stdio.h>
#include <stdbool.h>
#include "main.h"
#include "TriangleSolver.h"
#include "QuadrilateralSolver.h"


int main() {
	bool continueProgram = true; // for while loop
	while (continueProgram) {
		print_welcome();
		
		int shapeChoice = get_shape_choice();

		switch (shapeChoice)
		{
		case 0: // user selected exit
			continueProgram = false;
			break;
		case 1: // user selected a triangle
			printf_s("Triangle selected.\n");
			TRIANGLE triangle = triangle_wizard();
			print_triangle_information(triangle);
			break;

		case 2: // user selects quadrilateral
			printf_s("Quadrilateral selected.\n");
			QUADRILATERAL quadrilateral = quadrilateral_wizard();
			print_quadrilateral_information(quadrilateral);
			break;

		default:
			printf_s("Invalid value entered.\n");
			break;
		}
	} // while
	return 0;
}


void print_welcome() { // prints welcome to screen
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}


int get_shape_choice() { // print options to screen returns users choice
	printf_s("1. Triangle\n");
	printf_s("2. Quadrilateral\n");
	printf_s("0. Exit\n");

	int shapeChoice;
	scanf_s("%d", &shapeChoice);
	int c; while ((c = getchar()) != '\n' && c != EOF) {}// clears the get char buffer
	return shapeChoice;

}