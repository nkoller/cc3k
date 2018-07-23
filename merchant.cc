#include "merchant.h"

bool Merchant::hostile = false;

Merchant::Merchant(): Character{'M', true, Stats{30, 70, 5, 0}} {}

Merchant::~Merchant() {}

void Merchant::checkIfDead() {
	if (status.HP <= 0) {
		setState(State::CharacterDied);
		notifyObservers();
		std::cout << "Oh noey! " << name << " died! :(" << std::endl;
	}
	// spawn gold nearby
}

void Merchant::defend(Character &attacker) {
	double damage = attacker.attack(*this);
	status.HP -= damage;
        Merchant::hostile = true;
	std::cout << "Owie! " << name << " took " << damage << " damage! ";
	std::cout << status.HP << " wittle HPs left..." << std::endl;
	checkIfDead();
}
