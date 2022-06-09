#ifndef GAME_H_
#define GAME_H_

#include "IRunnable.h"
#include "Board.h"
#include "DrawableContainer.h"

class Game : public IRunnable
{
public:
	Game(void);

	void run(void) override;

private:
	void handleEvents(void);
	void render      (void);

private:
	bool is_running_;

	DrawableContainer drawable_container_;
	Board board_;
};

#endif /* GAME_H_ */
