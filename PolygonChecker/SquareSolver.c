#include "SquareSolver.h"


#include <math.h>

EQUILATERAL getSquareSides(EQUILATERAL points) { // retrieve user input for the 4 coordinate points
	
		printf_s("Enter the first coordinate of the square: \n");
		for (int i = 0; i < 4; i++)
		{
			printf_s("\nEnter the x coordinate of the %d coordinate of the square: ", (i + 1));
			scanf_s("%d", &points.x[i]); 
			printf_s("Enter the y coordinate of the %d coordinate of the square: ", (i + 1));
			scanf_s("%d", &points.y[i]);
		}
		return points;
	
}
double getPerimiter(int x, int y) { // return the total of 4 ints
	return  (2*x + 2*y);
}
double getArea(int x, int y) { // returns the area of two lines
	return x*y;
}
bool isRectangle(EQUILATERAL* points) { // says i need to generate 4 lines but 2 lines are identical for x and y axis so shouldnt I only need 2?


	return true; // everything passed
}