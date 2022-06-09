#include "pch.h"
#include "Player.h"

#define PAWN   0
#define KNIGHT 1
#define BISHOP 2
#define ROOK   3
#define QUEEN  4
#define KING   5

Player::Player(void)
	: piece_texture_ { TextureManager::load("assets/Images/Black_Pawn.png"  )  ,
					   TextureManager::load("assets/Images/Black_Knight.png")  ,
					   TextureManager::load("assets/Images/Black_Bishop.png")  ,
					   TextureManager::load("assets/Images/Black_Rook.png"  )  ,
					   TextureManager::load("assets/Images/Black_Queen.png" )  ,
					   TextureManager::load("assets/Images/Black_King.png"  ) },
	  pawn_   { { piece_texture_[PAWN]  , { 4  * SCALE + 2, SCALE + SCALE / 2, SCALE, SCALE } }  ,
				{ piece_texture_[PAWN]  , { 5  * SCALE + 2, SCALE + SCALE / 2, SCALE, SCALE } }  ,
				{ piece_texture_[PAWN]  , { 6  * SCALE + 2, SCALE + SCALE / 2, SCALE, SCALE } }  ,
				{ piece_texture_[PAWN]  , { 7  * SCALE + 2, SCALE + SCALE / 2, SCALE, SCALE } }  ,
				{ piece_texture_[PAWN]  , { 8  * SCALE + 2, SCALE + SCALE / 2, SCALE, SCALE } }  ,
				{ piece_texture_[PAWN]  , { 9  * SCALE + 2, SCALE + SCALE / 2, SCALE, SCALE } }  ,
				{ piece_texture_[PAWN]  , { 10 * SCALE + 2, SCALE + SCALE / 2, SCALE, SCALE } }  ,
				{ piece_texture_[PAWN]  , { 11 * SCALE + 2, SCALE + SCALE / 2, SCALE, SCALE } } },
	  knight_ { { piece_texture_[KNIGHT], { 5  * SCALE + 2, SCALE / 2, SCALE, SCALE } }  ,
			    { piece_texture_[KNIGHT], { 10 * SCALE + 2, SCALE / 2, SCALE, SCALE } } },
	  bishop_ { { piece_texture_[BISHOP], { 6  * SCALE + 2, SCALE / 2, SCALE, SCALE } }  ,
				{ piece_texture_[BISHOP], { 9  * SCALE + 2, SCALE / 2, SCALE, SCALE } } },
	  rook_   { { piece_texture_[ROOK]  , { 4  * SCALE + 2, SCALE / 2, SCALE, SCALE } }  ,
				{ piece_texture_[ROOK]  , { 11 * SCALE + 2, SCALE / 2, SCALE, SCALE } } },
	  queen_	{ piece_texture_[QUEEN] , { 7  * SCALE + 2, SCALE / 2, SCALE, SCALE } }  ,
	  king_		{ piece_texture_[KING]  , { 8  * SCALE + 2, SCALE / 2, SCALE, SCALE } }
{
	TRACE("Player: Black is constructing.");
}

Player::Player(bool is_white)
	: piece_texture_ { TextureManager::load("assets/Images/White_Pawn.png"  )  ,
					   TextureManager::load("assets/Images/White_Knight.png")  ,
					   TextureManager::load("assets/Images/White_Bishop.png")  ,
					   TextureManager::load("assets/Images/White_Rook.png"  )  ,
					   TextureManager::load("assets/Images/White_Queen.png" )  ,
					   TextureManager::load("assets/Images/White_King.png"  ) },
	pawn_   { { piece_texture_[PAWN]  , { 4  * SCALE + 2, 6 * SCALE + SCALE / 2, SCALE, SCALE } }  ,
			  { piece_texture_[PAWN]  , { 5  * SCALE + 2, 6 * SCALE + SCALE / 2, SCALE, SCALE } }  ,
			  { piece_texture_[PAWN]  , { 6  * SCALE + 2, 6 * SCALE + SCALE / 2, SCALE, SCALE } }  ,
			  { piece_texture_[PAWN]  , { 7  * SCALE + 2, 6 * SCALE + SCALE / 2, SCALE, SCALE } }  ,
			  { piece_texture_[PAWN]  , { 8  * SCALE + 2, 6 * SCALE + SCALE / 2, SCALE, SCALE } }  ,
			  { piece_texture_[PAWN]  , { 9  * SCALE + 2, 6 * SCALE + SCALE / 2, SCALE, SCALE } }  ,
			  { piece_texture_[PAWN]  , { 10 * SCALE + 2, 6 * SCALE + SCALE / 2, SCALE, SCALE } }  ,
			  { piece_texture_[PAWN]  , { 11 * SCALE + 2, 6 * SCALE + SCALE / 2, SCALE, SCALE } } },
	knight_ { { piece_texture_[KNIGHT], { 5  * SCALE + 2, 7 * SCALE + SCALE / 2, SCALE, SCALE } }  ,
			  { piece_texture_[KNIGHT], { 10 * SCALE + 2, 7 * SCALE + SCALE / 2, SCALE, SCALE } } },
	bishop_ { { piece_texture_[BISHOP], { 6  * SCALE + 2, 7 * SCALE + SCALE / 2, SCALE, SCALE } }  ,
			  { piece_texture_[BISHOP], { 9  * SCALE + 2, 7 * SCALE + SCALE / 2, SCALE, SCALE } } },
	rook_   { { piece_texture_[ROOK]  , { 4  * SCALE + 2, 7 * SCALE + SCALE / 2, SCALE, SCALE } }  ,
			  { piece_texture_[ROOK]  , { 11 * SCALE + 2, 7 * SCALE + SCALE / 2, SCALE, SCALE } } },
	queen_	  { piece_texture_[QUEEN] , { 7  * SCALE + 2, 7 * SCALE + SCALE / 2, SCALE, SCALE } },
	king_	  { piece_texture_[KING]  , { 8  * SCALE + 2, 7 * SCALE + SCALE / 2, SCALE, SCALE } }
{
	TRACE("Player: White is constructing.");
}

Player::~Player(void)
{
	TRACE("Player: Is deconstructing.");

	for (Uint64 index = 0; index < TOTAL_PIECES; ++index)
	{
		TextureManager::destroy(piece_texture_[index]);
	}
}

void Player::draw(void) const
{
	TRACE("Player: draw: Is drawing.");

	Uint64 index = 0;

	for (; index < TOTAL_PAWNS; ++index)
	{
		pawn_[index].draw();
	}
	for (index = 0; index < TOTAL_MINOR_PIECES; ++index)
	{
		knight_[index].draw();
		bishop_[index].draw();
		rook_  [index].draw();
	}
	queen_.draw();
	king_.draw();
}

void Player::update(const Coordinate& previous_click, const Coordinate& click)
{
	TRACE("PLAYER: update: Is updating.");

	Uint64 index = 0;
	Coordinate aux_coordinate = { 1, 1 };

	for (; index < TOTAL_PAWNS; ++index)
	{
		aux_coordinate = pawn_[index].getCoordinate();
		if (aux_coordinate.x == previous_click.x && aux_coordinate.y == previous_click.y)
		{
			pawn_[index].update(click);
			return;
		}
	}
	for (index = 0; index < TOTAL_MINOR_PIECES; ++index)
	{
		aux_coordinate = knight_[index].getCoordinate();
		if (aux_coordinate.x == previous_click.x && aux_coordinate.y == previous_click.y)
		{
			knight_[index].update(click);
			return;
		}

		aux_coordinate = bishop_[index].getCoordinate();
		if (aux_coordinate.x == previous_click.x && aux_coordinate.y == previous_click.y)
		{
			bishop_[index].update(click);
			return;
		}

		aux_coordinate = rook_[index].getCoordinate();
		if (aux_coordinate.x == previous_click.x && aux_coordinate.y == previous_click.y)
		{
			rook_[index].update(click);
			return;
		}
	}

	aux_coordinate = queen_.getCoordinate();
	if (aux_coordinate.x == previous_click.x && aux_coordinate.y == previous_click.y)
	{
		queen_.update(click);
		return;
	}

	aux_coordinate = king_.getCoordinate();
	if (aux_coordinate.x == previous_click.x && aux_coordinate.y == previous_click.y)
	{
		king_.update(click);
		return;
	}
}
