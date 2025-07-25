#include <string>
#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "The memory address of the string variable	: " << &str << std::endl;
	std::cout << "The memory address held by stringPTR		: " << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF		: " << &stringREF << std::endl;

	std::cout << "---------------------------------" << std::endl;

	std::cout << "The value of the string variable		: " << str << std::endl;
	std::cout << "The value pointed by stringPTR			: " << *stringPTR << std::endl;
	std::cout << "The value pointed by stringREF			: " << stringREF << std::endl;
}