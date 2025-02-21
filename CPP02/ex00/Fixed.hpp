#pragma once

#include <string>
#include <iostream>

class Fixed
{
	private:

		int fixedPoint;
		static const int rawBits = 8;

	public:

/* ================= Constructor & Destructor ================= */

		Fixed();
		Fixed(const Fixed& other);
		~Fixed();

/* ================== Operator Overloading ================== */

	Fixed& operator=(const Fixed &number);

/* ========================= Setter ========================= */

		int getRawBits( void ) const;

/* ========================= Getter ========================= */

		void setRawBits( int const raw );
};
