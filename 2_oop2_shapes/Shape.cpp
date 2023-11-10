#include "Shape.h"
using namespace std;

Shape::Shape(vector<double> position_) : position(position_) {}

void Shape::MoveRandomly()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	int axis = rand() % 3;
	cout << "axis chosen is:" << axis << endl;
	position[axis] = rand() % 50 * 1.0; //x = 0, y = 1, z = 2
	//increments/decrements any of the axes randomly
}