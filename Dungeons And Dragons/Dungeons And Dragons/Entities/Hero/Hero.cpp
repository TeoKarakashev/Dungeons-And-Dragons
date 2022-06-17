#include "Hero.h"

Hero::Hero(size_t power, size_t mana, size_t health) {
	this->power = power;
	this->mana = mana;
	this->health = health;
	this->level = 1;
}

Hero::Hero(size_t power, size_t mana, size_t health, size_t level, const Inventory& inventory /*const String& representation*/) {
	this->power = power;
	this->mana = mana;
	this->health = health;
	this->level = level;
	this->inventory = inventory;
}

void Hero::setPower(size_t power) {
	this->power = power;
}

void Hero::setMana(size_t mana) {
	this->mana = mana;
}

void Hero::setHealth(size_t health) {
	this->health = health;
}

void Hero::setLevel(size_t level) {
	this->level = level;
}

void Hero::setWeapon(const Weapon& weapon) {
	this->inventory.setWeapon(weapon);
}

void Hero::setArmour(const Armour& armour) {
	this->inventory.setArmour(armour);
}

void Hero::setSpell(const Spell& spell) {
	this->inventory.setSpell(spell);
}

//void Hero::setRepresentation(const String& path) {
//	this->representation = path;
//}

size_t Hero::getPower() const
{
	return power;
}

size_t Hero::getMana() const
{
	return mana;
}

size_t Hero::getHealth() const
{
	return health;
}

size_t Hero::getLevel() const
{
	return level;
}

const Weapon& Hero::getWeapon() const {
	return inventory.getWeapon();
}

const Optional<Armour>& Hero::getArmour() const {
	return inventory.getArmour();
}

const Spell& Hero::getSpell() const {
	return inventory.getSpell();
}

//const String& Hero::getRepresentation() const {
//	return representation;
//}
