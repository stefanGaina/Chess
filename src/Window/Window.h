#ifndef WINDOW_H_
#define WINDOW_H_

class Window
{
public:
	Window(const char* title, Uint32 position_x, Uint32 position_y, Uint16 screen_width, Uint16 screen_height, bool is_fullscreen);
	~Window(void);

	SDL_Renderer* getRenderer(void);

private:
	SDL_Window* window_;
	SDL_Renderer* renderer_;
};

#endif /* WINDOW_H_ */
