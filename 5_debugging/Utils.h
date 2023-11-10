#pragma once

#include <iostream>
#include "Defines.h"

namespace Utils
{
	uint64_t GetCurrentTimeStampMilliseconds();
	float GetSecondsFromMilliseconds(uint64_t miliseconds);
	void CycleInt(int& i);
	std::string GetSeasonName(const Season& season);
}