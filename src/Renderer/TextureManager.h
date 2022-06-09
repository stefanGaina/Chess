#ifndef TEXTURE_MANAGER_H_
#define TEXTURE_MANAGER_H_

#include "Renderer.h"

class TextureManager : public Renderer
{
public:
	static SDL_Texture* load(const char* file_path);
	//static SDL_Texture* createText(TTF_Font* textFont, std::string text, SDL_Color textColor, SDL_Renderer* renderer);
	static void destroy(SDL_Texture*& texture);
	static void draw(SDL_Texture* texture, SDL_Rect destination);

private:
	TextureManager(void) {}
};

#endif /* TEXTURE_MANAGER_H_ */
