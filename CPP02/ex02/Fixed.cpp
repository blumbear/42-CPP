#include "Fixed.h"

/* ================= Constructor & Destructor ================= */

Fixed::Fixed( void ) : fixedPoint(0)
{
	std::cout << DFLT_CONSTRUCTOR_ANC << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << CPY_CONSTRUCTOR_ANC << std::endl;
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
	std::cout << DESTRUCTOR_ANC << std::endl;
}

/* ================== Operator Overloading ================== */

Fixed &Fixed::operator=(const Fixed &number)
{
	std::cout << CPY_ASSIGNMENT_OP_ANC << std::endl;
	this->fixedPoint = number.fixedPoint;
	return (*this);
}
		/* ========== Comparison Operator ========== */

bool Fixed::operator<(const Fixed &number)
{
	return (this->toFloat() < number.toFloat());
}

bool Fixed::operator<=(const Fixed &number)
{
	return (this->toFloat() <= number.toFloat());
}

bool Fixed::operator>(const Fixed &number)
{
	return (this->toFloat() > number.toFloat());
}

bool Fixed::operator>=(const Fixed &number)
{
	return (this->toFloat() >= number.toFloat());
}

bool Fixed::operator==(const Fixed &number)
{
	return (this->toFloat() == number.toFloat());
}

bool Fixed::operator!=(const Fixed &number)
{
	return (this->toFloat() != number.toFloat());
}

		/* ========== Arithmetic Operator ========== */

float Fixed::operator+(const Fixed &number)
{
	return (this->toFloat() + number.toFloat());
}

float Fixed::operator-(const Fixed &number)
{
	return (this->toFloat() - number.toFloat());
}

float Fixed::operator*(const Fixed &number)
{
	return (this->toFloat() * number.toFloat());
}

float Fixed::operator/(const Fixed &number)
{
	if (this->toInt() == 0 || number.toInt() == 0)
		return (this->toFloat());
	return (this->toFloat() / number.toFloat());
}

		/* ========== Increment operator ========== */

Fixed &Fixed::operator++()
{
	this->fixedPoint++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	fixedPoint++;
	return (temp);
}

		/* ========== Decrement Operator ========== */
	
Fixed &Fixed::operator--()
{
	this->fixedPoint--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	fixedPoint--;
	return (temp);
}

/* ========================= Setter ========================= */

int Fixed::getRawBits( void ) const
{
	std::cout << GETRAWBITS_ANC << std::endl;
	return this->fixedPoint;
}

std::string Fixed::getbinary( void ) const
{
	std::cout << GETBIN_ANC << std::endl;
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

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a.toFloat() > b.toFloat())
		return (b);
	return (a);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() > b.toFloat())
		return (b);
	return (a);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a.toFloat() > b.toFloat())
		return (a);
	return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() > b.toFloat())
		return (a);
	return (b);
}

