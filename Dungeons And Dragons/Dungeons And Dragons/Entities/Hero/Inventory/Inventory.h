#pragma once
#include "../../Item/Armour/Armour.h"
#include "../../Item/Spell/Spell.h"
#include "../../Item/Weapon/Weapon.h"
#include "../../../Helpers/Optional/Optional.hpp"
class Inventory {
	Optional<Armour> armour;
	Weapon weapon;
	Spell spell;

public:
	Inventory();
	
	void setArmour(const Armour& armour);
	void setWeapon(const Weapon& weapon);
	void setSpell(const Spell& spell);

	const Spell& getSpell() const;
	const Optional<Armour>& getArmour() const;
	const Weapon& getWeapon() const;
};
