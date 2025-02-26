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
	/* ========== Comparison Operator ========== */

		bool operator<(const Fixed &number);
		bool operator<=(const Fixed &number);
		bool operator>(const Fixed &number);
		bool operator>=(const Fixed &number);
		bool operator==(const Fixed &number);
		bool operator!=(const Fixed &number);

	/* ========== Arithmetic Operator ========== */

		float operator+(const Fixed &number);
		float operator-(const Fixed &number);
		float operator*(const Fixed &number);
		float operator/(const Fixed &number);

	/* ========== Increment operator ========== */

		Fixed &operator++();
		Fixed operator++(int);

	/* ========== Decrement Operator ========== */
	
		Fixed &operator--();
		Fixed operator--(int);

/* ========================= Setter ========================= */

		int getRawBits( void ) const;
		std::string getbinary( void ) const;

/* ========================= Getter ========================= */

		void setRawBits( int const raw );
		void setbinary(std::string &binary );

/* ========================= Else ========================= */
		int	toInt( void ) const;
		float	toFloat( void ) const;

		Fixed static &min(Fixed &a, Fixed &b);
		const Fixed static &min(const Fixed &a, const Fixed &b);
		Fixed static &max(Fixed &a, Fixed &b);
		const Fixed static &max(const Fixed &a, const Fixed &b);

};