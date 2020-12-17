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


#include "QuadrilateralSolver.h"
#include "triangleSolver.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>

double get_perimeter(double sideOne, double sideTwo,
					 double sideThree, double sideFour) 
{
	return sideOne + sideTwo + sideThree + sideFour;
}
double get_area(double x, double y) 
{ // returns the area of two lines
	return x*y;
}


QUADRILATERAL create_quadrilateral(POINT pointOne, POINT pointTwo,
	POINT pointThree, POINT pointFour) // returns a quadralateral based on 4 points
{
	QUADRILATERAL result;

	POINT pointsTemp[4] = { pointOne, pointTwo, pointThree, pointFour };


	// Order the points to be top left, top right, bottom left, bottom right
	//    We can do so with 3 sorts

	// First, sort all y values in terms of their y values.
	//   points will contain [top point, top point, bottom point, bottom point]
	qsort(&(pointsTemp), 4, sizeof(POINT), compare_point_y);

	// Now, sort the top 2 and bottom 2 points individually
	qsort(&(pointsTemp), 2, sizeof(POINT), compare_point_x); // Order first two points (left most, then right most)
	qsort(&(pointsTemp[2]), 2, sizeof(POINT), compare_point_x); // Order last two points


	// The array works, but isn't readable. Let the struct have separate variables for different points
	result.topLeftPoint = pointsTemp[0];
	result.topRightPoint = pointsTemp[1];
	result.bottomLeftPoint = pointsTemp[2];
	result.bottomRightPoint = pointsTemp[3];

	// Find line lengths
	result.topLine = find_line_length(result.topLeftPoint, result.topRightPoint);
	result.bottomLine = find_line_length(result.bottomLeftPoint, result.bottomRightPoint);
	result.leftLine = find_line_length(result.topLeftPoint, result.bottomLeftPoint);
	result.rightLine = find_line_length(result.topRightPoint, result.bottomRightPoint);

	result.diagOne = find_line_length(result.topLeftPoint, result.bottomRightPoint);
	result.diagTwo = find_line_length(result.topRightPoint, result.bottomLeftPoint);


	return result;
}



QUADRILATERAL quadrilateral_wizard(void)
{

	POINT pointsTemp[4];

	bool hasDuplicates;
	do
	{
		for (int i = 0; i < 4; i++)
		{
			printf("Please enter the x value for point %d: ", i + 1);
			scanf_s("%lf", &(pointsTemp[i].x));
			printf("Please enter the y value for point %d: ", i + 1);
			scanf_s("%lf", &(pointsTemp[i].y));
		}

		hasDuplicates = has_duplicates(pointsTemp, 4);
		if (hasDuplicates)
		{
			printf("2 or more of your entered points are duplicates! Please try again.\n");
		}
	} while (hasDuplicates);



	return create_quadrilateral(pointsTemp[0], pointsTemp[1], pointsTemp[2], pointsTemp[3]);
}


void print_quadrilateral_information(QUADRILATERAL quadrilateral)
{
	bool isRectangle = is_rectangle(quadrilateral);

	if (isRectangle)
	{
		double area = get_area(quadrilateral.topLine, quadrilateral.leftLine);
		double perimeter = get_perimeter(quadrilateral.topLine,
										 quadrilateral.leftLine,
										 quadrilateral.bottomLine,
										 quadrilateral.rightLine);
		printf("This is a rectangle.\n");
		printf("Its area is %lf\n", area);
		printf("Its perimeter is %lf\n", perimeter);
	}
	else
	{
		double perimeter = get_perimeter(quadrilateral.topLine,
										 quadrilateral.leftLine,
										 quadrilateral.bottomLine,
										 quadrilateral.rightLine);
		printf("This is NOT a rectangle.\n");
		printf("Its perimeter is %lf\n", perimeter);
	}

	return;
}

bool has_duplicates(POINT* points, int n)
{

	// Check every POINT in points to subsequent POINTS in pairs 
	//    (e.g., points[0]-points[1], points[1]-points[2], etc.)
	// memcmp each pair. If memcmp returns 0, then a duplicate exists
	// If for loops terminate, then no duplicates exist
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int pointCompareResult = memcmp(&(points[i]), 
										    &(points[j]), sizeof(POINT));

			if (pointCompareResult == 0)
			{
				return true;
			}
		}
	}

	return false;
}


bool is_rectangle(QUADRILATERAL quadrilateral) { // says i need to generate 4 lines but 2 lines are identical for x and y axis so shouldnt I only need 2?
	double topLeftAngleRad = find_angle(quadrilateral.diagTwo, quadrilateral.topLine, quadrilateral.leftLine);
	
	double topRightAngleRad = find_angle(quadrilateral.diagOne, quadrilateral.topLine, quadrilateral.rightLine);

	double bottomLeftAngleRad = find_angle(quadrilateral.diagOne, quadrilateral.bottomLine, quadrilateral.leftLine);

	double bottomRightAngleRad = find_angle(quadrilateral.diagTwo, quadrilateral.bottomLine, quadrilateral.rightLine);


	// Doubles have rounding issues. In my initial testing, it seems that the errors are predictable such that
	//    all angles will end up the same. However, this might not be
	//    completely robust. If not robust, the best solution is likely using some rounding
	if ((topLeftAngleRad == topRightAngleRad) &&
		(topRightAngleRad == bottomLeftAngleRad) &&
		(bottomLeftAngleRad == bottomRightAngleRad))
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



double get_left_line(QUADRILATERAL quadrilateral) // returns the left line of a rectangle
{
	return quadrilateral.leftLine;
}
double get_top_line(QUADRILATERAL quadrilateral) // returns the top line of a rectangle
{
	return quadrilateral.topLine;
}
double get_right_line(QUADRILATERAL quadrilateral) // returns the right line of a rectangle
{
	return quadrilateral.rightLine;
}
double get_bottom_line(QUADRILATERAL quadrilateral) // returns the bottom line of a rectangle
{
	return quadrilateral.bottomLine;
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
		compare_point_x(pointOne, pointTwo);
	}
}




