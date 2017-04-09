#pragma once

#include "BattleshipPlayer.h"

BattleshipPlayer::BattleshipPlayer(int id, IBattleshipGameAlgo* algo) : id_(id), algo_(algo) {}

void BattleshipPlayer::setBoard(const char** board, int numRows, int numCols) {
	algo_->setBoard(board, numRows, numCols);
}

std::pair<int, int> BattleshipPlayer::attack() {
	return algo_->attack();
}

void BattleshipPlayer::notifyOnAttackResult(int player, int row, int col, AttackResult result) {
	algo_->notifyOnAttackResult(player, row, col, result);
}

int BattleshipPlayer::getId() { return id_; }

bool BattleshipPlayer::isAlive() { return battleships_.size() > 0; }

void BattleshipPlayer::addBattleship(Battleship& battleship) {
	battleships_.emplace_back(battleship);
}

int BattleshipPlayer::getScore() { return score_; }

void BattleshipPlayer::addPoints(int points) { score_ += points; }