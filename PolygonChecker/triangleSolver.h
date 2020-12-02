#pragma once

#define NOT_A_TRIANGLE "Not a triangle"
#define IS_EQUILATERAL "Equilateral triangle"
#define IS_ISOSCELES  "Isosceles triangle"
#define IS_SCALENE "Scalene triangle"


typedef struct triangle TRIANGLE;

const char* analyze_triangle(double side1, double side2, double side3);
double radians_to_degrees(double radians);
double* inside_angles_radians(double one, double two, double three);
double* inside_angles_degrees(double sideOne, double sideTwo, double sideThree);
double find_angle(double one, double two, double three);
bool is_triangle(double sideOne, double sideTwo, double sideThree);
bool is_sum_greater(int one, int two, int three);