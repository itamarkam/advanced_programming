#pragma once

#include "BattleshipPlayer.h"

BattleshipPlayer::BattleshipPlayer(int id) : id_(id) {}


void BattleshipPlayer::setBoard(const char** board, int numRows, int numCols) {
	// todo: read battleships from board and initialize
}


std::pair<int, int> BattleshipPlayer::attack() {
	std::pair<int, int> move = moves_.front();
	moves_.pop();
	return move;
}


void BattleshipPlayer::notifyOnAttackResult(int player, int row, int col, AttackResult result) {
	// todo: whay do we care?
}


AttackResult BattleshipPlayer::opponentMove(std::pair<int, int> move, int* score) {
	const auto& it = hits_.find(move);
	if (it == hits_.end()) {
		return AttackResult::Miss;
	}

	// HIT!
	// reference to battleship for after deletion of pointer
	Battleship& B = *(it->second);

	// remove <move> from hits_
	hits_.erase(it);

	B.hit();
	if (B.isSunk()) {
		*score += B.getValue();  // value for sinking ship
		n_ships_--;  // one less ship
		return AttackResult::Sink;
	}
	return AttackResult::Hit;
}


int BattleshipPlayer::getId() { return id_; }


bool BattleshipPlayer::isAlive() { return n_ships_ > 0; }