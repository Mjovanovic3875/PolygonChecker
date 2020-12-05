#include "SquareSolver.h"


#include <math.h>

EQUILATERAL getSquareSides(EQUILATERAL points) { // retrieve user input for the 4 coordinate points
	
		printf_s("Enter the first coordinate of the square: \n");
		for (int i = 0; i < 4; i++)
		{
			printf_s("\nEnter the x coordinate of the %d coordinate of the square: ", (i + 1));
			scanf_s("%lf", &points.x[i]); 
			printf_s("Enter the y coordinate of the %d coordinate of the square: ", (i + 1));
			scanf_s("%lf", &points.y[i]);
		}
		write_Sides(points);
		return points;
	
}
double getPerimiter(double x, double y) { // return the total of 4 ints
	return  (2*x + 2*y);
}
double getArea(double x, double y) { // returns the area of two lines
	return x*y;
}
bool isRectangle(EQUILATERAL* points) { // says i need to generate 4 lines but 2 lines are identical for x and y axis so shouldnt I only need 2?

	if (points->top_line == points->bottom_line && points->left_line == points->right_line) { // top and bottom lines are equal and left right lines are equal 
		if (points->diag1 == points->diag2) { // diagionals are equal
			return true; // all requirements passed
		}
	}
	else {
		return false; // not a rect
	}
}
void write_Sides(EQUILATERAL points) {
	int topy_1 = 0;
	int topy_2 = 0;
	int top_x = 0;
	int top_Right = 0;
	int top_Left = 0;
	int bottom_Left = 0;
	int Bottom_Right = 0;
	for (int counter = 0; counter < 4; counter++) { // get top two points
		if (points.y[counter] > points.y[topy_1]) {
			topy_1= counter;
		}
	}
	for (int counter = 0; counter < 4; counter++) { // get top two points
		if (points.y[counter] > points.y[topy_2] && counter != topy_1) {
			topy_2 = counter;
		}
	}
	if (points.x[topy_1] > points.x[topy_2]) { // decide left right points
		top_Right = topy_1;
		top_Left = topy_2;
}
	else { // decide left right points
		top_Right = topy_2;
		top_Left = topy_1;
	}
	for (int counter = 0; counter < 4; counter++) { // find farthest right point of the lower coordinates
		if (points.x[counter] > points.x[top_x] && counter != topy_1 && counter != topy_2) {
			top_x = counter;
		}
	}
	Bottom_Right = top_x;
	for (int counter = 0; counter < 4; counter++) { // the last non assigned coordinate is bottom left
		if (counter != topy_1 && counter != topy_2 && counter != top_x) {
			bottom_Left = counter;
		}
	}
	points.top_line = sqrt(pow(abs(points.x[top_Right] - points.x[top_Left]),2) + pow(abs(points.y[top_Right] - points.y[top_Left]),2)); // sqrt( (x2 - x1)^2 + (y2 - y1)^2 )
	points.bottom_line = sqrt(pow(abs(points.x[Bottom_Right] - points.x[bottom_Left]), 2) + pow(abs(points.y[Bottom_Right] - points.y[bottom_Left]), 2)); // abs allows x2 x1 to be interchangable in the above formula
	points.left_line = sqrt(pow(abs(points.x[top_Left] - points.x[bottom_Left]), 2) + pow(abs(points.y[top_Left] - points.y[bottom_Left]), 2));
	points.right_line = sqrt(pow(abs(points.x[top_Right] - points.x[Bottom_Right]), 2) + pow(abs(points.y[top_Right] - points.y[Bottom_Right]), 2));

	points.diag1 = sqrt(pow(abs(points.x[top_Left] - points.x[Bottom_Right]), 2) + pow(abs(points.y[top_Left] - points.y[Bottom_Right]), 2));
	points.diag2 = sqrt(pow(abs(points.x[top_Right] - points.x[bottom_Left]), 2) + pow(abs(points.y[top_Right] - points.y[bottom_Left]), 2));

	// uncomment the line underneath to view values of coordinates and lines
	// printf_s("top_left(%lf,%lf) top right(%lf,%lf) bottomleft(%lf,%lf) bottomright (%lf,%lf) Top: %lf, bottom : %lf, Left : %lf, Right : %lf		", points.x[top_Left], points.y[top_Left], points.x[top_Right], points.y[top_Right], points.x[bottom_Left], points.y[bottom_Left], points.x[Bottom_Right], points.y[Bottom_Right], points.top_line, points.bottom_line, points.left_line, points.right_line);
}