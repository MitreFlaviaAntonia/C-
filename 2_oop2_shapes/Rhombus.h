#pragma once
using namespace std;

#include "Square.h"

class Rhombus : public Square {

public:
	Rhombus() = delete;
	Rhombus(vector<double> position_, double side_);

	double GetArea() const override;
	void Grow() override;
	void Shrink() override;
	void PrintInfo() const override;
	virtual string GetShapeType() const override;

};
