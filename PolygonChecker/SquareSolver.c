#include "SquareSolver.h"
#include "triangleSolver.h"
#include <stdlib.h>
#include <math.h>

QUADRILATERAL getSquareSides(QUADRILATERAL points) { // retrieve user input for the 4 coordinate points
	
		printf_s("Enter the first coordinate of the square: \n");
		for (int i = 0; i < 4; i++)
		{
			printf_s("\nEnter the x coordinate of the %d coordinate of the square: ", (i + 1));
			scanf_s("%lf", &points.x[i]); 
			printf_s("Enter the y coordinate of the %d coordinate of the square: ", (i + 1));
			scanf_s("%lf", &points.y[i]);
		}
	
		return points;
	
}

double get_perimeter(double x, double y) { // return the total of 4 ints
	return  (2*x + 2*y);
}
double get_area(double x, double y) { // returns the area of two lines
	return x*y;
}
bool is_rectangle(QUADRILATERAL quadrilateral) { // says i need to generate 4 lines but 2 lines are identical for x and y axis so shouldnt I only need 2?
	double topLeftAngleRad = find_angle(quadrilateral.diag2, quadrilateral.top_line, quadrilateral.left_line);
	double topLeftAngleDeg = radians_to_degrees(topLeftAngleRad);

	double topRightAngleRad = find_angle(quadrilateral.diag1, quadrilateral.top_line, quadrilateral.right_line);
	double topRightAngleDeg = radians_to_degrees(topRightAngleRad);

	double bottomLeftAngleRad = find_angle(quadrilateral.diag1, quadrilateral.bottom_line, quadrilateral.left_line);
	double bottomLeftAngleDeg = radians_to_degrees(bottomLeftAngleRad);

	double bottomRightAngleRad = find_angle(quadrilateral.diag2, quadrilateral.bottom_line, quadrilateral.right_line);
	double bottomRightAngleDeg = radians_to_degrees(bottomRightAngleRad);

	if ((topLeftAngleDeg == topRightAngleDeg) &&
		(topRightAngleDeg == bottomLeftAngleDeg) &&
		(bottomLeftAngleDeg == bottomRightAngleDeg))
	{
		return true;
	}
	else
	{
		return false;
	}
}


double find_line_length(POINT pointOne, POINT pointTwo)
{
	// distance between two points is the square root of the 
	//    differences of the x points squared plus
	//    the differences of the y points squared
	double xDifferences = pointOne.x - pointTwo.x;
	double yDifferences = pointOne.y - pointTwo.y;

	double xDiffSquared = pow(xDifferences, 2);
	double yDiffSquared = pow(yDifferences, 2);

	double result = sqrt(xDiffSquared + yDiffSquared);

	return result;
}



double get_left_line(QUADRILATERAL quadrilateral)
{
	return quadrilateral.left_line;
}
double get_top_line(QUADRILATERAL quadrilateral)
{
	return quadrilateral.top_line;
}
double get_right_line(QUADRILATERAL quadrilateral)
{
	return quadrilateral.right_line;
}
double get_bottom_line(QUADRILATERAL quadrilateral)
{
	return quadrilateral.bottom_line;
}



int compare_point_y(POINT *pointOne, POINT *pointTwo)
{
	if (pointOne->y > pointTwo->y)
	{
		return -1;
	}
	else if (pointTwo->y > pointOne->y)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int compare_point_x(POINT* pointOne, POINT* pointTwo)
{
	if (pointOne->x < pointTwo->x)
	{
		return -1;
	}
	else if (pointTwo->x < pointOne->x)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


QUADRILATERAL quarilateral_wizard(void)
{
	QUADRILATERAL result;
	POINT pointsTemp[4];

	for (int i = 0; i < 4; i++)
	{
		printf("Please enter the x value for point %d: ", i + 1);
		scanf_s("%lf", &(pointsTemp[i].x));
		printf("Please enter the y value for point %d: ", i + 1);
		scanf_s("%lf", &(pointsTemp[i].y));
	}
	

	// Order the points to be top left, top right, bottom left, bottom right
	//    We can do so with 3 sorts

	// First, sort all y values in terms of their y values.
	//   points will contain [top point, top point, bottom point, bottom point]
	qsort(&(pointsTemp), 4, sizeof(POINT), compare_point_y);

	// Now, sort the top 2 and bottom 2 points individually
	qsort(&(pointsTemp), 2, sizeof(POINT), compare_point_x); // Order first two points (left most, then right most)
	qsort(&(pointsTemp[2]), 2, sizeof(POINT), compare_point_x); // Order last two points

	result.topLeftPoint = pointsTemp[0];
	result.topRightPoint = pointsTemp[1];
	result.bottomLeftPoint = pointsTemp[2];
	result.bottomRightPoint = pointsTemp[3];

	// Find line lengths
	result.top_line = find_line_length(result.topLeftPoint, result.topRightPoint);
	result.bottom_line = find_line_length(result.bottomLeftPoint, result.bottomRightPoint);
	result.left_line = find_line_length(result.topLeftPoint, result.bottomLeftPoint);
	result.right_line = find_line_length(result.topRightPoint, result.bottomRightPoint);

	result.diag1 = find_line_length(result.topLeftPoint, result.bottomRightPoint);
	result.diag2 = find_line_length(result.topRightPoint, result.bottomLeftPoint);

	return result;
}


QUADRILATERAL write_Sides(QUADRILATERAL quadrilateral) {
	int topy_1 = 0;
	int topy_2 = 0;
	int top_x = 0;
	int top_Right = 0;
	int top_Left = 0;
	int bottom_Left = 0;
	int Bottom_Right = 0;






	/*
	for (int counter = 0; counter < 4; counter++) { // get top two points
		if (quadrilateral.y[counter] > quadrilateral.y[topy_1]) {
			topy_1= counter;
		}
	}
	for (int counter = 0; counter < 4; counter++) { // get top two points
		if (quadrilateral.y[counter] > quadrilateral.y[topy_2] && counter != topy_1) {
			topy_2 = counter;
		}
	}
	if (quadrilateral.x[topy_1] > quadrilateral.x[topy_2]) { // decide left right points
		top_Right = topy_1;
		top_Left = topy_2;
}
	else { // decide left right points
		top_Right = topy_2;
		top_Left = topy_1;
	}
	for (int counter = 0; counter < 4; counter++) { // find farthest right point of the lower coordinates
		if (quadrilateral.x[counter] > quadrilateral.x[top_x] && counter != topy_1 && counter != topy_2) {
			top_x = counter;
		}
	}
	Bottom_Right = top_x;
	for (int counter = 0; counter < 4; counter++) { // the last non assigned coordinate is bottom left
		if (counter != topy_1 && counter != topy_2 && counter != top_x) {
			bottom_Left = counter;
		}
	}

	
	quadrilateral.top_line = sqrt(pow(abs(quadrilateral.x[top_Right] - quadrilateral.x[top_Left]),2) + pow(abs(quadrilateral.y[top_Right] - quadrilateral.y[top_Left]),2)); // sqrt( (x2 - x1)^2 + (y2 - y1)^2 )
	quadrilateral.bottom_line = sqrt(pow(abs(quadrilateral.x[Bottom_Right] - quadrilateral.x[bottom_Left]), 2) + pow(abs(quadrilateral.y[Bottom_Right] - quadrilateral.y[bottom_Left]), 2)); // abs allows x2 x1 to be interchangable in the above formula
	quadrilateral.left_line = sqrt(pow(abs(quadrilateral.x[top_Left] - quadrilateral.x[bottom_Left]), 2) + pow(abs(quadrilateral.y[top_Left] - quadrilateral.y[bottom_Left]), 2));
	quadrilateral.right_line = sqrt(pow(abs(quadrilateral.x[top_Right] - quadrilateral.x[Bottom_Right]), 2) + pow(abs(quadrilateral.y[top_Right] - quadrilateral.y[Bottom_Right]), 2));

	quadrilateral.diag1 = sqrt(pow(abs(quadrilateral.x[Bottom_Right] - quadrilateral.x[top_Left]), 2) + pow(abs(quadrilateral.y[top_Left] - quadrilateral.y[Bottom_Right]), 2));
	quadrilateral.diag2 = sqrt(pow(abs(quadrilateral.x[top_Right] - quadrilateral.x[bottom_Left]), 2) + pow(abs(quadrilateral.y[top_Right] - quadrilateral.y[bottom_Left]), 2));
	return quadrilateral;
	// uncomment the line underneath to view values of coordinates and lines
	printf_s("top_left(%lf,%lf) top right(%lf,%lf) bottomleft(%lf,%lf) bottomright (%lf,%lf) Top: %lf, bottom : %lf, Left : %lf, Right : %lf diag1 : %lf, diag2 : %lf	", quadrilateral.x[top_Left], quadrilateral.y[top_Left], quadrilateral.x[top_Right], quadrilateral.y[top_Right], quadrilateral.x[bottom_Left], quadrilateral.y[bottom_Left], quadrilateral.x[Bottom_Right], quadrilateral.y[Bottom_Right], quadrilateral.top_line, quadrilateral.bottom_line, quadrilateral.left_line, quadrilateral.right_line,quadrilateral.diag1,quadrilateral.diag2);
	*/
}