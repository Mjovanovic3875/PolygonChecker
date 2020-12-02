#pragma once

#define NOT_A_TRIANGLE "Not a triangle"
#define IS_EQUILATERAL "Equilateral triangle"
#define IS_ISOSCELES  "Isosceles triangle"
#define IS_SCALENE "Scalene triangle"

char* analyze_triangle(int side1, int side2, int side3);
double* inside_angles(int one, int two, int three);
double find_angle(int one, int two, int three);
bool is_sum_greater(int one, int two, int three);