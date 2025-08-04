#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat Michel("Michel", 149);
		Bureaucrat Laure("Laure", 1);
		Form Alternance("Alternance", 145, 10);
		Form Stage("Stage", 3, 2);
		std::cout << std::endl;

		Michel.signForm(Alternance);
		std::cout << std::endl;

		Laure.signForm(Stage);
		std::cout << std::endl;

		std::cout << Michel << std::endl;
		std::cout << Laure << std::endl;
		std::cout << Alternance << std::endl;
		std::cout << Stage << std::endl;
		std::cout << std::endl;
	}
	catch (const std::exception& e) {
	  std::cout << e.what();
	}
	return 0;
}
