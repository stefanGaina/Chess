#ifndef COMPONENT_H_
#define COMPONENT_H_

#include "IDrawable.h"

class Component : public IDrawable
{
public:
	Component(void);
	Component(SDL_Texture* texture , SDL_Rect starting_position);
	Component(const char* file_path, SDL_Rect starting_position);
	virtual ~Component(void);

	void draw(void) const override;

protected:
	SDL_Rect destination_;
	SDL_Texture* texture_;
};

#endif /* COMPONENT_H_ */
