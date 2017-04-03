#include "Battleship.h"

Battleship::Battleship(BattleshipType t)
	: size_(battleship_details_.find(t)->second.first),
	value_(battleship_details_.find(t)->second.second) {}


void Battleship::hit() { hits_--; }


bool Battleship::isSunk() { return hits_ == size_; }


int Battleship::getValue() { return value_; }


