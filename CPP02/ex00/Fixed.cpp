#include "Fixed.h"

/* ================= Constructor & Destructor ================= */

Fixed::Fixed( void ) : rawBits(0)
{
	std::cout << DFLT_CONSTRUCTOR_ANC << '\n';
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << CPY_CONSTRUCTOR_ANC << '\n';
	this->rawBits = other.getRawBits();
}

Fixed::~Fixed( void )
{
	std::cout << DESTRUCTOR_ANC << '\n';
}

/* ================== Operator Overloading ================== */

Fixed& Fixed::operator=(const Fixed number)
{
	std::cout << CPY_ASSIGNMENT_OP_ANC << '\n';
	this->rawBits = number.getRawBits();
	return (*this);
}

/* ========================= Setter ========================= */

int Fixed::getRawBits( void ) const
{
	std::cout << GETRAWBITS_ANC << '\n';
	return this->rawBits;
}

/* ========================= Getter ========================= */

void Fixed::setRawBits( int const raw )
{
	this->rawBits = raw;
}