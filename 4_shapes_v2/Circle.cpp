#include "Circle.h"
#include <iostream>

const double pi = 3.14159;

Circle::Circle(Array <double> _position, double _radius) : Shape(_position), radius(_radius) {}

double Circle::GetArea() const
{
	return pi * (radius * radius);
}

void Circle::Grow()
{
	radius = radius * sqrt(1.1);
}

void Circle::Shrink()
{
	radius = radius * sqrt(0.9);
}

void Circle::PrintInfo() const
{
	std::cout << "Circle position: ";
	std::cout << "\nx = " << position[0] << "\ny = " << position[1] << "\nz = " << position[2];
	std::cout << "\nradius = " << radius << '\n';
	std::cout << std::endl;
}

std::string Circle::GetShapeName() const
{
	return "Circle";
}