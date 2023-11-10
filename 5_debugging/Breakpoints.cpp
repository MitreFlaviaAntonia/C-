#include "Breakpoints.h"
#include "DisplayMessage.h"
#include "Utils.h"
#include "Timer.h"

// Basic Breakpoint
void Exercise_1()
{
	// TODO: Put basic breakpoints
	// - Follow the flow of the execution with shortcuts:
	//		- F11 - Step into function
	// 		- Shift + F11 - Step out of function
	//		- F10 - Step over
	//		- F5  - Continue execution
	// TODO: Look at the values of the variables while in breakpoint
	// TODO: Play with the debug pointer and see how it impacts the result
	 
	int a = 0;

	for (int i = 0; i < 10; ++i)
	{
		Utils::CycleInt(a);
	}

	DisplayMessage(a);
}

// Conditional Breakpoint
void Exercise_2()
{
	// TODO: Get the value of b when a is bigger than 100 and i is 666
	// - How to put conditional breakpoint: Put a breakpoint -> Right click -> Conditions -> set the condition for the breakpoint
	// - b should be 1965(first time the breakpoint is hit), if it's not, figure out why :p
	int i = 11;
	int a = 0;
	int b = 0;

	while (b < 10000 && a < 10000)
	{
		Utils::CycleInt(i);
		a += 2;
		b += 3;
	}
}

// Tracepoints
void Exercise_3()
{
	// TODO: Write in output the values of b when a is bigger than 50 and i is 666
	// - How to put tracepoint: Put a breakpoint -> Right click -> Actions -> set value to print
	// - Use the following format "[Function Name][search-able name] b = 'value'"
	// - [search-able name] is just any name you want to put, to make it easy to be searched in output
	// The values should be 1965, 4965, 7965
	
	int i = 11;
	int a = 0;
	int b = 0;

	while (b < 10000 && a < 10000)
	{
		Utils::CycleInt(i);
		a += 2;
		b += 3;
	}
}

// Autos, Locals
void Exercise_4()
{
	// TODO: Put a breakpoint on the "nummbersArray[i] = i;" line and observe how the variables in locals and auto change
	int assignationsMade = 0;
	int nummbersArray[9];

	for (int i = 0; i < 9; i++)
	{
		nummbersArray[i] = i;
		assignationsMade++;
	}
}

// Watch
void Exercise_5()
{
	// TODO: Add variable c to watch and observe how it changes
	// - put a breakpoint near the c variable -> right click -> Add watch
	// TODO: Leave a breakpoint at the end of while and observe how c changes

	int a = 0;
	int b = 0;

	int c = 0;

	while (c < 1000)
	{
		if (a % 5 == 0)
		{
			c += 3;
		}

		if (b % 4 == 1)
		{
			c += 2;
		}

		a++;
		b++;
	}
}

// Data Breakpoint
void Exercise_6()
{
	// TODO: Put a data breakpoint on 'a' and follow how the value changes
	// Data breakpoint - Trigger a breakpoint when the variable exists -> go to Locals/Autos/Watch -> right click the variable -> break when value changes
	// Bonus awesome points if you do it the old way as well
	// folosim un watch, dam click dreapta pe variabila a din watch si selectam "Break when value changes" , dam F5 ca sa continue rularea

	int a = 10;
	int b = 2;

	while (a > 0)
	{
		a -= b;
	}
}
