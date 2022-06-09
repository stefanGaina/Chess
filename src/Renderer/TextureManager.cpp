#include "pch.h"
#include "TextureManager.h"

SDL_Texture* TextureManager::load(const char* file_path)
{
	TRACE("TextureManager: load: Loading texture.");

	SDL_Surface* temporarySurface = IMG_Load(file_path);

	VERIFY(temporarySurface != nullptr, "TextureManager: load: Failed to load image! ({0})", file_path);
	ASSERT(s_renderer_ != nullptr, "TextureManager: load: Renderer is null!");

	SDL_Texture* texture = SDL_CreateTextureFromSurface(s_renderer_, temporarySurface);
	SDL_FreeSurface(temporarySurface);

	return texture;
}

/*SDL_Texture* TextureManager::createText(TTF_Font* font, std::string text, SDL_Color color, SDL_Renderer* renderer)
{
#ifdef DEBUG
	if (font == nullptr)
	{
		ERROR("Invalid font");
	}
#endif
	SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.c_str(), color);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_FreeSurface(textSurface);

	return texture;
}*/

void TextureManager::destroy(SDL_Texture*& texture)
{
	TRACE("TextureManager: destroy: Destroying texture.");
	VERIFY(texture != nullptr, "TextureManager: destroy: Destroying null texture!");

	SDL_DestroyTexture(texture);
	texture = nullptr;
}

void TextureManager::draw(SDL_Texture* texture, SDL_Rect destination)
{
	TRACE("TextureManager: draw: Drawing texture.");
	VERIFY(texture != nullptr, "TextureManager: draw: Drawing null texture!");
	ASSERT(s_renderer_ != nullptr, "TextureManager: draw: Renderer is null!");

	SDL_RenderCopy(s_renderer_, texture, nullptr, &destination);
}
