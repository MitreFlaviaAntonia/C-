#include <iostream>
#include "stack.h"

int main()
{
	myStack stk(5);
	stk.push(10);
	stk.push(20);
	stk.push(30);
	stk.push(40);
	stk.push(50);
	stk.push(60);
	stk.push(70);
	stk.push(80);
	stk.push(90);
	std::cout << "Top element: " << stk.top() << std::endl;
	stk.pop();
	std::cout << "Top element after pop: " << stk.top() << std::endl;
	return 0;
}