#pragma once
#include "Shape.h"

class Circle : public Shape
{

protected:
	double radius;

public:
	Circle(Array <double> _position, double _radius);

	double GetArea() const override;
	void Grow() override;
	void Shrink() override;
	void PrintInfo() const override;
	std::string GetShapeName() const override;
};