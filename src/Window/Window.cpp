#include "pch.h"
#include "Window.h"

Window::Window(const char* title, Uint32 position_x, Uint32 position_y, Uint16 screen_width, Uint16 screen_height, bool is_fullscreen)
	: window_(nullptr), renderer_(nullptr)
{
	Sint32 success = 0;
	Uint32 fullscreen_flag = is_fullscreen ? SDL_WINDOW_FULLSCREEN : 0;

	TRACE("Window: Constructor.");
	VERIFY(title != nullptr,  "Window: Title is null!");
	VERIFY(screen_width  > 0, "Window: Screen width is (0)!");
	VERIFY(screen_height > 0, "Window: Screen height is (0)!");
	VERIFY(position_x == SDL_WINDOWPOS_CENTERED, "Window: Position is not centered! ({0})", position_x);
	VERIFY(position_y == SDL_WINDOWPOS_CENTERED, "Window: Position is not centered! ({0})", position_y);

	window_ = SDL_CreateWindow(title, position_x, position_y, screen_width, screen_height, fullscreen_flag);
	ASSERT(window_ != nullptr, SDL_GetError());
	INFO("Window: Window successfully created!");

	renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	ASSERT(renderer_ != nullptr, SDL_GetError());
	INFO("Window: Renderer successfully created!");

	SDL_SetRenderDrawBlendMode(renderer_, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(renderer_, 0xFF, 0xFF, 0xFF, 0xFF); /* white */

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
}

Window::~Window(void)
{
	SDL_DestroyWindow(window_);
	window_ = nullptr;

	SDL_DestroyRenderer(renderer_);
	renderer_ = nullptr;

	//TTF_Quit();
	//IMG_Quit();
	//Mix_Quit();
	SDL_Quit();
}

SDL_Renderer* Window::getRenderer(void)
{
	return renderer_;
}
