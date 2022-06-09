#include "pch.h"
#include "Component.h"

Component::Component(SDL_Texture* texture, SDL_Rect starting_position)
	: texture_(texture), destination_(starting_position)
{
	TRACE("Component: Is constructing from texture.");
	VERIFY(texture != nullptr, "Component: Texture argument is null!");
}

Component::Component(const char* file_path, SDL_Rect starting_position)
	: texture_(TextureManager::load(file_path)),
	  destination_(starting_position)
{
	TRACE("Component: Is constructing from file path.");
	VERIFY(texture_ != nullptr, "Component: Texture is null!");
}

Component::~Component(void)
{
	TRACE("Component: Is deconstructing.");
	TextureManager::destroy(texture_);
}

void Component::draw(void) const
{
	TRACE("Component: draw: Is drawing.");
	TextureManager::draw(texture_, destination_);
}
