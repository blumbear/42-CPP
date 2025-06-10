#pragma once

#include <iostream>
#include <exception>

class Bureaucrat {
	private :
		const std::string _name;
		int _grade;
	public:
		class GradeTooHighException: public std::exception {
			public :
				const char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public :
				const char* what() const throw();
		};

/* ================== Constructor ================== */

		Bureaucrat(const std::string name, int grade);

/* ================= Canonical Form ================= */

		Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat();
		Bureaucrat &operator=(const Bureaucrat &other);

/* ===================== Getter ===================== */

		int	getGrade() const;
		std::string getName() const;

/* ================= Member function ================= */

		void incrementGrade();
		void decrementGrade();

/* ================ Overload Operator ================ */

};

std::ostream& operator<<(std::ostream& out, const Bureaucrat &other);