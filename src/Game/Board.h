#ifndef BOARD_H_
#define BOARD_H_

#include "IObserver.h"

#define BOARD_WIDTH  8
#define BOARD_HEIGHT 8

enum class Square
{
	EMPTY        = 0,

	WHITE_PAWN   = 1,
	WHITE_KNIGHT = 2,
	WHITE_BISHOP = 3,
	WHITE_ROOK   = 4,
	WHITE_QUEEN  = 5,
	WHITE_KING   = 6,

	BLACK_PAWN   = -1,
	BLACK_KNIGHT = -2,
	BLACK_BISHOP = -3,
	BLACK_ROOK   = -4,
	BLACK_QUEEN  = -5,
	BLACK_KING   = -6,
};

class Board
{
public:
	Board(IObserver* observer);

	void update(Coordinate click);

private:
	Square piece_selected_;
	Square stage_[BOARD_WIDTH][BOARD_HEIGHT];
	IObserver* observer_;
};

#endif /* BOARD_H_ */
