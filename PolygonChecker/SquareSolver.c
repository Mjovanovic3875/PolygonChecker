#include "SquareSolver.h"




COORDINATE getSquareSides(COORDINATE points) {
	
		printf_s("Enter the first coordinate of the square: \n");
		for (int i = 0; i < 4; i++)
		{
			printf_s("\nEnter the x coordinate of the %d coordinate of the square: ", (i + 1));
			scanf_s("%d", &points.x[i]); 
			printf_s("\nEnter the y coordinate of the %d coordinate of the square: ", (i + 1));
			scanf_s("%d", &points.y[i]);
		}
		return points;
	
}
int getPerimiter(COORDINATE points) {
	return points.y[3];
}
int getArea(COORDINATE points) {
	return points.x[2];
}
bool isRectangle(COORDINATE points) {
	return true;
}