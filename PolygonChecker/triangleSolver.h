#pragma once

#define NOT_A_TRIANGLE "Not a triangle"
#define IS_EQUILATERAL "Equilateral triangle"
#define IS_ISOSCELES  "Isosceles triangle"
#define IS_SCALENE "Scalene triangle"


typedef struct triangle TRIANGLE;

const char* analyze_triangle(int side1, int side2, int side3);
double radians_to_degrees(double radians);
double* inside_angles_radians(int one, int two, int three);
double* inside_angles_degrees(int sideOne, int sideTwo, int sideThree);
double find_angle(int one, int two, int three);
bool is_sum_greater(int one, int two, int three);