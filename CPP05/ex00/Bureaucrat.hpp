#pragma once

#include <string>
#include <iostream>

class Bureaucrat {
	private :
		const std::string name;
		int grade;
	public :

/* ============ Constructor & Destructor ============ */

		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat();

/* ===================== Getter ===================== */

		std::string	getName();
		int			getGrade();

/* =============== Overload Operator =============== */

		Fixed& Fixed::operator=(const Fixed &number);

};