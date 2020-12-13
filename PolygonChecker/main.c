#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "TriangleSolver.h"
#include "SquareSolver.h"

int main() {
	bool continueProgram = true; // for while loop
	while (continueProgram) {
		printWelcome();
		
		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 0: // user selected exit
			continueProgram = false;
			break;
		case 1: // user selected a triangle


			printf_s("Triangle selected.\n");
			TRIANGLE* triangle = triangle_wizard();
			print_triangle_information(triangle);
			free_triangle(triangle);

			// Old code
			/*
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides); // get triangle sides from user
			//printf_s("! %d\n", triangleSidesPtr[0]);
			char* result = analyze_triangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]); // what kind of triangle
			double* angles = inside_angles_radians(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]); // store angles of given sides
			printf_s("\n%s\nThe angles are : %f, %f, %f", result, angles[0],angles[1],angles[2]);
			*/
			break;

		case 2: // user selects rectangle
			printf_s("\nSquare selected.\n");
			QUADRILATERAL quadrilateral = quarilateral_wizard();
			bool isRectangle = is_rectangle(quadrilateral);

			if (isRectangle)
			{
				double left_line = get_left_line(quadrilateral);
				double top_line = get_top_line(quadrilateral);
				double perimeter = get_perimeter(left_line, top_line);
				double area = get_area(left_line, top_line);

				printf("This is a rectangle.\n");
				printf("Its perimeter is %lf\n", perimeter);
				printf("Its area is %lf\n", area);
			}
			else
			{
				printf_s("This is not a rectangle..."); // was not a rectangle
			}
			break;

			/*
			QUADRILATERAL SquareSides = { .x = {0,0,0,0},.y = {0,0,0,0}, .top_line = 0,.bottom_line = 0,.left_line =0, .right_line =0};
			SquareSides = getSquareSides(SquareSides); // get Square coordinates from user
			SquareSides = write_Sides(SquareSides);

			if (isRectangle(SquareSides) == true) { // if user does enter a valid rectangle
				double perimeter = 0;
		
				perimeter = getPerimiter(SquareSides.top_line,SquareSides.left_line); // get perimeter
				double area = 0;
				area = getArea(SquareSides.top_line, SquareSides.left_line); // get area
				printf_s("The perimeter is %lf\nThe Area is : %lf\n",perimeter,area); //print data
			}
			else {
				printf_s("\nThis is not a rectangle..."); // was not a rectangle
			}
			break;
			*/
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
	int c; while ((c = getchar()) != '\n' && c != EOF) {}// clears the get char buffer
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