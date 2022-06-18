#pragma once
#include "../Entities/Hero/Human/Human.h"
#include "../Entities/Hero/Warrior/Warrior.h"
#include "../Entities/Hero/Wizard/Wizard.h"
#include "../Entities/Monster/Monster.h"
class Battle {

public:
	void begin(Human& human, Monster& monster) ;
	void begin(Warrior& warrior, Monster& monster) ;
	void begin(Wizzard& wizzad, Monster& monster) ;
};
