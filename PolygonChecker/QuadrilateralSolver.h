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

#pragma once
#include <stdbool.h>
#include <stdio.h>
#include "triangleSolver.h"


typedef struct point
{
	double x;
	double y;
} POINT;


typedef struct quadrilateral {
	POINT topLeftPoint;
	POINT topRightPoint;
	POINT bottomLeftPoint;
	POINT bottomRightPoint;
	double topLine;
	double leftLine;
	double bottomLine;
	double rightLine;
	double diag1;
	double diag2;
}QUADRILATERAL;

QUADRILATERAL create_quadrilateral(POINT pointOne, POINT pointTwo, POINT pointThree, POINT pointFour); // creates a quadrilateral object from the 4 points given

QUADRILATERAL quadrilateral_wizard(void); // used to get 4 points from the user

bool has_duplicates(POINT* points, int n);

// returns the perimeter given four side lengths
double get_perimeter(double sideOne, double sideTwo, 
		             double sideThree, double sideFour);

double get_area(double x, double y); //returns the area of two lines

bool is_rectangle(QUADRILATERAL points); // determines if the given set of coordinates is a rectangle or not

double find_line_length(POINT pointOne, POINT pointTwo);

void print_quadrilateral_information(QUADRILATERAL quadrilateral); // prints information about the quadrilateral

// Returns integer values signifying which of the points are left-most
//    Returns a negative number if pointOne is to the left of pointTwo
//    Returns a positive number if pointTwo is to the left of pointOne
//    Returns 0 if both points are the aligned horizontally
int compare_point_x(POINT* pointOne, POINT* pointTwo);

// Returns integer values signifying which of the points are top-most
//    Returns a negative number if pointOne is above pointTwo
//    Returns a positive number if pointTwo is above pointOne
//    Returns compare_point_x (with points supplied) if both points are aligned vertically
int compare_point_y(POINT* pointOne, POINT* pointTwo);
