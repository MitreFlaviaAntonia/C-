#include <iostream>
#include <string>
#include "Rhombus.h"
#include "Circle.h"

enum class ShapeType
{
	Rectangle,
	Circle,
	Square,
	Rhombus,
	Count
};

ShapeType randomShapeType()
{
	return static_cast<ShapeType>(rand() % static_cast<int>(ShapeType::Count));
}

std::string enumToString(ShapeType type)
{
	switch (type)
	{
	case ShapeType::Rectangle:
		return "Rectangle";
	case ShapeType::Circle:
		return "Circle";
	case ShapeType::Square:
		return "Square";
	case ShapeType::Rhombus:
		return "Rhombus";
	default:
		return "Count";
	}
}

void generateNewShape(Array <Shape*>& shapesPtrArr, Array <double> position)
{
	std::cout << "The selected shape type is: ";
	ShapeType type = randomShapeType();
	std::cout << enumToString(type) << std::endl;
	Shape* shape = nullptr;

	switch (type)
	{
	case ShapeType::Circle:
	{
		shape = new Circle(position, rand() % 50 * 1.0);
		break;
	}
	case ShapeType::Rectangle:
	{
		shape = new Rectangle(position, rand() % 50 * 1.0, rand() % 50 * 1.0);
		break;
	}
	case ShapeType::Square:
	{
		shape = new Square(position, rand() % 50 * 1.0);
		break;
	}
	case ShapeType::Rhombus:
	{
		shape = new Rhombus(position, rand() % 50 * 1.0, rand() % 50 * 1.0);
		break;
	}
	default:
		break;
	}
	shapesPtrArr.addElement(shape);
}

void removeShape(Array <Shape*>& shapesPtrArr)
{
	std::cout << "The selected shape type is: ";
	ShapeType type = randomShapeType();
	std::string shapeType = enumToString(type);
	std::cout << shapeType << std::endl;

	for (int i = 0; i < shapesPtrArr.getSize(); ++i)
	{
		if ((shapesPtrArr[i]->GetShapeName()).compare(shapeType) == 0)
		{
			std::cout << std::endl << "The first " << shapesPtrArr[i]->GetShapeName() << " from the list is deleted" << std::endl;
			shapesPtrArr.removeElement(i);
			break;
		}
	}
}

void growAllShapes(Array <Shape*>& shapesPtrArr)
{
	for (int i = 0; i < shapesPtrArr.getSize(); ++i)
	{
		shapesPtrArr[i]->Grow();
	}
}

void shrinkAllShapes(Array <Shape*>& shapesPtrArr)
{
	for (int i = 0; i < shapesPtrArr.getSize(); ++i)
	{
		shapesPtrArr[i]->Shrink();
	}
}

void moveAllShapesOnOneAxis(Array <Shape*>& shapesPtrArr)
{
	for (int i = 0; i < shapesPtrArr.getSize(); ++i)
	{
		shapesPtrArr[i]->MoveRandomly(); //the axis is the same for all as a pointer to shape is used?
		shapesPtrArr[i]->PrintInfo();
	}
}

void displayAreasOfaShapeType(Array <Shape*>& shapesPtrArr)
{
	std::cout << "The selected shape type is: ";
	ShapeType type = randomShapeType();
	std::string shapeType = enumToString(type);
	std::cout << shapeType << std::endl;

	for (int i = 0; i < shapesPtrArr.getSize(); ++i)
	{
		if ((shapesPtrArr[i]->GetShapeName()).compare(shapeType) == 0)
			std::cout << std::endl << "Area of " << shapeType << " is: " << shapesPtrArr[i]->GetArea() << std::endl;
	}
}

void printInfoAllShapes(Array <Shape*>& shapesPtrArr)
{
	for (int i = 0; i < shapesPtrArr.getSize(); ++i)
	{
		shapesPtrArr[i]->PrintInfo();
	}
}

int main()
{
	Array <Shape*> shapesPtrArr(10);

	srand(static_cast<unsigned int>(time(nullptr)));

	int shapeType = 0;

	int option = -1;

	std::cout << "The actions you can make:" << std::endl;
	std::cout << "1 - generate new shape of the specified type" << std::endl;
	std::cout << "2 - remove one shape with the specified type from the list" << std::endl;
	std::cout << "3 - resize all shapes" << std::endl;
	std::cout << "4 - shrink all shapes" << std::endl;
	std::cout << "5 - move all shapes randomly on one axis and print the info on all shapes" << std::endl;
	std::cout << "6 - display the areas of all the shapes of a type" << std::endl;
	std::cout << "7 - print all class members for all shapes" << std::endl;
	std::cout << "0 - exit program" << std::endl << std::endl;

	std::cout << "The shape types you can create: " << std::endl;
	std::cout << "0 - Circle" << std::endl;
	std::cout << "1 - Rectangle" << std::endl;
	std::cout << "2 - Square" << std::endl;
	std::cout << "3 - Rhombus" << std::endl;

	while (option)
	{
		std::cout << std::endl << "The wanted action is: ";
		std::cin >> option;

		switch (option)
		{
		case 1:
		{
			Array <double> position(3);
			position.addElement(rand() % 50);
			position.addElement(rand() % 50);
			position.addElement(rand() % 50);

			generateNewShape(shapesPtrArr, position);
			break;
		}
		case 2:
		{
			removeShape(shapesPtrArr);
			break;
		}
		case 3:
		{
			growAllShapes(shapesPtrArr);
			break;
		}
		case 4:
		{
			shrinkAllShapes(shapesPtrArr);
			break;
		}
		case 5:
		{
			moveAllShapesOnOneAxis(shapesPtrArr);
			break;
		}
		case 6:
		{
			displayAreasOfaShapeType(shapesPtrArr);
			break;
		}
		case 7:
		{
			printInfoAllShapes(shapesPtrArr);
			break;
		}
		default:
			if(option != 0)
			{
				std::cout << "Action not recognized" << std::endl;
			}
			break;
		}
	}
}