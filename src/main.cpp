#include "pch.h"
#include "Window.h"
#include "Game.h"

#define TITLE "Chess"
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define IS_FULLSCREEN false

int main(int argc, char* argv[])
{
	Log::init();

	Window window(TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, IS_FULLSCREEN);

	Game game(window.getRenderer());

	game.run();

	return 0;
}
