#pragma once
using namespace std;

#include "Rectangle.h"

class Square : public Rectangle {

public:
	Square() = delete;
	Square(vector<double> position_, double side_);

	void Grow() override;
	void Shrink() override;
	void PrintInfo() const override;
	virtual string GetShapeType() const override;
};