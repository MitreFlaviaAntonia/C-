#pragma once
#include "Shape.h"

class Rectangle : public Shape
{

protected:
	double width;
	double height;

public:
	Rectangle(Array <double> _position, double _width, double _height);

	double GetArea() const override;
	void Grow() override;
	void Shrink() override;
	void PrintInfo() const override;
	std::string GetShapeName() const override;
};