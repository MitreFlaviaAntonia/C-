#include "Square.h"

Square::Square(Array <double> _position, double _side) : Rectangle(_position, _side, _side) {}

void Square::Grow()
{
	height = sqrt(GetArea() * 1.1);
}

void Square::Shrink()
{
	height = sqrt(GetArea() * 0.9);
}

void Square::PrintInfo() const
{
	std::cout << "Square position: ";
	std::cout << "\nx = " << position[0] << "\ny = " << position[1] << "\nz = " << position[2];
	std::cout << "\nside = " << height << '\n';
	std::cout << std::endl;
}

std::string Square::GetShapeName() const
{
	return "Square";
}