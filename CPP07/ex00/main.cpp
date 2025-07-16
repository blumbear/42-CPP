#include "whatever.hpp"
#include <iostream>
#include <string>

int main() {
	std::cout << min(8,5) << std::endl;
	std::cout << min(5,8) << std::endl;
	std::cout << min(-25,25) << std::endl;
	std::cout << min(8.5,5.5) << std::endl;
	std::cout << min(8.8f,8.9f) << std::endl << std::endl;

	std::cout << max(8,5) << std::endl;
	std::cout << max(5,8) << std::endl;
	std::cout << max(-25,25) << std::endl;
	std::cout << max(8.5,5.5) << std::endl;
	std::cout << max(8.8f,8.9f) << std::endl << std::endl;

	std::string tmpa = "hello";
	std::string tmpb = "world";
	
	swap(tmpa, tmpb);

	std::cout << tmpa << " " << tmpb << std::endl;

	swap(tmpa, tmpb);
	std::cout << tmpa << " " << tmpb << std::endl;

	return (1);
}