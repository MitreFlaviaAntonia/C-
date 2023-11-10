using namespace std;
#include "Rectangle.h"

Rectangle::Rectangle(vector<double> position_, double width_, double height_) : Shape(position_), width(width_), height(height_) {}

double Rectangle::GetArea() const
{
	return width * height;
}

void Rectangle::Grow()
{
	double area = GetArea();

	area = area + area * 1.1;

	double sidesIncrease = area / (width + height);

	width = width + width * 0.0488088; //calculated using the formula % increase in area = a + a +(a^2/100)
	height = height + height * 0.0488088; //https://testbook.com/question-answer/each-side-of-a-rectangular-field-is-increased-by-1--6007e3cc02f2c3547f004246
}

void Rectangle::Shrink()
{
	width = width - width / 10;
	height = height - height / 10;
}

void Rectangle::PrintInfo() const
{
	std::cout << "Rectangle position: ";
	std::cout << "\nx = " << position[0] << "\ny = " << position[1] << "\nz = " << position[2];
	std::cout << "\nwidth = " << width;
	std::cout << "\nheight = " << height << '\n';
	std::cout << endl;
}

string Rectangle::GetShapeType() const
{
	return "rectangle";
}