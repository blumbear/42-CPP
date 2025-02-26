#include <iostream>
#include <sstream>
#include "Point.hpp"
#include "bsp.cpp"

int main ( void )
{
	Point a(10.0f, 0.2f);
	Point b(0.2f, 10.0f);
	Point c(5.5f, 5.5f);
	Point point(5.9f, 6.3f);

	if (bsp(a, b, c, point))
		std::cout << "point is in ABC triangle" << std::endl;
	else 
		std::cout << "point isn't in ABC triangle" << std::endl;
}