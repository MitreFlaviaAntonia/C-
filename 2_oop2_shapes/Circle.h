#pragma once
using namespace std;

#include "Shape.h"

class Circle : public Shape {

protected:
	double radius;

public:
	Circle() = delete;
	Circle(vector<double> position_, double radius_);

	double GetArea() const override;
	void Grow() override;
	void Shrink() override;
	void PrintInfo() const override;
	virtual string GetShapeType() const override;
};