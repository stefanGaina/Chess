#ifndef GAME_H_
#define GAME_H_

#include "IRunnable.h"

struct FrameCap
{
	const Uint8 perSecond = 60;
	const Uint8 delay = 1000 / perSecond;

	Uint32 start;
	Uint32 time;
};

class Game : public IRunnable
{
public:
	Game(SDL_Renderer* renderer);

	void run         (void);
	void handleEvents(void);
	void render      (void);
	

private:
	SDL_Renderer* renderer_;
	bool is_running_;
};

#endif /* GAME_H_ */
