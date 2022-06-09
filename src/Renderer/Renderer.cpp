#include "pch.h"
#include "Renderer.h"

SDL_Renderer* Renderer::s_renderer_ = nullptr;

SDL_Renderer* Renderer::getRenderer(void)
{
	TRACE("Renderer: getRenderer: Getting renderer.");
	ASSERT(s_renderer_ != nullptr, "Renderer: getRenderer: Renderer is null!");

	return s_renderer_;
}

void Renderer::setRenderer(SDL_Renderer* renderer)
{
	TRACE("Renderer: setRenderer: Setting renderer.");

	if (s_renderer_ == nullptr && renderer != nullptr)
	{
		INFO("Renderer: setRenderer: Renderer was set!");
		s_renderer_ = renderer;
	}
	else if (renderer == nullptr)
	{
		WARN("Renderer: setRenderer: Renderer was set to null!");
		s_renderer_ = renderer;
	}
	else
	{
		ERROR("Renderer: setRenderer: Renderer is already set!");
	}
}
