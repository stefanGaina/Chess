#include "pch.h"
#include "Piece.h"

#define OFFSET_X 4 * SCALE + 2
#define OFFSET_Y SCALE / 2 + 2

Piece::Piece(SDL_Texture* texture, SDL_Rect starting_position)
	: Component(texture, starting_position), position_(starting_position.x / SCALE - 4, starting_position.y / SCALE)
{
	TRACE("Piece: Is constructing. ({0}, {1})", position_.x, position_.y);
	VERIFY(texture != nullptr, "Piece: Texture argument is null!");
}

void Piece::update(Coordinate click)
{
	INFO("Piece: update: Piece got updated with {0}, {1}", click.x, click.y);

	position_ = click;
	destination_.x = position_.x * SCALE + OFFSET_X;
	destination_.y = position_.y * SCALE + OFFSET_Y;
}

Coordinate Piece::getCoordinate(void) const
{
	TRACE("Piece: getCoordinate: ({0}, {1})", position_.x, position_.y);
	return position_;
}
