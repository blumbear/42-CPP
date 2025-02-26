#pragma once

#include "Fixed.hpp"

class Point {
	private:
		const Fixed x;
		const Fixed y;

	public:
/* ================= Constructor & Destructor ================= */

		Point();
		Point(const float x, const float y);
		Point(const Point &point);
		~Point();

/* ========================= Setter ========================= */

		void	setX(const float x);
		void	setY(const float y);

/* ========================= Getter ========================= */

		Fixed	getX( void ) const;
		Fixed	getY( void ) const;

/* ================== Operator Overloading ================== */

		Point &operator=(const Point &number) const;
		bool &operator==(const Point &number) const;
};