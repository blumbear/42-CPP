#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat bob = Bureaucrat("bob", 150);
		Bureaucrat michel = Bureaucrat("michel", 1);
		std::cout << std::endl;
		std::cout << bob << std::endl << michel << std::endl << std::endl;
		bob.incrementGrade();
		std::cout << bob << std::endl << michel << std::endl << std::endl;
		bob.incrementGrade();
		std::cout << bob << std::endl << michel << std::endl << std::endl;
		michel.decrementGrade();
		std::cout << bob << std::endl << michel << std::endl << std::endl;
		bob = michel;
		std::cout << bob << std::endl << michel << std::endl << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
		return (0);
	}
	return (0);
}