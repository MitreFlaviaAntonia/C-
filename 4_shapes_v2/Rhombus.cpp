#include "Rhombus.h"

Rhombus::Rhombus(Array <double> _position, double _side, double _height) : Square(_position, _side)
{
	_height = _side * sqrt(3);
	height = _height;
}
double Rhombus::GetArea() const
{
	return width * width * sqrt(3);
}

void Rhombus::Grow()
{
	width  = width * sqrt(1.1);
	height = width * sqrt(3);
}

void Rhombus::Shrink()
{
	width = width * sqrt(0.9);
	height = width * sqrt(3);
}

void Rhombus::PrintInfo() const
{
	std::cout << "Rhombus position: ";
	std::cout << "\nx = " << position[0] << "\ny = " << position[1] << "\nz = " << position[2];
	std::cout << "\nwidth = " << width;
	std::cout << "\nheight = " << height << '\n';
	std::cout << std::endl;
}

std::string Rhombus::GetShapeName() const
{
	return "Rhombus";
}