#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Array.h"

class Shape
{

protected: 
	Array <double> position;

public:
	Shape() = delete; //deletes the predefined constructor
	Shape(Array <double> _position);
	//virtual destructor, can delete the shape object and the inherited objects
	virtual ~Shape() = default;

	virtual void Grow() = 0;
	virtual void Shrink() = 0;
	virtual void PrintInfo() const = 0;
	virtual double GetArea() const = 0;
	virtual std::string GetShapeName() const = 0;
	void MoveRandomly();
};