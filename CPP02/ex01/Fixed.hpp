#pragma once

#include <string>
#include <iostream>
#include <cmath>

class Fixed
{
	private:

		int rawBits;
		static const int numberOfBit = 8;
		std::string binary;

	public:

/* ================= Constructor & Destructor ================= */

		Fixed();
		Fixed(const Fixed& other);
		Fixed(const int number, bool test);
		Fixed(const int number);
		Fixed(float number);
		~Fixed();

/* ================== Operator Overloading ================== */

	Fixed& operator=(const Fixed number);
	// Fixed& operator<<(const Fixed number);

/* ========================= Setter ========================= */

		int getRawBits( void ) const;
		std::string getbinary( void ) const;

/* ========================= Getter ========================= */

		void setRawBits( int const raw );
		void setbinary(std::string &binary );

/* ========================= Else ========================= */
		int	toInt( void ) const;
		float	toFloat( void ) const;

};