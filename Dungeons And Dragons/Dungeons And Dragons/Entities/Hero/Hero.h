#pragma once
#include "Inventory/Inventory.h"
#include "../Item/Armour/Armour.h"
#include "../Item/Spell/Spell.h"
#include "../Item/Weapon/Weapon.h"
class Hero {
	size_t power;
	size_t mana;
	size_t health;
	size_t level;
	Inventory inventory;
	String representation;

public:

	virtual ~Hero() = default;

	void setPower(size_t power);
	void setMana(size_t mana);
	void setHealth(size_t health);
	void setLevel(size_t level);
	void setWeapon(const Weapon& weapon);
	void setArmour(const Armour& armour);
	void setSpell(const Spell& spell);
	void setRepresentation(const String& string);

	size_t getPower() const;
	size_t getMana() const;
	size_t getHealth() const;
	size_t getLevel() const;
	const Weapon& getWeapon() const;
	const Optional<Armour>& getArmour() const;
	const Spell& getSpell() const;
	const String& getRepresentation() const;
};