#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Shape {

protected: 
	vector<double> position;

public:
	Shape() = delete; //deletes the predefined constructor
	Shape(vector<double> position_);
	//virtual destructor, can delete the shape object and the inherited objects
	virtual ~Shape() = default;

	virtual void Grow() = 0;
	virtual void Shrink() = 0;
	virtual void PrintInfo() const = 0; //this functions are declared as const because they do not modify any of the member variables in these classes
	virtual double GetArea() const = 0;
	virtual string GetShapeType() const = 0;
	void MoveRandomly();
};