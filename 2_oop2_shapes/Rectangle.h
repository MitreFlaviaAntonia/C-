#pragma once
using namespace std;

#include "Shape.h"

class Rectangle : public Shape {

protected:
	double width;
	double height;

public:
	Rectangle() = delete;
	Rectangle(vector<double> position_, double width_, double height_);

	double GetArea() const override;
	void Grow() override;
	void Shrink() override;
	void PrintInfo() const override;
	virtual string GetShapeType() const override;
};