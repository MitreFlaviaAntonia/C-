#include <string>
#include <iostream>

size_t strlen_custom(const char* str)
{
	size_t length = 0;
	while (str[length] != '\0')
	{
		length++;
	}
	return length;
}

int main()
{
	const char str[] = "The behavior";

	std::cout << "without null character: " << strlen_custom(str) << '\n'
		<< "with null character: " << sizeof str << '\n';
}