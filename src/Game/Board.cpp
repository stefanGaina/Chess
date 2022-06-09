#include "pch.h"
#include "Board.h"

Board::Board(IObserver* observer)
	: observer_(observer), piece_selected_(Square::EMPTY)
{
	TRACE("Board: Is constructing.");

	for (Uint64 index = 0; index < BOARD_WIDTH; ++index)
	{
		stage_[1][index] = Square::BLACK_PAWN;
		stage_[6][index] = Square::WHITE_PAWN;
	}

	stage_[0][0] = Square::BLACK_ROOK  ;
	stage_[0][1] = Square::BLACK_KNIGHT;
	stage_[0][2] = Square::BLACK_BISHOP;
	stage_[0][3] = Square::BLACK_QUEEN ;
	stage_[0][4] = Square::BLACK_KING  ;
	stage_[0][5] = Square::BLACK_BISHOP;
	stage_[0][6] = Square::BLACK_KNIGHT;
	stage_[0][7] = Square::BLACK_ROOK  ;

	stage_[7][0] = Square::WHITE_ROOK  ;
	stage_[7][1] = Square::WHITE_KNIGHT;
	stage_[7][2] = Square::WHITE_BISHOP;
	stage_[7][3] = Square::WHITE_QUEEN ;
	stage_[7][4] = Square::WHITE_KING  ;
	stage_[7][5] = Square::WHITE_BISHOP;
	stage_[7][6] = Square::WHITE_KNIGHT;
	stage_[7][7] = Square::WHITE_ROOK  ;
}

void Board::update(Coordinate click)
{
	TRACE("Board: update: Is updating.");

	static Coordinate s_previous_click = { 0, 0 };

	click.x = (click.x / SCALE) - 4;

	if (click.y <= SCALE / 2)
	{
		INFO("Board: update: Out of bounds!");
		return;
	}
	click.y -= SCALE / 2;
	click.y = (click.y / SCALE);

	INFO("Board: update: Board stage updated! ({0}, {1})", click.x, click.y);

	if (click.x < 0 || click.y < 0 || click.x >= BOARD_WIDTH || click.y >= BOARD_HEIGHT)
	{
		INFO("Board: update: Out of bounds!");
		return;
	}
	if (piece_selected_ != Square::EMPTY)
	{
		stage_[click.y][click.x] = piece_selected_;

		observer_->update(s_previous_click, click);

		piece_selected_ = Square::EMPTY;
	}
	else if (stage_[click.y][click.x] != Square::EMPTY)
	{
		s_previous_click = click;
		piece_selected_ = stage_[click.y][click.x];
	}
}
