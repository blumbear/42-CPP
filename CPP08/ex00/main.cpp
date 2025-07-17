#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <ctime>

int main() {
	std::vector<int> v(1000);

	std::srand(std::time(0));
	std::generate(v.begin(), v.end(), std::rand);

	try {
		std::vector<int>::const_iterator it = easyfind(v, v[5]);
		std::cout << "Element found: " << *it << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		std::vector<int>::const_iterator it = easyfind(v, 0);
		std::cout << "Element found: " << *it << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}