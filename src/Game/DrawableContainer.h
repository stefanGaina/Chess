#ifndef BACKGROUND_H_
#define BACKGROUND_H_

#include "IObserver.h"
#include "Component.h"
#include "Player.h"

class DrawableContainer : public IDrawable, public IObserver
{
public:
	DrawableContainer(void);

	void draw(void) const override;
	
	void update(const Coordinate& previous_click, const Coordinate& click) override;

private:
	Component table_;
	Component board_;
	Player white_, black_;
};

#endif /* BACKGROUND_H_ */
