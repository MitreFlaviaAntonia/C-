#include "Weapon.h"
#include "string.h"
#include <iostream>

Weapon::Weapon()
{
	strcpy_s(my_Name, 10, "N/A");
	my_Damage = 0;
	my_Weight = 0;
	my_IsTwoHanded = false;
}

Weapon::Weapon(const char name[], int damage, int weight, bool isTwoHanded)
{
	if (strlen(name) >= 10)
	{
		strcpy_s(my_Name, 10, "invalid");
	}
	else
	{
		strcpy_s(my_Name, 10, name);
	}
	my_Damage = damage;
	my_Weight = weight;
	my_IsTwoHanded = isTwoHanded;
}