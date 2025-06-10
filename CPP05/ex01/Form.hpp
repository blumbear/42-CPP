#pragma once

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class Form {
	private :
		const std::string _name;
		bool		_signed;
		const int	_signGrade;
		const int	_execGrade;

	public :
/* ================= Exception Handler ================= */

	class GradeTooHighException: public std::exception {
		public :
			const char* what() const throw();
	};
	class GradeTooLowException: public std::exception {
		public :
			const char* what() const throw();
	};

/* ================= Canonical Form ================= */

		Form(const std::string& name = "", const int signGrade = -1, const int execGrade = -1, bool approved = false);
		Form(const Form &other);
		~Form();
		Form &operator=(const Form &other);

/* ==================== Getter ==================== */

		const std::string	getName() const;
		bool	getSigned() const;
		int	getSignGrade() const;
		int	getExecGrade() const;

/* ================ Menmber Function ================ */

		void	beSigned(Bureaucrat& bureaucrat);
};

/* ================ Overload Operator ================ */

std::ostream& operator<<(std::ostream& out, const Form &other);
