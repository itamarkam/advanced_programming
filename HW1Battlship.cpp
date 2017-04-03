// HW1Battlship.cpp : Defines the entry point for the console application.
//

#include <stdio.h>

#include "Battleship.h"
#include "BattleshipPlayer.h"

void makeMove(BattleshipPlayer active, BattleshipPlayer passive);


int main()
{
	// if read configuration... else return -1

	BattleshipPlayer A(0), B(1);
	// A.setBoard(...), B.setBoard(...)
	while (A.isAlive() && B.isAlive()) {
		// A's move
		makeMove(A, B);

		if (A.isAlive() && B.isAlive()) {
			// B's move
			makeMove(B, A);
		}
	}

	// Game Over
	BattleshipPlayer& winner = A.isAlive() ? A : B;

	// Print all messages

    return 0;
}


void MakeMove(BattleshipPlayer& active, BattleshipPlayer& passive) {
	std::pair<int, int> move = active.attack();
	AttackResult res = passive.opponentMove(move, &(active.score));

	if (res == AttackResult::Miss) { // check for self hit
		res = active.opponentMove(move, &(passive.score));
	}
	active.notifyOnAttackResult(active.getId(), move.first, move.second, res);
	passive.notifyOnAttackResult(active.getId(), move.first, move.second, res);
}