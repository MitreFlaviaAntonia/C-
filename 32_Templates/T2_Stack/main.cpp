#include <iostream>
#include <string>
#include "stack.h"

int main()
{
	// Create a Stack using std::deque as the default container
	Stack<float> stack1;

	stack1.push(10.4);
	stack1.push(20.5);
	stack1.push(30.6);

	float poppedElementFloat = stack1.pop();
	std::cout << "Popped element: " << poppedElementFloat << std::endl;

	float topElement = stack1.top();
	std::cout << "Top element: " << topElement << std::endl;

	// Create a Stack using std::vector as the container
	Stack<int, std::vector<int>> stack2;

	stack2.push(100);
	stack2.push(200);
	stack2.push(300);
	stack2.push(800);

	int poppedElementInt = stack2.pop();
	std::cout << "Popped element: " << poppedElementInt << std::endl;

	topElement = stack2.top();
	std::cout << "Top element: " << topElement << std::endl;


	stack1 = stack2;

	poppedElementFloat = stack1.pop();

	std::cout << "Top element: " << stack1.top() << std::endl;

	return 0;
}