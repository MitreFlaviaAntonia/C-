#pragma once
#include "Square.h"

class Rhombus : public Square
{

public:
	Rhombus(Array <double> _position, double _width, double _height);

	double GetArea() const override;
	void Grow() override;
	void Shrink() override;
	void PrintInfo() const override;
	std::string GetShapeName() const override;
};