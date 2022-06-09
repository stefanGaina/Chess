#include "pch.h"
#include "DrawableContainer.h"

DrawableContainer::DrawableContainer(void)
	: table_("assets/Images/Table.png", { 0         , 0        , 16 * SCALE, 9 * SCALE }),
	  board_("assets/Images/Board.png", { 4 * SCALE , SCALE / 2, 8  * SCALE, 8 * SCALE }),
	  white_(true), black_()
{
	TRACE("DrawableContainer: Is constructing.");
}

void DrawableContainer::draw(void) const
{
	TRACE("DrawableContainer: draw: Is drawing.");

	table_.draw();
	board_.draw();
	white_.draw();
	black_.draw();
}

void DrawableContainer::update(const Coordinate& previous_click, const Coordinate& click)
{
	TRACE("DrawableContainer: update: Is updating.");

	white_.update(previous_click, click);
	black_.update(previous_click, click);
}
