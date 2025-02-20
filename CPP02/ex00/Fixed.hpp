#pragma once

#include <string>
#include <iostream>

class Fixed
{
	private:

		int rawBits;
		static const int numberOfBit = 8;

	public:

/* ================= Constructor & Destructor ================= */

		Fixed();
		Fixed(const Fixed& other);
		~Fixed();

/* ================== Operator Overloading ================== */

	Fixed& operator=(const Fixed number);

/* ========================= Setter ========================= */

		int getRawBits( void ) const;

/* ========================= Getter ========================= */

		void setRawBits( int const raw );
};
