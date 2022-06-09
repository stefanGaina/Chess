#ifndef PIECE_H_
#define PIECE_H_

#include "Component.h"

class Piece : public Component
{
public:
	Piece(SDL_Texture* texture, SDL_Rect starting_position);

	void update(Coordinate click);

	Coordinate getCoordinate(void) const;

private:
	Coordinate position_;
};

#endif /* PIECE_H_ */
