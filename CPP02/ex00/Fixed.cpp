#include "Fixed.h"

/* ================= Constructor & Destructor ================= */

Fixed::Fixed( void ) : fixedPoint(0)
{
	std::cout << DFLT_CONSTRUCTOR_ANC << '\n';
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << CPY_CONSTRUCTOR_ANC << '\n';
	*this = other;
}

Fixed::~Fixed( void )
{
	std::cout << DESTRUCTOR_ANC << '\n';
}

/* ================== Operator Overloading ================== */

Fixed& Fixed::operator=(const Fixed &number)
{
	std::cout << CPY_ASSIGNMENT_OP_ANC << '\n';
	this->fixedPoint = number.getRawBits();
	return (*this);
}

/* ========================= Setter ========================= */

int Fixed::getRawBits( void ) const
{
	std::cout << GETRAWBITS_ANC << '\n';
	return this->fixedPoint;
}

/* ========================= Getter ========================= */

void Fixed::setRawBits( int const raw )
{
	this->fixedPoint = raw;
}