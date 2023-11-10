#include "Circle.h"
#include <iostream>
using namespace std;

const double pi = 3.14159;

Circle::Circle(vector<double> position_, double radius_) : Shape(position_), radius(radius_) {}

double Circle::GetArea() const
{
	return pi * (radius * radius);
}

void Circle::Grow()
{
	radius = sqrt((GetArea() * 1.1) / pi);
}

void Circle::Shrink()
{
	radius = sqrt((GetArea() * 0.9) / pi);
}

void Circle::PrintInfo() const
{
	std::cout << "Circle position: ";
	std::cout << "\nx = " << position[0] << "\ny = " << position[1] << "\nz = " << position[2];
	std::cout << "\nradius = " << radius << '\n';
	std::cout << endl;
}

string Circle::GetShapeType() const
{
	return "circle";
}