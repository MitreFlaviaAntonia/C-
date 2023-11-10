#include <iostream>
#include <vector>
#include <list>
#include <iostream>
#include "Rectangle.h"
#include "Square.h"
#include "Rhombus.h"
#include "Circle.h"
#include "Shape.h"
using namespace std;

int main()
{
	list <Shape*> shapes;

	srand(static_cast<unsigned int>(time(nullptr)));

	int shapeType = 0;

	/*
	const int SIZE = 10;
	vector <int> shapeType = {0,0,0,0,0,0,0,0,0,0}
	for (int i = 0; i < 10; i++)
	{
		shapeType[i] = rand() % 4; //random int 0-3
	}
	*/

	int option = -1;

	cout << "The actions can make:" << endl;
	cout << "1 - generate new shape of the specified type" << endl;
	cout << "2 - remove one shape with the specified type from the list" << endl;
	cout << "3 - resize all shapes" << endl;
	cout << "4 - shrink all shapes" << endl;
	cout << "5 - move all shapes randomly on one axis and print the info on all shapes" << endl;
	cout << "6 - display the areas of all the shapes of a type" << endl;
	cout << "7 - print all class members for all shapes" << endl;
	cout << "0 - exit program" << endl << endl;

	cout << "The shape types you can create: " << endl;
	cout << "0 - Circle" << endl;
	cout << "1 - Rectangle" << endl;
	cout << "2 - Square" << endl;
	cout << "3 - Rhombus" << endl;

	while (option)
	{
		cout << endl << "The wanted action is: ";
		cin >> option;

		switch (option) {
		case 1: //generate new shape
		{	
			int it = 0;
			cout << "The selected shape type is: ";
			//cin >> shapeType[it];
			shapeType = rand() % 4;
			cout << shapeType;

			switch (shapeType) {
			case 0:
			{
				Circle* circle = new Circle({ rand() % 50 * 1.0, rand() % 50 * 1.0, rand() % 50 * 1.0 }, rand() % 50 * 1.0);
				shapes.push_back(circle);
				break;
			}
			case 1:
			{
				Rectangle* rectangle = new Rectangle({ rand() % 50 * 1.0, rand() % 50 * 1.0, rand() % 50 * 1.0 }, rand() % 50 * 1.0, rand() % 50 * 1.0);
				shapes.push_back(rectangle);
				break;
			}
			case 2:
			{
				Square* square = new Square({ rand() % 50 * 1.0, rand() % 50 * 1.0, rand() % 50 * 1.0 }, rand() % 50 * 1.0);
				shapes.push_back(square);
				break;
			}
			case 3:
			{
				Rhombus* rhombus = new Rhombus({ rand() % 50 * 1.0, rand() % 50 * 1.0, rand() % 50 * 1.0 }, rand() % 50 * 1.0);
				shapes.push_back(rhombus);
				break;
			}
			default:
				break;
			}
			it++;
			break;
		}
		case 2: //remove a specified type shape
		{
			cout << "The selected shape type is: ";
			//cin >> shapeType[it];
			shapeType = rand() % 4;
			cout << shapeType;
			string shapeType_s = "";

			if (shapeType == 0)
				shapeType_s = "circle";
			if (shapeType == 1)
				shapeType_s = "rectangle";
			if (shapeType == 2)
				shapeType_s = "square";
			if (shapeType == 3)
				shapeType_s = "rhombus";
			
			for (auto it = shapes.begin(); it != shapes.end(); ++it)
			{
				Shape* shapePtr = *it;
				if ((shapePtr->GetShapeType()).compare(shapeType_s) == 0)
				{
					cout << endl << "The first " << shapePtr->GetShapeType() << " from the list is deleted" << endl;
					delete* it;
					shapes.erase(it); //removes the element at the iterator it from the shapes list and all subsequent elements are shifted down to fill the gap
					break;
				}
			}
			break;
		}
		case 3: //resize (grow) all shapes
		{
			for (auto it = shapes.begin(); it != shapes.end(); ++it)
			{
				// dereference the iterator to get a pointer to the current Shape
				Shape* shapePtr = *it;

				// use the arrow operator to access members of the Shape object
				shapePtr->Grow();
			}
			break;
		}
		case 4: //shrink all shapes
		{
			for (auto it = shapes.begin(); it != shapes.end(); ++it) {
				Shape* shapePtr = *it;
				shapePtr->Shrink();
			}
			break;
		}
		case 5: //move all shapes on one axis
		{
			for (auto it = shapes.begin(); it != shapes.end(); ++it) {
				Shape* shapePtr = *it;
				shapePtr->MoveRandomly(); //the axis is the same for all as a pointer to shape is used?
				shapePtr->PrintInfo();
			}
			break;
		}
		case 6: //display the areas of all the shapes of a specified type
		{
			cout << "The selected shape type is: ";
			//cin >> shapeType[it];
			shapeType = rand() % 4;
			cout << shapeType;
			string shapeType_s = "";

			if (shapeType == 0)
				shapeType_s = "circle";
			if (shapeType == 1)
				shapeType_s = "rectangle";
			if (shapeType == 2)
				shapeType_s = "square";
			if (shapeType == 3)
				shapeType_s = "rhombus";

			for (auto it = shapes.begin(); it != shapes.end(); ++it)
			{
				Shape* shapePtr = *it;
				if((shapePtr->GetShapeType()).compare(shapeType_s) == 0)
					cout << endl << "Area of " << shapeType_s << " is: " << shapePtr->GetArea() << endl;
			}
			break;
		}
		case 7: //print info all shapes existing
		{
			for (auto it = shapes.begin(); it != shapes.end(); ++it)
			{
				Shape* shapePtr = *it;
				shapePtr->PrintInfo();
			}
			break;
		}
		default:
			break;
		}
	}
}