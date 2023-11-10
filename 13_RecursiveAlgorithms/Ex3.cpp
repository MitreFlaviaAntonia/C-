#include <iostream>

int gcd(int firstNr, int secondNr)
{
	if (secondNr == 0)
	{
		return firstNr;
	}
	return gcd(secondNr, firstNr % secondNr);
}

int main()
{
	int firstNr = 98, secondNr = 56;
	std::cout << "GCD of " << firstNr << " and " << secondNr << " is " << gcd(firstNr, secondNr);
	return 0;
}