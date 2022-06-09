#ifndef TYPES_H_
#define TYPES_H_

struct Coordinate
{
	Coordinate(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	Sint32 x, y;
};

struct FrameCap
{
	static const Uint16 per_second = 60;
	static const Uint16 delay = 1000 / per_second;

	Uint32 start;
	Uint32 time;
};

#endif /* TYPES_H_ */
