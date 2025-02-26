#include <iostream>
#include <sstream>
#include "Fixed.hpp"
#include "Fixed.h"

std::ostream &operator<<(std::ostream &out, Fixed const &fixed)
{
	out << fixed.toFloat();
	return out;
}

int main( void )
{
	Fixed a;
	Fixed const b( 10 );
	Fixed c( 42.42f );
	Fixed const d( 42.43f );
	Fixed e( d );

	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "e is " << e << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	std::cout << "e is " << e.toInt() << " as integer" << std::endl;

	bool test = a < b;
	std::cout << "a < b = " << test << std::endl;
	test = a <= b;
	std::cout << "a <= b = " << test << std::endl;
	test = a > b;
	std::cout << "a > b = " << test << std::endl;
	test = a >= b;
	std::cout << "a >= b = " << test << std::endl;
	test = a == b;
	std::cout << "a == b = " << test << std::endl;
	test = a != b;
	std::cout << "a != b = " << test << std::endl;
	
	test = e == d;
	std::cout << "e == d = " << test << std::endl;

	Fixed a_bis;
	Fixed b_bis(a - b);
	Fixed c_bis(c / 10);
	Fixed d_bis(a * 2);
	Fixed e_bis(a / 0);
	std::cout << "---------------------\n";
	std::cout << "b is " << b_bis.toFloat() << " as integer" << std::endl;
	std::cout << "c is " << c_bis.toFloat() << " as integer" << std::endl;
	std::cout << "d is " << d_bis.toFloat() << " as integer" << std::endl;
	std::cout << "e is " << e_bis.toFloat() << " as integer" << std::endl;

	std::cout << "---------------------\n";
	std::cout << "a_bis is " << a_bis << " as integer" << std::endl;
	std::cout << "a_bis is " << ++a_bis << " as integer" << std::endl;
	std::cout << "a_bis is " << a_bis << " as integer" << std::endl;
	std::cout << "a_bis is " << a_bis++ << " as integer" << std::endl;
	std::cout << "a_bis is " << a_bis << " as integer" << std::endl;
	
	std::cout << "---------------------\n";
	std::cout << "a_bis is " << a_bis << " as integer" << std::endl;
	std::cout << "a_bis is " << --a_bis << " as integer" << std::endl;
	std::cout << "a_bis is " << a_bis << " as integer" << std::endl;
	std::cout << "a_bis is " << a_bis-- << " as integer" << std::endl;
	std::cout << "a_bis is " << a_bis << " as integer" << std::endl;
	return 0;
}