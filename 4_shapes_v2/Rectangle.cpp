#include "Rectangle.h"

Rectangle::Rectangle(Array <double> _position, double _width, double _height) : Shape(_position), width(_width), height(_height) {}

double Rectangle::GetArea() const
{
	return width * height;
}

void Rectangle::Grow()
{
	double sqRoot = sqrt(1.1);
	width *= sqRoot; //calculated using the formula: % increase in area = a + a +(a^2/100), where a is the percentage of growth for the width and height => ~4% = 0.0488088 each
	height *= sqRoot; //https://testbook.com/question-answer/each-side-of-a-rectangular-field-is-increased-by-1--6007e3cc02f2c3547f004246
}

void Rectangle::Shrink()
{
	double sqRoot = sqrt(0.9);
	width *= sqRoot;
	height *= sqRoot;
}

void Rectangle::PrintInfo() const
{
	std::cout << "Rectangle position: ";
	std::cout << "\nx = " << position[0] << "\ny = " << position[1] << "\nz = " << position[2];
	std::cout << "\nwidth = " << width;
	std::cout << "\nheight = " << height << '\n';
	std::cout << std::endl;
}

std::string Rectangle::GetShapeName() const
{
	return "Rectangle";
}