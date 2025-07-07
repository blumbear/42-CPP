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
		ShrubberyCreationForm tree("tree");
		PresidentialPardonForm president("president");
		RobotomyRequestForm robot("robot");
		std::cout << std::endl;

		Bureaucrat Michel("Michel", 125);
		Bureaucrat Laure("Laure", 1);
		std::cout << std::endl;
		
		std::cout << "---Michel PPF test---" << std::endl;
		Michel.signForm(president);
		Michel.executeForm(president);
		std::cout << president;
		std::cout << std::endl;
		
		std::cout << "---Laure PPF test---" << std::endl;
		Laure.signForm(president);
		Laure.executeForm(president);
		std::cout << std::endl;
		
		std::cout << "---Michel RRF test---" << std::endl;
		Michel.signForm(robot);
		Michel.executeForm(robot);
		std::cout << std::endl;

		std::cout << "---Laure RRF test---" << std::endl;
		Laure.signForm(robot);
		Laure.executeForm(robot);
		Laure.executeForm(robot);
		std::cout << std::endl;
		
		std::cout << "---Michel SCF test---" << std::endl;
		Michel.signForm(tree);
		Michel.executeForm(tree);
		std::cout << std::endl;

		std::cout << "---Laure SCF test---" << std::endl;
		Laure.signForm(tree);
		Laure.executeForm(tree);
		std::cout << std::endl;
		
		std::cout << Michel << std::endl ;
		std::cout << Laure << std::endl ;
		std::cout << tree << std::endl ;
		std::cout << president << std::endl ;
		std::cout << robot << std::endl << std::endl ;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
	}
	return 0;
}