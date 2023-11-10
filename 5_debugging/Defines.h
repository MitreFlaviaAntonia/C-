#pragma once

enum class Season
{
	Spring,
	Summer,
	Autumn,
	Winter,
	Count
};

struct PetOwner
{
	int m_OwnedCatsNum = 0;
	float m_LastCatBoughtTimeStamp = 0.f;
};
