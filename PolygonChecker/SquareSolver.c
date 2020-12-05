#include "SquareSolver.h"


#include <math.h>

COORDINATE getSquareSides(COORDINATE points) { // retrieve user input for the 4 coordinate points
	
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
int getPerimiter(int x, int y) { // return the total of 4 ints
	return  (2*x + 2*y);
}
int getArea(int x, int y) { // returns the area of two lines
	return x*y;
}
bool isRectangle(COORDINATE* points) { // says i need to generate 4 lines but 2 lines are identical for x and y axis so shouldnt I only need 2?

	
	if (points->x[0] == points->x[1] || points->x[0] == points->x[2] || points->x[0] == points->x[3]) { // if first x coord matches with any of the other coords move on

	}
	else {
		return false;
	}
	if (points->x[1] == points->x[0] || points->x[1] == points->x[2] || points->x[1] == points->x[3]) { // every x coord should have at least one match somewhere

	}
	else {
		return false;
	}
	if (points->x[2] == points->x[1] || points->x[2] == points->x[0] || points->x[2] == points->x[3]) {

	}
	else {
		return false;
	}
	if (points->x[3] == points->x[1] || points->x[3] == points->x[2] || points->x[3] == points->x[0]) {

	}
	else {
		return false;

	}


	if (points->y[0] == points->y[1] || points->y[0] == points->y[2] || points->y[0] == points->y[3]) { // if first y coord matches with any of the other coords move on

	}
	else {
		return false;
	}
	if (points->y[1] == points->y[0] || points->y[1] == points->y[2] || points->y[1] == points->y[3]) { // every y coord should have at least one match somewhere

	}
	else {
		return false;
	}
	if (points->y[2] == points->y[1] || points->y[2] == points->y[0] || points->y[2] == points->y[3]) {

	}
	else {
		return false;
	}
	if (points->y[3] == points->y[1] || points->y[3] == points->y[2] || points->y[3] == points->y[0]) {

	}
	else {
		return false;

	}
	
	int max = points->x[0];
	int min = points->x[0];
	for (int counter = 0; counter < 4; counter++) { // get side length of width
		
		if (points->x[counter] > max) {
			max = points->x[counter];
		}
		else if (points->x[counter] < min) {
			min = points->x[counter];
		}
		
	}
	points->side1 = (max - min); // save side length of width
	for (int counter = 0; counter < 4; counter++) {// side length of height
		 max = points->y[0];
		 min = points->y[0];
		if (points->y[counter] > max) {
			max = points->y[counter];
		}
		else if (points->y[counter] < min) {
			min = points->y[counter];
		}
		
	}
	points->side2 = (max - min); // save side length of height
	double c;



	return true; // everything passed
}