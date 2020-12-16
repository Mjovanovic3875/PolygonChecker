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

#define NOT_A_TRIANGLE "Not a triangle"
#define IS_EQUILATERAL "Equilateral triangle"
#define IS_ISOSCELES  "Isosceles triangle"
#define IS_SCALENE "Scalene triangle"


typedef struct triangle TRIANGLE;

TRIANGLE* create_triangle(double sideA, double sideB, double sideC);

TRIANGLE* triangle_wizard();

void free_triangle(TRIANGLE* triangle);

void print_triangle_information(TRIANGLE* triangle);

const char* analyze_triangle(double side1, double side2, double side3);

double radians_to_degrees(double radians);

double* inside_angles_radians(double one, double two, double three);

double* inside_angles_degrees(double sideOne, double sideTwo, double sideThree);

double find_angle(double a, double b, double c);

bool is_triangle(double sideOne, double sideTwo, double sideThree);

bool is_sum_greater(int one, int two, int three);