#include "pch.h"
#include "Window.h"

SDL_Window* Window::s_window_ = nullptr;

void Window::init(const char* const title, Sint32 position_x, Sint32 position_y, Sint32 screen_width, Sint32 screen_height, bool is_fullscreen)
{
	TRACE("Window: init: Window is initializing.");

	VERIFY(title != nullptr, "Window: Title is null!");
	VERIFY(screen_width > 0, "Window: Screen width is (0)!");
	VERIFY(screen_height > 0, "Window: Screen height is (0)!");
	VERIFY(position_x == SDL_WINDOWPOS_CENTERED, "Window: Position is not centered! ({0})", position_x);
	VERIFY(position_y == SDL_WINDOWPOS_CENTERED, "Window: Position is not centered! ({0})", position_y);

	Sint32 success = 0;
	Uint32 fullscreen_flag = is_fullscreen ? SDL_WINDOW_FULLSCREEN : 0;
	SDL_Renderer* renderer = nullptr;

	s_window_ = SDL_CreateWindow(title, position_x, position_y, screen_width, screen_height, fullscreen_flag);
	ASSERT(s_window_ != nullptr, SDL_GetError());
	INFO("Window: Window successfully created!");

	renderer = SDL_CreateRenderer(s_window_, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	ASSERT(renderer != nullptr, SDL_GetError());
	INFO("Window: Renderer successfully created!");

	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF); /* white */

	//SDL_ShowCursor(SDL_DISABLE);

	success = SDL_Init(SDL_INIT_EVERYTHING);
	ASSERT(success >= 0, SDL_GetError());
	INFO("Window: SDL successfully initialized!");

	/*if (TTF_Init() == -1)
	{
		ERROR(SDL_GetError());
	}
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		ERROR(SDL_GetError());
	}*/

	TextureManager::setRenderer(renderer);
}

void Window::deinit(void)
{
	TRACE("Window: deinit: Window is deinitializing.");

	SDL_DestroyRenderer(TextureManager::getRenderer());
	INFO("Window: deinit: Renderer was destroyed!");
	TextureManager::setRenderer(nullptr);

	SDL_DestroyWindow(s_window_);
	s_window_ = nullptr;
	INFO("Window: deinit: Window was destroyed!");

	//TTF_Quit();
	//IMG_Quit();
	//Mix_Quit();
	SDL_Quit();
}

SDL_Window* Window::getWindow(void)
{
	TRACE("Window: getWindow: Getting window.");
	return s_window_;
}
