#pragma once

#include <string>
#include <iostream>
#include <cmath>

class Fixed
{
	private:

		int fixedPoint;
		static const int rawBits = 8;
		std::string binary;

	public:

/* ================= Constructor & Destructor ================= */

		Fixed();
		Fixed(const Fixed& other);
		Fixed(const float number);
		Fixed(const int number);
		~Fixed();

/* ================== Operator Overloading ================== */

	Fixed &operator=(const Fixed &number);

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