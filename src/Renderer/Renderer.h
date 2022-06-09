#ifndef RENDERER_H_
#define RENDERER_H_

class Renderer
{
public:
	static SDL_Renderer* getRenderer(void);
	static void setRenderer(SDL_Renderer* renderer);

protected:
	Renderer(void) {}

protected:
	static SDL_Renderer* s_renderer_;
};

#endif /* RENDERER_H_ */
