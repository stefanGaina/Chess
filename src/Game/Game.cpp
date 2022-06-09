#include "pch.h"
#include "Game.h"

Game::Game(void)
	: board_(&drawable_container_), is_running_(true)
{
	TRACE("Game: Is constructoring.");
}

void Game::run(void)
{
	INFO("Game: run: Game started!");
	VERIFY(is_running_ == true, "Game: run: Running flag not set!");

	FrameCap frame;

	while (is_running_)
	{
		frame.start = SDL_GetTicks();

		handleEvents();
		render();

		frame.time = SDL_GetTicks() - frame.start;

		if (frame.delay > frame.time)
		{
			TRACE("Game: run: Timeout for ({0}) ms", frame.delay - frame.time);
			SDL_Delay(frame.delay - frame.time);
		}
	}
}

void Game::handleEvents(void)
{
	TRACE("Game: handleEvents: Handling events.");

	static SDL_Event event;
	static Coordinate click = { 0, 0 };

	if (SDL_WaitEvent(&event) != 0)
	{
		switch (event.type)
		{
			case SDL_MOUSEBUTTONDOWN:
			{
				SDL_GetMouseState(&click.x, &click.y);
				INFO("Game: handleEvents: Mouse was clicked! ({0}, {1})", click.x, click.y);

				board_.update(click);
				break;
			}
			case SDL_QUIT:
			{
				INFO("Game: handleEvents: Close application command!");
				is_running_ = false;
				break;
			}
			default:
			{
				TRACE("Game: handleEvents: Nothing to do.");
			}
		}
	}
}

void Game::render(void)
{
	TRACE("Game: render: Rendering.");

	SDL_RenderClear(Renderer::getRenderer());
	TRACE("Game: render: Renderer was cleared.");

	drawable_container_.draw();

	SDL_RenderPresent(Renderer::getRenderer());
	TRACE("Game: render: Renderer was presented.");
}
