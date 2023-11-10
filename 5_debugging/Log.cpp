#include <iostream>
#include <fstream>
#include <stdarg.h>
#include "Log.h"

// Hello :D
// No bugs here (hopefully)

void Log(const char* text, ...)
{
	char buffer[256];
	va_list args;
	va_start(args, text);

	vsprintf_s(buffer, text, args);

	static bool initialized = false;

	if (!initialized)
	{
		initialized = true;
		std::ofstream file("log.txt");
		file.close();
	}

	// Create and open a text file
	std::ofstream MyFile("log.txt", std::ios_base::app);


	MyFile << buffer << std::endl;

	// Close the file
	MyFile.close();
}