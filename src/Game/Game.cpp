#include "pch.h"
#include "Game.h"

Game::Game(SDL_Renderer* renderer)
	: renderer_(renderer), is_running_(true)
{
	TRACE("Game: Constructor.");
}

void Game::run(void)
{
	FrameCap frame;

	TRACE("Game: run: Game started!");
	VERIFY(is_running_ == true, "Game: run: Running flag not set!");

	while (is_running_)
	{
		frame.start = SDL_GetTicks();

		handleEvents();
		render();

		frame.time = SDL_GetTicks() - frame.start;

		if (frame.delay > frame.time)
		{
			SDL_Delay(frame.delay - frame.time);
		}
	}
}

void Game::handleEvents(void)
{

}

void Game::render(void)
{
	SDL_RenderClear(renderer_);

	SDL_RenderPresent(renderer_);
}
