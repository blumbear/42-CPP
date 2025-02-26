#include "Point.hpp"

/* ================= Constructor & Destructor ================= */

Point::Point()
{
	this->x = Fixed(0);
	this->y = Fixed(0);
}

Point::Point(float x, float y)
{
	this->x = Fixed(x);
	this->y = Fixed(y);
}

Point::Point(const Point &point)
{
	*this = point;
}

~Point::Point() {}

/* ========================= Setter ========================= */

void	Point::setX(float x)
{
	this->x = Fixed(x);
}

void	Point::setY(float y)
{
	this->y = Fixed(y);
}

/* ========================= Getter ========================= */

Fixed	Point::getX( void ) const
{
	return (this->x);
}

Fixed	Point::getY( void ) const 
{
	return (this->y);
}

/* ================== Operator Overloading ================== */

Point &Point::operator=(const Point &number) const 
{
	this->x = number->getX();
	this->y = number->getY();
	return *this;
}

bool &Point::operator==(const Point &number) const
{
	return (this->x == number.getX() && this->y == number.getY());
}