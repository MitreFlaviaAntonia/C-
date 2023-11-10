#include <iostream>
#include "Breakpoints.h"
#include "DisplayMessage.h"
#include "Demo.h"
#include "Exercises.h"
#include "GameTrial.h"

void RunGameTrial()
{
	GameTrial trial;
	trial.Init();
	
	while (!trial.Finished())
	{
		trial.Update();
	}

	trial.Shutdown();
}

int main()
{ 
	// Hello there :D
	// Uncomment each exercise and follow the instructions written as TODO's
	// These are meant to familiarize you with debugging tools
	// so try stuff out to see what each of them has to offer

	// Ignore this
	//Demo();

	// --------------------------------------------------------------------------
	// Exercises

	//Exercise_1();
	//Exercise_2();
	//Exercise_3();
	//Exercise_4();
	//Exercise_5();
	//Exercise_6();
	//Exercise_7();
	//Exercise_8();

	//Bonus
	//Exercise_9();

	// --------------------------------------------------------------------------
	// This is the ULTIMATE DEBUGGING TRIAL
	
	// Backstory:
	// "The programmer that has written this system has left the company
	// and now it is your job to to understand the system and solve the
	// bugs that have been plaguing the game."

	// Rules:
	// This is a simulation game where a "main character" is fighting with 4 enemies.
	// - they attack whenever they can
	// - fight finishes when main character dies or when all enemies die
	// - main character can heal himself
	// - seasons advance while the fight continues and we care about how many seasons it takes for one side to defeat the other

	// Bugs:
	// - Latest build crashes v
	// - Seasons don't change properly v
	// - Simulation doesn't end properly 9/10 repro - se termina jocul cand moare primul inamic. v
	// - Main character can heal over max hp v
	// - Main character will sometimes attack dead enemies v
	// - Dead enemies still attack the main character v
	// - Characters have less health than set values v
	
	// Good luck! :D

	RunGameTrial();

	DisplayMessage("Finished");
}