#include "Shape.h"

Shape::Shape(Array <double> _position) : position(_position) {}

void Shape::MoveRandomly()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	int axis = rand() % 3;
	if (axis == 0)
	{
		std::cout << "axis chosen is x"<< std::endl;
	}
	if (axis == 1)
	{
		std::cout << "axis chosen is y" << std::endl;
	}
	if (axis == 2)
	{
		std::cout << "axis chosen is z" << std::endl;
	}
	position[axis] = rand() % 50 * 1.0;
	//increments/decrements any of the axes randomly
}