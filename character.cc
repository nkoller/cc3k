#include "character.h"
#include "stats.h"
#include "shade.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orc.h"
#include "merchant.h"
#include "halfling.h"

Character::Character(char name, bool canMove, Stats status):
	name{name}, canMove{canMove}, status{status} {}

void Character::attach(Observer *o) {
	if(observers.size()) observers.pop_back();
	observers.emplace_back(o);
}

char Character::getName() {
   return name;
}

Stats Character::getStats() const {
 return status;
}

/*
void Character::setStats(Stats s) {
    status.HP = s.HP;
    status.Atk = s.Atk;
    status.Def = s.Def;
    status.Gold = s.Gold;
}*/

bool Character::moves() {
 return canMove;
}

/*//helper
void change(int &type, const int amt) {
 type += amt;
 if(type < 0) {
   type = 0;
 }
}*/

void Character::checkIfDead() {
	if (status.HP <= 0) {
		setState(State::CharacterDied);
		notifyObservers();
		std::cout << "Oh noey! " << name << " died! :(" << std::endl;
	}
}

int Character::calcDamage(double atk, double def) {
	double damage = (100.0 / (100 + def)) * atk;
	int trunc = damage;
	return (damage > trunc)? trunc + 1 : trunc;
}

double Character::attack(Shade &defender) {
	return calcDamage(status.Atk, defender.getStats().Def);
}

double Character::attack(Dwarf &defender) {
	return calcDamage(status.Atk, defender.getStats().Def);
}

double Character::attack(Human &defender) {
	return calcDamage(status.Atk, defender.getStats().Def);
}

double Character::attack(Elf &defender) {
	return calcDamage(status.Atk, defender.getStats().Def);
}

double Character::attack(Orc &defender) {
	return calcDamage(status.Atk, defender.getStats().Def);
}

double Character::attack(Merchant &defender) {
	return calcDamage(status.Atk, defender.getStats().Def);
}

double Character::attack(Halfling &defender) {
	return calcDamage(status.Atk, defender.getStats().Def);
}

Character::~Character() {}
