#include "Fixed.h"

int ft_pow(int n, int pow)
{
	if (pow == 0)
		return 1;
	int res = 1;
	while (pow-- > 0)
		res *= n;
	return res;
}

std::string intToBin(int number)
{
	std::string res = "";
	while (number > 0)
	{
		if (number % 2 == 0)
			res.insert(0, "0");
		if (number % 2 == 1)
			res.insert(0, "1");
		number /= 2;
	}
	return res;
}

int binaryToInt(std::string binary)
{
	int res;
	int tmp = binary.size();
	for (int i = 0; binary[i]; i++)
	{
		tmp--;
		if (binary[i] == '1')
			res = res + (ft_pow(2, tmp));
	}
	return res;
}

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

Fixed::Fixed(const int number)
{
	std::string binary = intToBin(number * (((number > 0) * 2) - 1));
	binary.insert(binary.find("1") + 1, ".");
	int exponent = binary.size() - (binary.find(".") + 1);
	int rawbit = 0;
	int biasedExponent = exponent + 127;
	rawbit = (rawbit << 8 | biasedExponent);
	binary.erase(0, binary.find(".") + 1);
	int tmp = (numberOfBit - binary.size());
	rawbit = (rawbit << numberOfBit | binaryToInt(binary) << tmp);
	rawbit = rawbit | ((number < 0) << 16);
	this->binary = intToBin(rawbit);
	if (this->binary.size() < 17)
		this->binary.insert(0, "0");
	this->setRawBits(rawbit);
}

Fixed::Fixed(const int number, bool test)
{
	if (test == false)
		return ;
	std::cout << "number = " << number <<'\n';
	std::cout << INT_CONSTRUCTOR_ANC << '\n';
	std::string binary = intToBin(number * (((number > 0) * 2) - 1));
	binary.insert(binary.find("1") + 1, ".");
	int exponent = binary.size() - (binary.find(".") + 1);
	int rawbit = 0;
	std::cout << "1. bin = " << intToBin(rawbit) << '\n';
	int biasedExponent = exponent + 127;
	std::cout << "biased exponent =" << biasedExponent << '\n';
	rawbit = (rawbit << 8 | biasedExponent);
	std::cout << "2. bin =	 " << intToBin(rawbit) << '\n';
	binary.erase(0, binary.find(".") + 1);
	std::cout << "binary =	 " << binary << '\n';
	int tmp = (numberOfBit - binary.size());
	rawbit = (rawbit << numberOfBit | binaryToInt(binary) << tmp);
	rawbit = rawbit | ((number < 0) << 16);
	this->binary = intToBin(rawbit);
	if (this->binary.size() < 17)
		this->binary.insert(0, "0");
	std::cout << "3. bin =	 " << this->binary << '\n';
	std::cout << "4. final rawbit =" << this->rawBits << '\n';
	std::cout << "size of bin =	 " << this->binary.size() << '\n';
	this->setRawBits(rawbit);
}

Fixed::Fixed(const float number)
{
	std::cout << FLT_CONSTRUCTOR_ANC << '\n';
	this->setRawBits(number);
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

// Fixed& Fixed::operator<<(const Fixed number)
// {
// 	void* number;
// 	return *this;
// }

/* ========================= Setter ========================= */

int Fixed::getRawBits( void ) const
{
	std::cout << GETRAWBITS_ANC << '\n';
	return this->rawBits;
}

std::string Fixed::getbinary( void ) const
{
	std::cout << GETBIN_ANC << '\n';
	return this->binary;
}

/* ========================= Getter ========================= */

void Fixed::setRawBits( int const raw )
{
	this->rawBits = raw;
}

void Fixed::setbinary(std::string &binary)
{
	this->binary = binary;
}

/* ========================= Else ========================= */
int	Fixed::toInt( void ) const
{
	int res = 0;

	return res;
}

float	Fixed::toFloat( void ) const
{
	float res = 0;

	return res;
}
