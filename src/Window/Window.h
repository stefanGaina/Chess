#ifndef WINDOW_H_
#define WINDOW_H_

class Window
{
public:
	static void init(const char* const title, Sint32 position_x, Sint32 position_y, Sint32 screen_width, Sint32 screen_height, bool is_fullscreen);
	static void deinit(void);

	static SDL_Window* getWindow(void);

protected:
	Window(void) {}

private:
	static SDL_Window* s_window_;
};

#endif /* WINDOW_H_ */
