#include "Demo.h"
#include "Utils.h"
#include "Timer.h"

void Demo()
{
	Timer timer;
	timer.Start(30);
	int i = 0;
	int j = 0;

	float remainingTime = timer.GetRemainingTime();

	while (!timer.HasFinished())
	{
		Utils::CycleInt(i);
		remainingTime = timer.GetRemainingTime();

		if (i == 100)
		{
			std::cout << remainingTime << std::endl;
			j++;
		}
	}

	std::cout << j << std::endl;
}