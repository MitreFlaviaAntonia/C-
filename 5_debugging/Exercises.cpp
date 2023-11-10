#include "Exercises.h"
#include "Defines.h"
#include "DisplayMessage.h"
#include "Log.h"
#include "Timer.h"

// Call stack + Find bugs
void Exercise_7()
{
	// TODO: Put a breakpoint in the Get_0() function and browse through the callstack
	// TODO: Find the bugs and try to debug putting breakpoints in the Get_x() functions and using the callstack
	// TODO: Check the output window for any warnings or errors
	// in loc de 9 afisa 8, pentru ca la case 9 era return get_8 in loc de get_9

	DisplayMessage("I will now print numbers from 0 to 9");
	
	DisplayMessage(Get_0());
	DisplayNumbersInRange(1, 9);
}

// Logs
void Exercise_8()
{
	// TODO: Run this exercise
	// TODO: look for the file named "log.txt" in your working directory
	// Working directory
	//	- in the solution folder -> if you run from visual studio
	//	- in x64/debug or release -> if you run from the exe
	
	// TODO: play with logs

	Log("Logging can be tricky, but it is fun enough!");

	for (int i = 0; i < 10; ++i)
	{
		Log("%i", i);
	}

	Log(":P");
}

// Timing issues
void Exercise_9()
{
	// TODO: Run the program once and see what happens in the console with no breakpoints
	// TODO: Put a breakpoint in the while and inspect the variables in the Locals and Autos windows
	// TODO: Notice what happens when you stay too much in a breakpoint;

	PetOwner owner;

	Timer sessionTimer;
	sessionTimer.Start(10000);

	Timer petBuyCooldownTimer;
	petBuyCooldownTimer.Start(1.2f);

	while (sessionTimer.GetElapsedTime() < 60 && owner.m_OwnedCatsNum < 10)
	{
		if (petBuyCooldownTimer.HasFinished())
		{
			// Buy pet
			owner.m_LastCatBoughtTimeStamp = sessionTimer.GetElapsedTime();
			owner.m_OwnedCatsNum++;
			std::cout << "Pet bought " << owner.m_LastCatBoughtTimeStamp << " seconds after starting the program" << std::endl;
			petBuyCooldownTimer.Start(1.2f);
		}
	}

	std::cout << std::endl;

	if (owner.m_OwnedCatsNum == 10)
	{
		DisplayMessage("Enough pets for you");
		std::cout << "You bought " << owner.m_OwnedCatsNum << " pets in " << sessionTimer.GetElapsedTime() << " real seconds." << std::endl << std::endl;
	}
	else
	{
		DisplayMessage("Time expired");
		std::cout << "You only managed to buy " << owner.m_OwnedCatsNum << " pets in " << sessionTimer.GetElapsedTime() << " real seconds." << std::endl << std::endl;
	}
}

void DisplayNumbersInRange(int minCap, int maxCap)
{
	for (int i = minCap; i <= maxCap; i++)
	{
		DisplayMessage(Get_num(i));
	}
}

int Get_0()
{
	return 0;
}

int Get_1()
{
	return 1;
}

int Get_2()
{
	return 2;
}

int Get_3()
{
	return 3;
}

int Get_4()
{
	return 4;
}

int Get_5()
{
	return 5;
}

int Get_6()
{
	return 6;
}

int Get_7()
{
	return 7;
}

int Get_8()
{
	return 8;
}

int Get_9()
{
	return 9;
}


int Get_num(int i)
{
	switch (i)
	{
	case 0:
		return Get_0();
	case 1:
		return Get_1();
	case 2:
		return Get_2();
	case 3:
		return Get_3();
	case 4:
		return Get_4();
	case 5:
		return Get_5();
	case 6:
		return Get_6();
	case 7:
		return Get_7();
	case 8:
		return Get_8();
	case 9:
		return Get_9();
	default:
		break;
	}
}