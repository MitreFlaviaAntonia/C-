#include "Timer.h"
#include "Utils.h"

// Hello :D
// No bugs here (hopefully)

void Timer::Start(float duration)
{
	m_StartTime = Utils::GetCurrentTimeStampMilliseconds();
	m_Duration = static_cast<uint64_t>(duration * 1000.f);
}

float Timer::GetElapsedTime()
{
	return (Utils::GetCurrentTimeStampMilliseconds() - m_StartTime) / 1000.f;
}

float Timer::GetRemainingTime()
{
	if (HasFinished())
		return 0;

	return (m_Duration - (Utils::GetCurrentTimeStampMilliseconds() - m_StartTime)) / 1000.f;
}

bool Timer::HasFinished()
{
	return (m_StartTime + m_Duration) <= Utils::GetCurrentTimeStampMilliseconds();
}