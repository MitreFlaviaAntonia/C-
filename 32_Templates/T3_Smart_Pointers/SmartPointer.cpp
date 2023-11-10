#include <iostream>
#include "WeakPointer.h"

int main()
{
	SharedPtr<int> sp(new int(140));
	{
		WeakPtr<int> wp(sp);
		std::cout << "wp " << *wp << "\n";
	}

	SharedPtr<int> sp2(sp);
	std::cout << "sp " << *sp << "\n";
	std::cout << "sp2 " << *sp2 << "\n";
}