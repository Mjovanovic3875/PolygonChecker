#pragma once
#include <stdbool.h>
#include <stdio.h>
#include "triangleSolver.h"

typedef struct equilateral { // this is a coordinate struct it contains x and y coordinates for up to 4 points and carries 2 side lengths
	double x[4];
	double y[4];
	double top_line;
	double right_line;
	double bottom_Line;
	double left_Line;
}EQUILATERAL;

EQUILATERAL getSquareSides(EQUILATERAL points); //gets user input and returned them as a coordinate struct
int getPerimiter(int x, int y); // returns the perimeter of a rectangle based on two lines
int getArea(int x, int y); //returns the area of two lines
bool isRectangle(EQUILATERAL* points); // determines if the given set of coordinates is a rectangle or not
