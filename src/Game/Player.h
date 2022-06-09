#ifndef PLAYER_H_
#define PLAYER_H_

#include "Piece.h"
#include "IObserver.h"

#define TOTAL_PIECES       6
#define TOTAL_PAWNS        8
#define TOTAL_MINOR_PIECES 2

class Player : public IDrawable, public IObserver
{
public:
	Player(void);
	Player(bool is_white);
	~Player(void);

	void draw(void) const override;

	void update(const Coordinate& previous_click, const Coordinate& click) override;

public:
	//

private:
	SDL_Texture* piece_texture_[TOTAL_PIECES];

	Piece pawn_  [TOTAL_PAWNS];
	Piece knight_[TOTAL_MINOR_PIECES];
	Piece bishop_[TOTAL_MINOR_PIECES];
	Piece rook_  [TOTAL_MINOR_PIECES];
	Piece queen_;
	Piece king_;
};

#endif /* PLAYER_H_ */
