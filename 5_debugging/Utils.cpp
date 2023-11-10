#include "Utils.h"
#include <chrono>
#include <cstdint>
#include <string.h>

namespace Utils
{
	uint64_t GetCurrentTimeStampMilliseconds()
	{
		using namespace std::chrono;
		return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
	}

	float GetSecondsFromMilliseconds(uint64_t miliseconds)
	{
		return miliseconds / 1000.f;
	}

	void CycleInt(int& i)
	{
		i = (i + 1) % 1000;
	}

	std::string GetSeasonName(const Season& season)
	{
		std::string seasonName;

		switch (season)
		{
		case Season::Spring:
		{
			seasonName = "Spring";
			break;
		}
		case Season::Summer:
		{
			seasonName = "Summer";
			break;
		}
		case Season::Autumn:
		{
			seasonName = "Autumn";
			break;
		}
		case Season::Winter:
		{
			seasonName = "Winter";
			break;
		}
		}
		return seasonName;
	}
}