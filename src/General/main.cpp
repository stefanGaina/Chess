#include "pch.h"
#include "Window.h"
#include "Game.h"

#define TITLE "Chess"
#define SCREEN_WIDTH 16 * SCALE
#define SCREEN_HEIGHT 9 * SCALE
#define IS_FULLSCREEN false

/* Entry Point: SDL_main */
int main(int argc, char* argv[])
{
	Log::init();
	Window::init(TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, IS_FULLSCREEN);

	Game game;
	game.run();

	Window::deinit();
	INFO("main: Application stopped cleanly!");

	return 0;
}
