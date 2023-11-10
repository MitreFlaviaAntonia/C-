#pragma once
#include "Rectangle.h"

class Square : public Rectangle
{

public:
	Square(Array <double> _position, double _side);

	void Grow() override;
	void Shrink() override;
	void PrintInfo() const override;
	std::string GetShapeName() const override;
};