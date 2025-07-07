#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>
#include <iostream>

int main()
{
	Intern intern;
	AForm *form;
	Bureaucrat signer("Jean-Michel", 1); // grade suffisant pour tout

	struct Test {
		const char *nameForm;
		const char *target;
	};

	const Test tabTest[] = {
		{ "shrubbery creation", "bonjour_a_tous" },
		{ "robotomy request", "Bender" },
		{ "presidential pardon", "Zaphod" },
		{ "invalid form", "Problems" } // erreur ici
	};

	for (int i = 0; i < 4; i++) {
		std::cout << "\nTrying to create: " << tabTest[i].nameForm
				<< " for " << tabTest[i].target << std::endl;

		form = intern.makeForm(tabTest[i].nameForm, tabTest[i].target);

		if (form) {
			std::cout << "Form " << form->getName() << " successfully created\n";

			try {
				signer.signForm(*form);
				signer.executeForm(*form);
			} catch (const std::exception &e) {
				std::cerr << "Error during form handling: " << e.what() << std::endl;
			}

			delete form;
		} else {
			std::cout << "Failed to create form: " << tabTest[i].nameForm << "\n";
		}
	}
	return 0;
}