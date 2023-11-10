using namespace std;
#include "Rhombus.h"

Rhombus::Rhombus(vector<double> position_, double side_) : Square(position_, side_) {}
double Rhombus::GetArea() const
{
	return height * height * sqrt(3)/2;
} //area of a rhombus made from 2 equilateral triangles

void Rhombus::Grow()
{
	height  = sqrt(2.2 * GetArea() / sqrt(3));
}

void Rhombus::Shrink()
{
	height = sqrt(1.8 * GetArea() / sqrt(3));
}

void Rhombus::PrintInfo() const
{
	std::cout << "Rhombus position: ";
	std::cout << "\nx = " << position[0] << "\ny = " << position[1] << "\nz = " << position[2];
	std::cout << "\nside = " << height << '\n';
	std::cout << endl;
}

string Rhombus::GetShapeType() const
{
	return "rhombus";
}