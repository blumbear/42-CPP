#include <iostream>
#include <sstream>
#include "Fixed.hpp"
#include "Fixed.h"

int main()
{
	Fixed a(10);
	Fixed b(15);
	Fixed c(89);
	Fixed d(-5);

	std::cout << "a bin = " << a.getbinary() << '\n';
	std::cout << "a intToBin =	" << intToBin(a.getRawBits()) << '\n';
	std::cout << "bin have to be : 01000001001000000" << '\n';
	std::cout << "b bin = " << b.getbinary() << '\n';
	std::cout << "a intToBin =	" << intToBin(b.getRawBits()) << '\n';
	std::cout << "bin have to be : 01000001011100000" << '\n';
	std::cout << "c bin = " << c.getbinary() << '\n';
	std::cout << "a intToBin =	" << intToBin(c.getRawBits()) << '\n';
	std::cout << "bin have to be : 01000010101100100" << '\n';
	std::cout << "d bin = " << d.getbinary() << '\n';
	std::cout << "a intToBin =	" << intToBin(d.getRawBits()) << '\n';
	std::cout << "bin have to be : 11000000101000000" << '\n';
	
	return 0;
}
/*
01000001001000000 have to be
1000010000000010 being
*/

/*int main( void )
{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return 0;
}*/