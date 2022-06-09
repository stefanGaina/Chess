#ifndef IOBSERVER_H_
#define IOBSERVER_H_

class IObserver
{
public:
	virtual void update(const Coordinate& previous_click, const Coordinate& click) = 0;
};

#endif /* IOBSERVER_H_ */
