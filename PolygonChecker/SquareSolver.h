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


typedef struct quadrilateral { // this is a coordinate struct it contains x and y coordinates for up to 4 points and carries 2 side lengths
	POINT points[4];
	POINT topLeftPoint;
	POINT topRightPoint;
	POINT bottomLeftPoint;
	POINT bottomRightPoint;
	double x[4];
	double y[4];
	double top_line;
	double left_line;
	double bottom_line;
	double right_line;
	double diag1;
	double diag2;
}QUADRILATERAL;

QUADRILATERAL create_quadrilateral(POINT pointOne, POINT pointTwo, POINT pointThree, POINT pointFour); // creates a quadrilateral object from the 4 points given

QUADRILATERAL quadrilateral_wizard(void); // used to get 4 points from the user

QUADRILATERAL write_Sides(QUADRILATERAL reference); // returns a quadrilateral with the side lengths inputted from the given quadrilateral

QUADRILATERAL getSquareSides(QUADRILATERAL points); //gets user input and returned them as a coordinate struct

double get_perimeter(double x, double y); // returns the perimeter of a rectangle based on two lines

double get_area(double x, double y); //returns the area of two lines

bool is_rectangle(QUADRILATERAL points); // determines if the given set of coordinates is a rectangle or not

double get_left_line(QUADRILATERAL quadrilateral); // returns the left line of the given quadrilateral

double get_top_line(QUADRILATERAL quadrilateral);// returns the top line of the given quadrilateral

double get_right_line(QUADRILATERAL quadrilateral);// returns the right line of the given quadrilateral

double get_bottom_line(QUADRILATERAL quadrilateral);// returns the bottom line of the given quadrilateral
