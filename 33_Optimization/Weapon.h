#pragma once
class Weapon
{
public:
	Weapon();
	Weapon(const char name[], int damage, int weight, bool isTwoHanded);

public:
	char my_Name[10];
	int my_Damage;
	int my_Weight;
	bool my_IsTwoHanded;
};