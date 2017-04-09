#include "Battleship.h"

Battleship::Battleship(BattleshipType t, BattleshipPlayer* owner)
	: owner_(owner), size_(battleship_details_.find(t)->second.first),
	value_(battleship_details_.find(t)->second.second) {}

BattleshipPlayer* Battleship::owner() { return owner_; }

void Battleship::hit() { size_--; }

bool Battleship::isSunk() { return size_ > 0; }

int Battleship::getValue() { return value_; }


