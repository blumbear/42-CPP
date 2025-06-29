#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>
#include <iostream>

int main()
{
	try
	{
		// ShrubberyCreationForm tree("tree");
		PresidentialPardonForm president("president");
		RobotomyRequestForm robot("robot");
		std::cout << std::endl;

		Bureaucrat Michel("Michel", 125);
		Bureaucrat Laure("Laure", 1);
		std::cout << std::endl;
		
		Michel.signForm(president);
		Michel.executeForm(president);
		std::cout << president;
		std::cout << std::endl;
		
		Laure.signForm(president);
		Laure.executeForm(president);
		std::cout << std::endl;
		
		Michel.signForm(robot);
		Michel.executeForm(robot);
		Laure.signForm(robot);
		Laure.executeForm(robot);
		Laure.executeForm(robot);
		std::cout << std::endl;
		
		// Michel.signForm(tree);
		// Michel.executeForm(tree);
		// Laure.executeForm(tree);
		std::cout << std::endl;
		
		std::cout << Michel;
		std::cout << Laure;
		// std::cout << tree;
		std::cout << president;
		std::cout << robot;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
	}
	return 0;
}