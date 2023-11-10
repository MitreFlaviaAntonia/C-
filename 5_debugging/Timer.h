#pragma once

#include <iostream>

class Timer
{
public:
	void Start(float duration);
	float GetElapsedTime();
	float GetRemainingTime();
	bool HasFinished();

private:
	uint64_t m_StartTime{ 0 };
	uint64_t m_Duration{ 0 };
};
