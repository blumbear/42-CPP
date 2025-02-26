#include "Point.hpp"

float findHigherX(Point const a, Point const b, Point const c)
{
	if (a.getX() > b.getX() && a.getX() > c.getX())
		return a.getX();
	if (b.getX() > a.getX() && b.getX() > c.getX())
		return b.getX();
	if (c.getX() > b.getX() && c.getX() > a.getX())
		return c.getX();
	return (0);
}

float findLowerX(Point const a, Point const b, Point const c)
{
	if (a.getX() < b.getX() && a.getX() < c.getX())
		return a.getX();
	if (b.getX() < a.getX() && b.getX() < c.getX())
		return b.getX();
	if (c.getX() < b.getX() && c.getX() < a.getX())
		return c.getX();
	return (0);
}

float findHigherY(Point const a, Point const b, Point const c)
{
	if (a.getY() > b.getY() && a.getY() > c.getY())
		return a.getY();
	if (b.getY() > a.getY() && b.getY() > c.getY())
		return b.getY();
	if (c.getY() > b.getY() && c.getY() > a.getY())
		return c.getY();
	return (0);
}

float findLowerY(Point const a, Point const b, Point const c)
{
	if (a.getY() < b.getY() && a.getY() < c.getY())
		return a.getY();
	if (b.getY() < a.getY() && b.getY() < c.getY())
		return b.getY();
	if (c.getY() < b.getY() && c.getY() < a.getY())
		return c.getY();
	return (0);
}

bool initialTest(Point const a, Point const b, Point const c, Point const point)
{
	if (a == b && a == c)
		return false;
	else if (a.getX() == b.getX() && a.getX() == c.getX())
		return false;
	else if (a.getY() == b.getY() && a.getY() == c.getY())
		return false;
	else if (point.getX() >= findHigherX(a, b, c) || point.getX() <= findLowerX(a, b, c))
		return false;
	else if (point.getY() >= findHigherY(a, b, c) || point.getY() <= findLowerY(a, b, c))
		return false;
	return true;
}

float	crossProduct(Point a, Point b, Point point)
{
	return (((b.getX() - a.getX()) * (point.getY() - a.getY())) - ((b.getY() - a.getY()) * (point.getX() - a.getX())));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	if (initialTest(a, b, c, point) == false)
		return false;
	
	float crossA = crossProduct(a, b, point);
	float crossB = crossProduct(a, c, point);
	float crossC = crossProduct(c, b, point);

	if (crossA > 0 && crossB > 0 && crossC > 0 )
		return true;
	else if (crossA < 0 && crossB < 0 && crossC < 0 )
		return true;
	else
		return false;
}
