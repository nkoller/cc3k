#include "dwarf.h"
  
Dwarf::Dwarf(): Character{'W', true ,Stats{100, 20, 30, 1}} {}
					//small pile for now

int Dwarf::returnGold() const {
 return 2 * this->getStats().Gold;
}

Dwarf::~Dwarf() {}
