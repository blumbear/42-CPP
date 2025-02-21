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

Fixed::Fixed(const int number)
{
	std::cout << INT_CONSTRUCTOR_ANC << std::endl;
	this->fixedPoint = number << this->rawBits;
}

Fixed::Fixed(const float number)
{
	std::cout << FLT_CONSTRUCTOR_ANC << std::endl;
	this->fixedPoint = roundf(number * (1 << this->rawBits));
}

Fixed::~Fixed( void )
{
	std::cout << DESTRUCTOR_ANC << '\n';
}

/* ================== Operator Overloading ================== */

Fixed &Fixed::operator=(const Fixed &number)
{
	std::cout << CPY_ASSIGNMENT_OP_ANC << '\n';
	this->fixedPoint = number.fixedPoint;
	return (*this);
}

std::ostream &operator<<(std::ostream &out, Fixed const &fixed)
{
	out << fixed.toFloat();
	return out;
}

/* ========================= Setter ========================= */

int Fixed::getRawBits( void ) const
{
	std::cout << GETRAWBITS_ANC << '\n';
	return this->fixedPoint;
}

std::string Fixed::getbinary( void ) const
{
	std::cout << GETBIN_ANC << '\n';
	return this->binary;
}

/* ========================= Getter ========================= */

void Fixed::setRawBits( int const raw )
{
	this->fixedPoint = raw;
}

void Fixed::setbinary(std::string &binary)
{
	this->binary = binary;
}

/* ========================= Else ========================= */
int	Fixed::toInt( void ) const
{
	return (this->fixedPoint >> this->rawBits);;
}

float	Fixed::toFloat( void ) const
{
	return (float)(this->fixedPoint) / (1 << this->rawBits);
}
