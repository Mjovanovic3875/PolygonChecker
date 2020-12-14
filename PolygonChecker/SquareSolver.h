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

QUADRILATERAL create_quadrilateral(POINT pointOne, POINT pointTwo, POINT pointThree, POINT pointFour);

QUADRILATERAL quarilateral_wizard(void);
QUADRILATERAL write_Sides(QUADRILATERAL reference);
QUADRILATERAL getSquareSides(QUADRILATERAL points); //gets user input and returned them as a coordinate struct
double get_perimeter(double x, double y); // returns the perimeter of a rectangle based on two lines
double get_area(double x, double y); //returns the area of two lines
bool is_rectangle(QUADRILATERAL points); // determines if the given set of coordinates is a rectangle or not

double get_left_line(QUADRILATERAL quadrilateral);

double get_top_line(QUADRILATERAL quadrilateral);

double get_right_line(QUADRILATERAL quadrilateral);

double get_bottom_line(QUADRILATERAL quadrilateral);
