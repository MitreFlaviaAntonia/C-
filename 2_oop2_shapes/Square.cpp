using namespace std;
#include "Square.h"

Square::Square(vector<double> position_, double side_) : Rectangle(position_, side_, side_) {}

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
	std::cout << endl;
}

string Square::GetShapeType() const
{
	return "square";
}